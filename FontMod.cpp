#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <windows.h>
#include <cstdint>
#include <unordered_map>
#include <string>
#include <string_view>
#include <fstream>
#include <filesystem>
namespace fs = std::filesystem;

#include "yaml-cpp/yaml.h"

#include "winmm.hpp"
#include "Util.hpp"
#include "DefConfigFile.hpp"

#define CONFIG_FILE L"FontMod.yaml"
#define LOG_FILE L"FontMod.log"

#pragma pack(push, 1)
struct jmp
{
	uint8_t opcode;
	size_t address;
};
#pragma pack(pop)

size_t addrCreateFontIndirectW = 0;
size_t addrGetStockObject = 0;

// overrideflags
#define	_NONE 0
#define	_HEIGHT 1 << 1
#define	_WIDTH 1 << 2
#define	_WEIGHT 1 << 3
#define	_ITALIC 1 << 4
#define	_UNDERLINE 1 << 5
#define	_STRIKEOUT 1 << 6
#define	_CHARSET 1 << 7
#define	_OUTPRECISION 1 << 8
#define	_CLIPPRECISION 1 << 9
#define	_QUALITY 1 << 10
#define	_PITCHANDFAMILY 1 << 11

struct font
{
	std::wstring replace;
	uint32_t overrideFlags;
	long height;
	long width;
	long weight;
	bool italic;
	bool underLine;
	bool strikeOut;
	BYTE charSet;
	BYTE outPrecision;
	BYTE clipPrecision;
	BYTE quality;
	BYTE pitchAndFamily;
};

enum GSOFontMode {
	DISABLED,
	USE_NCM_FONT, // Use default font from SystemParametersInfo SPI_GETNONCLIENTMETRICS
	USE_USER_FONT // Use user defined font
};

std::unordered_map<std::wstring, font> fontsMap;
FILE *logFile = nullptr;
HFONT newGSOFont = nullptr;

__declspec(naked) HFONT WINAPI CallOrigCreateFontIndirectW(const LOGFONTW* lplf)
{
	_asm
	{
		mov edi, edi
		push ebp
		mov ebp, esp
		jmp addrCreateFontIndirectW
	}
}

__declspec(naked) HGDIOBJ WINAPI CallOrigGetStockObject(int i)
{
	_asm
	{
		mov edi, edi
		push ebp
		mov ebp, esp
		jmp addrGetStockObject
	}
}

HFONT WINAPI MyCreateFontIndirectW(LOGFONTW* lplf)
{
	if (logFile)
	{
		std::string name;
		if (Utf16ToUtf8(lplf->lfFaceName, name))
		{
#define bool_string(b) b != FALSE ? "true" : "false"
			fprintf_s(logFile,
				"[CreateFont] name = \"%s\", height = %d, "
				"width = %d, escapement = %d, "
				"orientation = %d, weight = %d, "
				"italic = %s, underline = %s, "
				"strikeout = %s, charset = %d, "
				"outprecision = %d, clipprecision = %d, "
				"quality = %d, pitchandfamily = %d\n",
				name.c_str(), lplf->lfHeight,
				lplf->lfWidth, lplf->lfEscapement,
				lplf->lfOrientation, lplf->lfWeight,
				bool_string(lplf->lfItalic), bool_string(lplf->lfUnderline),
				bool_string(lplf->lfStrikeOut), lplf->lfCharSet,
				lplf->lfOutPrecision, lplf->lfClipPrecision,
				lplf->lfQuality, lplf->lfPitchAndFamily);
		}
	}

	auto it = fontsMap.find(lplf->lfFaceName);
	if (it != fontsMap.end())
	{
		size_t len = it->second.replace._Copy_s(lplf->lfFaceName, LF_FACESIZE, LF_FACESIZE);
		lplf->lfFaceName[len] = L'\0';

		if ((it->second.overrideFlags & _HEIGHT) == _HEIGHT)
			lplf->lfHeight = it->second.height;
		if ((it->second.overrideFlags & _WIDTH) == _WIDTH)
			lplf->lfWidth = it->second.width;
		if ((it->second.overrideFlags & _WEIGHT) == _WEIGHT)
			lplf->lfWeight = it->second.weight;
		if ((it->second.overrideFlags & _ITALIC) == _ITALIC)
			lplf->lfItalic = it->second.italic;
		if ((it->second.overrideFlags & _UNDERLINE) == _UNDERLINE)
			lplf->lfUnderline = it->second.underLine;
		if ((it->second.overrideFlags & _STRIKEOUT) == _STRIKEOUT)
			lplf->lfStrikeOut = it->second.strikeOut;
		if ((it->second.overrideFlags & _CHARSET) == _CHARSET)
			lplf->lfCharSet = it->second.charSet;
		if ((it->second.overrideFlags & _OUTPRECISION) == _OUTPRECISION)
			lplf->lfOutPrecision = it->second.outPrecision;
		if ((it->second.overrideFlags & _CLIPPRECISION) == _CLIPPRECISION)
			lplf->lfClipPrecision = it->second.clipPrecision;
		if ((it->second.overrideFlags & _QUALITY) == _QUALITY)
			lplf->lfQuality = it->second.quality;
		if ((it->second.overrideFlags & _PITCHANDFAMILY) == _PITCHANDFAMILY)
			lplf->lfPitchAndFamily = it->second.pitchAndFamily;
	}
	return CallOrigCreateFontIndirectW(lplf);
}

HGDIOBJ WINAPI MyGetStockObject(int i)
{
	switch (i)
	{
	case OEM_FIXED_FONT:
	case ANSI_FIXED_FONT:
	case ANSI_VAR_FONT:
	case SYSTEM_FONT:
	case DEVICE_DEFAULT_FONT:
	case SYSTEM_FIXED_FONT:
		return newGSOFont;
	}
	return CallOrigGetStockObject(i);
}

bool LoadSettings(HMODULE hModule, const fs::path& fileName, wchar_t* errMsg, GSOFontMode& fixGSOFont, LOGFONT& userGSOFont, bool& debug)
{
	bool ret = false;
	std::ifstream fin(fileName);
	if (fin)
	{
		do {
			YAML::Node config;
			try
			{
				config = YAML::Load(fin);
			}
			catch (const std::exception& e)
			{
				swprintf(errMsg, 512, L"YAML::Load error.\n%hs", e.what());
				break;
			}

			if (!config.IsMap())
			{
				swprintf(errMsg, 512, L"Root node is not a map.");
				break;
			}

			if (auto node = FindNode(config, "fonts"); node && node.IsMap())
			{
				for (const auto& i : node)
				{
					if (i.first.IsScalar() && i.second.IsMap())
					{
						YAML::Node replace;
						if (auto r = FindNode(i.second, "replace"); r && r.IsScalar())
						{
							replace = r;
						}
						else
						{
							replace = FindNode(i.second, "name");
						}
						if (replace && replace.IsScalar())
						{
							font fontInfo;
							Utf8ToUtf16(replace.as<std::string>(), fontInfo.replace);
							fontInfo.overrideFlags = _NONE;

							if (auto node = FindNode(i.second, "size"); node && node.IsScalar())
							{
								if (stol(node.as<std::string>(), fontInfo.height))
									fontInfo.overrideFlags |= _HEIGHT;
							}

							if (auto node = FindNode(i.second, "width"); node && node.IsScalar())
							{
								if (stol(node.as<std::string>(), fontInfo.width))
									fontInfo.overrideFlags |= _WIDTH;
							}

							if (auto node = FindNode(i.second, "weight"); node && node.IsScalar())
							{
								if (stol(node.as<std::string>(), fontInfo.weight))
									fontInfo.overrideFlags |= _WEIGHT;
							}

							if (auto node = FindNode(i.second, "italic"); node && node.IsScalar())
							{
								fontInfo.overrideFlags |= _ITALIC;
								fontInfo.italic = node.as<bool>();
							}

							if (auto node = FindNode(i.second, "underLine"); node && node.IsScalar())
							{
								fontInfo.overrideFlags |= _UNDERLINE;
								fontInfo.underLine = node.as<bool>();
							}

							if (auto node = FindNode(i.second, "strikeOut"); node && node.IsScalar())
							{
								fontInfo.overrideFlags |= _STRIKEOUT;
								fontInfo.strikeOut = node.as<bool>();
							}

							if (auto node = FindNode(i.second, "charSet"); node && node.IsScalar())
							{
								unsigned long out;
								if (stoul(node.as<std::string>(), out))
								{
									fontInfo.overrideFlags |= _CHARSET;
									fontInfo.charSet = static_cast<BYTE>(out);
								}
							}

							if (auto node = FindNode(i.second, "outPrecision"); node && node.IsScalar())
							{
								unsigned long out;
								if (stoul(node.as<std::string>(), out))
								{
									fontInfo.overrideFlags |= _OUTPRECISION;
									fontInfo.outPrecision = static_cast<BYTE>(out);
								}
							}

							if (auto node = FindNode(i.second, "clipPrecision"); node && node.IsScalar())
							{
								unsigned long out;
								if (stoul(node.as<std::string>(), out))
								{
									fontInfo.overrideFlags |= _CLIPPRECISION;
									fontInfo.clipPrecision = static_cast<BYTE>(out);
								}
							}

							if (auto node = FindNode(i.second, "quality"); node && node.IsScalar())
							{
								unsigned long out;
								if (stoul(node.as<std::string>(), out))
								{
									fontInfo.overrideFlags |= _QUALITY;
									fontInfo.quality = static_cast<BYTE>(out);
								}
							}

							if (auto node = FindNode(i.second, "pitchAndFamily"); node && node.IsScalar())
							{
								unsigned long out;
								if (stoul(node.as<std::string>(), out))
								{
									fontInfo.overrideFlags |= _PITCHANDFAMILY;
									fontInfo.pitchAndFamily = static_cast<BYTE>(out);
								}
							}

							std::wstring find;
							Utf8ToUtf16(i.first.as<std::string>(), find);
							fontsMap[find] = fontInfo;
						}
					}
				}
			}

			if (auto node = FindNode(config, "fixGSOFont"); node)
			{
				if (node.IsScalar())
				{
					if (node.as<bool>())
						fixGSOFont = USE_NCM_FONT;
				}
				else if (node.IsMap())
				{
					YAML::Node name;
					if (auto r = FindNode(node, "replace"); r && r.IsScalar())
					{
						name = r;
					}
					else
					{
						name = FindNode(node, "name");
					}
					if (name && name.IsScalar())
					{
						fixGSOFont = USE_USER_FONT;

						std::wstring faceName;
						Utf8ToUtf16(name.as<std::string>(), faceName);
						memcpy_s(userGSOFont.lfFaceName, sizeof(userGSOFont.lfFaceName), faceName.c_str(), faceName.size() * sizeof(decltype(faceName)::value_type));

						if (auto n = FindNode(node, "size"); n && n.IsScalar())
						{
							stol(n.as<std::string>(), userGSOFont.lfHeight);
						}

						if (auto n = FindNode(node, "width"); n && n.IsScalar())
						{
							stol(n.as<std::string>(), userGSOFont.lfWidth);
						}

						if (auto n = FindNode(node, "weight"); n && n.IsScalar())
						{
							stol(n.as<std::string>(), userGSOFont.lfWeight);
						}

						if (auto n = FindNode(node, "italic"); n && n.IsScalar())
						{
							userGSOFont.lfItalic = n.as<bool>();
						}

						if (auto n = FindNode(node, "underLine"); n && n.IsScalar())
						{
							userGSOFont.lfUnderline = n.as<bool>();
						}

						if (auto n = FindNode(node, "strikeOut"); n && n.IsScalar())
						{
							userGSOFont.lfStrikeOut = n.as<bool>();
						}

						if (auto n = FindNode(node, "charSet"); n && n.IsScalar())
						{
							unsigned long out;
							stoul(n.as<std::string>(), out);
							userGSOFont.lfCharSet = static_cast<BYTE>(out);
						}

						if (auto n = FindNode(node, "outPrecision"); n && n.IsScalar())
						{
							unsigned long out;
							stoul(n.as<std::string>(), out);
							userGSOFont.lfOutPrecision = static_cast<BYTE>(out);
						}

						if (auto n = FindNode(node, "clipPrecision"); n && n.IsScalar())
						{
							unsigned long out;
							stoul(n.as<std::string>(), out);
							userGSOFont.lfClipPrecision = static_cast<BYTE>(out);
						}

						if (auto n = FindNode(node, "quality"); n && n.IsScalar())
						{
							unsigned long out;
							stoul(n.as<std::string>(), out);
							userGSOFont.lfQuality = static_cast<BYTE>(out);
						}

						if (auto n = FindNode(node, "pitchAndFamily"); n && n.IsScalar())
						{
							unsigned long out;
							stoul(n.as<std::string>(), out);
							userGSOFont.lfPitchAndFamily = static_cast<BYTE>(out);
						}
					}
				}
			}

			if (auto node = FindNode(config, "debug"); node && node.IsScalar())
				debug = node.as<bool>();

			ret = true;
		} while (0);
	}
	else
	{
#pragma warning(push)
#pragma warning(disable: 4996) // 'strerror': This function or variable may be unsafe.
		swprintf(errMsg, 512, L"Can not open " CONFIG_FILE ".\n%hs", strerror(errno));
#pragma warning(pop)
	}
	return ret;
}

void LoadUserFonts(const fs::path& path)
{
	try
	{
		auto fontsPath = path / L"fonts";
		if (fs::is_directory(fontsPath))
		{
			for (auto& f : fs::directory_iterator(fontsPath))
			{
				if (f.is_directory()) continue;
				int ret = AddFontResourceExW(f.path().c_str(), FR_PRIVATE, 0);
				if (logFile)
				{
					fprintf_s(logFile, "[LoadUserFonts] filename = \"%s\", ret = %d, lasterror = %d\n", f.path().filename().u8string().c_str(), ret, GetLastError());
				}
			}
		}
	}
	catch (const std::exception& e)
	{
		if (logFile)
		{
			fprintf_s(logFile, "[LoadUserFonts] exception: \"%s\"\n", e.what());
		}
	}
}

void InlineHook(void* func, void* hookFunc, size_t* origAddr)
{
	DWORD oldProtect;
	if (VirtualProtect(func, 5, PAGE_EXECUTE_READWRITE, &oldProtect))
	{
		jmp* hook = reinterpret_cast<jmp*>(func);
		hook->opcode = 0xE9; // jmp
		hook->address = (size_t)hookFunc - (size_t)func - 5;
		*origAddr = (size_t)func + 5;
		VirtualProtect(func, 5, oldProtect, &oldProtect);
	}
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
	if (ul_reason_for_call == DLL_PROCESS_ATTACH)
	{
		DisableThreadLibraryCalls(hModule);

#if _DEBUG
		MessageBoxW(0, L"DLL_PROCESS_ATTACH", L"", 0);
#endif

		if (!LoadDLL())
			return FALSE;

		auto path = GetModuleFsPath(hModule);
		auto configPath = path / CONFIG_FILE;
		if (!fs::exists(configPath))
		{
			FILE* f;
			if (_wfopen_s(&f, configPath.c_str(), L"wb") == 0)
			{
				fputs(defConfigFile, f);
				fclose(f);
			}
		}

		GSOFontMode fixGSOFont = DISABLED;
		LOGFONT userGSOFont = {};

		wchar_t errMsg[512];
		bool debug;
		if (!LoadSettings(hModule, configPath, errMsg, fixGSOFont, userGSOFont, debug))
		{
			wchar_t msg[512];
			swprintf_s(msg, L"LoadSettings error.\n%s", errMsg);

			SetThreadDpiAware();
			MessageBoxW(0, msg, L"Error", MB_ICONERROR);
			return TRUE;
		}

		if (debug)
		{
			auto logPath = path / LOG_FILE;
			logFile = _wfsopen(logPath.c_str(), L"a+", _SH_DENYWR);
			setvbuf(logFile, nullptr, _IOLBF, BUFSIZ);
		}

		LoadUserFonts(path);

		switch (fixGSOFont)
		{
		case USE_NCM_FONT:
		{
			NONCLIENTMETRICSW ncm = { sizeof(ncm) };
			if (SystemParametersInfoW(SPI_GETNONCLIENTMETRICS, sizeof(ncm), &ncm, 0))
			{
				newGSOFont = CreateFontIndirectW(&ncm.lfMessageFont);
				if (logFile)
				{
					std::string name;
					if (Utf16ToUtf8(ncm.lfMessageFont.lfFaceName, name))
					{
						fprintf_s(logFile, "[DllMain] SystemParametersInfo NONCLIENTMETRICS.lfMessageFont.lfFaceName=\"%s\"\n", name.c_str());
					}
				}
			}
			else if (logFile)
			{
				fprintf_s(logFile, "[DllMain] SystemParametersInfo failed. (%d)\n", GetLastError());
			}
		}
		break;
		case USE_USER_FONT:
		{
			newGSOFont = CreateFontIndirectW(&userGSOFont);
		}
		break;
		}

		HMODULE hGdi32 = GetModuleHandleW(L"gdi32.dll");

		if (fixGSOFont != DISABLED)
		{
			auto pfnGetStockObject = GetProcAddress(hGdi32, "GetStockObject");
			if (pfnGetStockObject)
			{
				InlineHook(pfnGetStockObject, MyGetStockObject, &addrGetStockObject);
			}
		}

		auto pfnCreateFontIndirectW = GetProcAddress(hGdi32, "CreateFontIndirectW");
		if (pfnCreateFontIndirectW)
		{
			InlineHook(pfnCreateFontIndirectW, MyCreateFontIndirectW, &addrCreateFontIndirectW);
		}
	}
	else if (ul_reason_for_call == DLL_PROCESS_DETACH)
	{
		if (logFile)
			fclose(logFile);
	}
	return TRUE;
}
