#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <windows.h>
#include <cstdint>
#include <map>
#include <string>
#include <io.h>

#include "winmm.h"
#include "HiDPI.h"

#define RAPIDJSON_ERROR_CHARTYPE wchar_t
#define RAPIDJSON_ERROR_STRING(x) L##x
#include "rapidjson/document.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/encodings.h"
#include "rapidjson/filereadstream.h"
#include "rapidjson/encodedstream.h"
#include "rapidjson/error/zh_CN.h"

using namespace rapidjson;

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

std::map<std::wstring, font> fontsMap;
bool debug = false;
FILE *logFile = nullptr;
HFONT newGSOFont = nullptr;

__declspec(naked) HFONT WINAPI CallOrigCreateFontIndirectW(const LOGFONTW *lplf)
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

bool Utf8ToUtf16(const char *source, GenericStringBuffer<UTF16<>> &target)
{
	bool success = true;
	GenericStringStream<UTF8<>> sourceStream(source);
	while (sourceStream.Peek() != '\0')
		if (!rapidjson::Transcoder<UTF8<>, UTF16<>>::Transcode(sourceStream, target))
		{
			success = true;
			break;
		}
	return success;
}

bool Utf16ToUtf8(const wchar_t *source, GenericStringBuffer<UTF8<>> &target)
{
	bool success = true;
	GenericStringStream<UTF16<>> sourceStream(source);
	while (sourceStream.Peek() != '\0')
		if (!rapidjson::Transcoder<UTF16<>, UTF8<>>::Transcode(sourceStream, target))
		{
			success = true;
			break;
		}
	return success;
}

HFONT WINAPI MyCreateFontIndirectW(LOGFONTW *lplf)
{
	if (debug && logFile)
	{
		GenericStringBuffer<UTF8<>> name;
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
				"quality = %d, pitchandfamily = %d\r\n",
				name.GetString(), lplf->lfHeight,
				lplf->lfWidth, lplf->lfEscapement,
				lplf->lfOrientation, lplf->lfWeight,
				bool_string(lplf->lfItalic), bool_string(lplf->lfUnderline),
				bool_string(lplf->lfStrikeOut), lplf->lfCharSet,
				lplf->lfOutPrecision, lplf->lfClipPrecision,
				lplf->lfQuality, lplf->lfPitchAndFamily);
			fflush(logFile);
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
	if (OEM_FIXED_FONT <= i && i <= DEFAULT_GUI_FONT && i != DEFAULT_PALETTE)
		return newGSOFont;
	return CallOrigGetStockObject(i);
}

bool LoadSettings(HMODULE hModule, const wchar_t *fileName, wchar_t *errMsg, GSOFontMode &fixGSOFont, LOGFONT &userGSOFont)
{
	bool ret = false;
	FILE *file;
	if (_wfopen_s(&file, fileName, L"rb") == 0)
	{
		do {
			char readBuffer[512];
			FileReadStream is(file, readBuffer, sizeof(readBuffer));
			EncodedInputStream<UTF8<>, FileReadStream> eis(is);

			GenericDocument<UTF16<>> dom;

			if (dom.ParseStream<0, UTF8<>>(eis).HasParseError())
			{
				swprintf(errMsg, 512, L"解析 JSON 时出现错误! (%s, 偏移: %u)", GetParseError_Zh_Cn(dom.GetParseError()), dom.GetErrorOffset());
				break;
			}

			if (!dom.IsObject())
			{
				wcscpy_s(errMsg, 512, L"JSON 格式不合法, 根值不是 Object!");
				break;
			}

			auto member = dom.FindMember(L"fonts");
			if (member != dom.MemberEnd() && member->value.IsObject())
			{
				for (auto it = member->value.MemberBegin(); it != member->value.MemberEnd(); ++it)
				{
					if (it->value.IsObject())
					{
						std::wstring find = std::wstring(it->name.GetString(), it->name.GetStringLength());

						auto replace = it->value.FindMember(L"replace");
						if (replace != it->value.MemberEnd() && replace->value.IsString())
						{
							font fontInfo;
							fontInfo.replace = std::wstring(replace->value.GetString(), replace->value.GetStringLength());
							fontInfo.overrideFlags = _NONE;

							auto member = it->value.FindMember(L"size");
							if (member != it->value.MemberEnd() && member->value.IsInt())
							{
								fontInfo.overrideFlags |= _HEIGHT;
								fontInfo.height = member->value.GetInt();
							}

							member = it->value.FindMember(L"width");
							if (member != it->value.MemberEnd() && member->value.IsInt())
							{
								fontInfo.overrideFlags |= _WIDTH;
								fontInfo.width = member->value.GetInt();
							}

							member = it->value.FindMember(L"weight");
							if (member != it->value.MemberEnd() && member->value.IsInt())
							{
								fontInfo.overrideFlags |= _WEIGHT;
								fontInfo.weight = member->value.GetInt();
							}

							member = it->value.FindMember(L"italic");
							if (member != it->value.MemberEnd() && member->value.IsBool())
							{
								fontInfo.overrideFlags |= _ITALIC;
								fontInfo.italic = member->value.GetBool();
							}

							member = it->value.FindMember(L"underLine");
							if (member != it->value.MemberEnd() && member->value.IsBool())
							{
								fontInfo.overrideFlags |= _UNDERLINE;
								fontInfo.underLine = member->value.GetBool();
							}

							member = it->value.FindMember(L"strikeOut");
							if (member != it->value.MemberEnd() && member->value.IsBool())
							{
								fontInfo.overrideFlags |= _STRIKEOUT;
								fontInfo.strikeOut = member->value.GetBool();
							}

							member = it->value.FindMember(L"charSet");
							if (member != it->value.MemberEnd() && member->value.IsInt())
							{
								fontInfo.overrideFlags |= _CHARSET;
								fontInfo.charSet = member->value.GetInt();
							}

							member = it->value.FindMember(L"outPrecision");
							if (member != it->value.MemberEnd() && member->value.IsInt())
							{
								fontInfo.overrideFlags |= _OUTPRECISION;
								fontInfo.outPrecision = member->value.GetInt();
							}

							member = it->value.FindMember(L"clipPrecision");
							if (member != it->value.MemberEnd() && member->value.IsInt())
							{
								fontInfo.overrideFlags |= _CLIPPRECISION;
								fontInfo.clipPrecision = member->value.GetInt();
							}

							member = it->value.FindMember(L"quality");
							if (member != it->value.MemberEnd() && member->value.IsInt())
							{
								fontInfo.overrideFlags |= _QUALITY;
								fontInfo.quality = member->value.GetInt();
							}

							member = it->value.FindMember(L"pitchAndFamily");
							if (member != it->value.MemberEnd() && member->value.IsInt())
							{
								fontInfo.overrideFlags |= _PITCHANDFAMILY;
								fontInfo.pitchAndFamily = member->value.GetInt();
							}

							fontsMap[find] = fontInfo;
						}
					}
				}
			}

			member = dom.FindMember(L"debug");
			if (member != dom.MemberEnd() && member->value.IsBool())
				debug = member->value.GetBool();

			member = dom.FindMember(L"fixGSOFont");
			if (member != dom.MemberEnd())
			{
				if (member->value.IsBool())
				{
					if (member->value.GetBool())
						fixGSOFont = USE_NCM_FONT;
				}
				else if (member->value.IsObject())
				{
					auto name = member->value.FindMember(L"name");
					if (name != member->value.MemberEnd() && name->value.IsString())
					{
						fixGSOFont = USE_USER_FONT;
						memcpy_s(userGSOFont.lfFaceName, sizeof(userGSOFont.lfFaceName), name->value.GetString(), name->value.GetStringLength() * sizeof(decltype(name->value)::Ch));

						auto m = member->value.FindMember(L"size");
						if (m != member->value.MemberEnd() && m->value.IsInt())
						{
							userGSOFont.lfHeight = m->value.GetInt();
						}

						m = member->value.FindMember(L"width");
						if (m != member->value.MemberEnd() && m->value.IsInt())
						{
							userGSOFont.lfWidth = m->value.GetInt();
						}

						m = member->value.FindMember(L"weight");
						if (m != member->value.MemberEnd() && m->value.IsInt())
						{
							userGSOFont.lfWeight = m->value.GetInt();
						}

						m = member->value.FindMember(L"italic");
						if (m != member->value.MemberEnd() && m->value.IsBool())
						{
							userGSOFont.lfItalic = m->value.GetBool();
						}

						m = member->value.FindMember(L"underLine");
						if (m != member->value.MemberEnd() && m->value.IsBool())
						{
							userGSOFont.lfUnderline = m->value.GetBool();
						}

						m = member->value.FindMember(L"strikeOut");
						if (m != member->value.MemberEnd() && m->value.IsBool())
						{
							userGSOFont.lfStrikeOut = m->value.GetBool();
						}

						m = member->value.FindMember(L"charSet");
						if (m != member->value.MemberEnd() && m->value.IsInt())
						{
							userGSOFont.lfCharSet = m->value.GetInt();
						}

						m = member->value.FindMember(L"outPrecision");
						if (m != member->value.MemberEnd() && m->value.IsInt())
						{
							userGSOFont.lfOutPrecision = m->value.GetInt();
						}

						m = member->value.FindMember(L"clipPrecision");
						if (m != member->value.MemberEnd() && m->value.IsInt())
						{
							userGSOFont.lfClipPrecision = m->value.GetInt();
						}

						m = member->value.FindMember(L"quality");
						if (m != member->value.MemberEnd() && m->value.IsInt())
						{
							userGSOFont.lfQuality = m->value.GetInt();
						}

						m = member->value.FindMember(L"pitchAndFamily");
						if (m != member->value.MemberEnd() && m->value.IsInt())
						{
							userGSOFont.lfPitchAndFamily = m->value.GetInt();
						}
					}
				}
			}

			ret = true;
		} while (0);
		fclose(file);
	}
	else
	{
#pragma warning(push)
#pragma warning(disable: 4996) // 'strerror': This function or variable may be unsafe.
		swprintf(errMsg, 512, L"无法打开 TGFont.json! (%hs)", strerror(errno));
#pragma warning(pop)
	}
	return ret;
}

void LoadUserFonts(const wchar_t *path)
{
	wchar_t fontPath[MAX_PATH];
	wcscpy_s(fontPath, path);
	wcscat_s(fontPath, L"fonts\\");
	wchar_t *font = fontPath + wcslen(fontPath);
	font[0] = L'*';
	font[1] = 0;

	WIN32_FIND_DATAW ffd;
	HANDLE hFind = FindFirstFileW(fontPath, &ffd);
	if (hFind != INVALID_HANDLE_VALUE)
	{
		do {
			if ((ffd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) != FILE_ATTRIBUTE_DIRECTORY)
			{
				wcscpy_s(font, fontPath + MAX_PATH - font, ffd.cFileName);
				int ret = AddFontResourceExW(fontPath, FR_PRIVATE, 0);
				if (debug && logFile)
				{
					GenericStringBuffer<UTF8<>> filename;
					if (Utf16ToUtf8(ffd.cFileName, filename))
					{
						fprintf_s(logFile, "[LoadUserFonts] filename = \"%s\", ret = %d, lasterror = %d\r\n", filename.GetString(), ret, GetLastError());
						fflush(logFile);
					}
				}
			}
		} while (FindNextFileW(hFind, &ffd) != 0);
		FindClose(hFind);
	}
	else
	{
		if (debug && logFile)
		{
			fprintf_s(logFile, "[LoadUserFonts] FindFirstFile failed! (%d)\r\n", GetLastError());
			fflush(logFile);
		}
	}
}

void InlineHook(void *func, void *hookFunc, size_t *origAddr)
{
	DWORD oldProtect;
	if (VirtualProtect(func, 5, PAGE_EXECUTE_READWRITE, &oldProtect))
	{
		jmp *hook = (jmp *)func;
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

		wchar_t path[MAX_PATH];
		if (GetModuleFileNameW(hModule, path, MAX_PATH))
		{
			auto c = wcsrchr(path, L'\\');
			if (c) c[1] = L'\0';
		}

		wchar_t jsonName[MAX_PATH];
		wcscpy_s(jsonName, path);
		wcscat_s(jsonName, L"TGFont.json");

		if (_waccess_s(jsonName, 0) != 0)
		{
			FILE *file;
			if (_wfopen_s(&file, jsonName, L"wb") == 0)
			{
				fputs("{\r\n\t\"fonts\": {\r\n\t\t\"SimSun\": {\r\n\t\t\t\"replace\": \"Microsoft YaHei UI\",\r\n\t\t\t\"#size\": 0,\r\n\t\t\t\"#width\": 0,\r\n\t\t\t\"#weight\": 0,\r\n\t\t\t\"#italic\": false,\r\n\t\t\t\"#underLine\": false,\r\n\t\t\t\"#strikeOut\": false,\r\n\t\t\t\"#charSet\": 0,\r\n\t\t\t\"#outPrecision\": 0,\r\n\t\t\t\"#clipPrecision\": 0,\r\n\t\t\t\"#quality\": 0,\r\n\t\t\t\"#pitchAndFamily\": 0\r\n\t\t}\r\n\t},\r\n\t\"debug\": false\r\n}\r\n", file);
				fclose(file);
			}
		}

		GSOFontMode fixGSOFont = DISABLED;
		LOGFONT userGSOFont = {};

		wchar_t errMsg[512];
		if (!LoadSettings(hModule, jsonName, errMsg, fixGSOFont, userGSOFont))
		{
			wchar_t msg[512];
			swprintf_s(msg, L"加载配置文件时出现错误!\n%s", errMsg);

			SetThreadDpiAware();
			MessageBoxW(0, msg, L"Error", MB_ICONERROR);
			return TRUE;
		}

		if (debug)
		{
			wchar_t logName[MAX_PATH];
			wcscpy_s(logName, path);
			wcscat_s(logName, L"TGFont.log");
			logFile = _wfsopen(logName, L"ab+", _SH_DENYWR);
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
				if (debug && logFile)
				{
					fprintf_s(logFile, "[DllMain] SystemParametersInfo NONCLIENTMETRICS.lfMessageFont.lfFaceName=\"%ls\"\r\n", ncm.lfMessageFont.lfFaceName);
					fflush(logFile);
				}
			}
			else if (debug && logFile)
			{
				fprintf_s(logFile, "[DllMain] SystemParametersInfo failed! (%d)\r\n", GetLastError());
				fflush(logFile);
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
