#include "pch.h"
namespace fs = std::filesystem;
#include "Util.hpp"
#include "DllStub.hpp"
#include "DefConfigFile.hpp"
#include "RymlCallbacks.hpp"

#define CONFIG_FILE_STR L"FontMod.yaml"
constexpr std::wstring_view CONFIG_FILE = CONFIG_FILE_STR;
constexpr std::wstring_view LOG_FILE = L"FontMod.log";

auto addrCreateFontIndirectExW = CreateFontIndirectExW;
auto addrGetStockObject = GetStockObject;

namespace GPFlat = Gdiplus::DllExports;
using GPFlat::GdipCreateFontFamilyFromName;
decltype(GdipCreateFontFamilyFromName)* addrGdipCreateFontFamilyFromName = nullptr;
using GPFlat::GdipCreateFont;
decltype(GdipCreateFont)* addrGdipCreateFont = nullptr;
using GPFlat::GdipGetFamilyName;
decltype(GdipGetFamilyName)* addrGdipGetFamilyName = nullptr;
using GPFlat::GdipGetGenericFontFamilySansSerif;
decltype(GdipGetGenericFontFamilySansSerif)* addrGdipGetGenericFontFamilySansSerif = nullptr;
using GPFlat::GdipGetGenericFontFamilySerif;
decltype(GdipGetGenericFontFamilySerif)* addrGdipGetGenericFontFamilySerif = nullptr;
using GPFlat::GdipGetGenericFontFamilyMonospace;
decltype(GdipGetGenericFontFamilyMonospace)* addrGdipGetGenericFontFamilyMonospace = nullptr;

struct FontInfo
{
	enum struct OverrideFlags : uint32_t
	{
		None = 0,
		Height = 1 << 1,
		Width = 1 << 2,
		Weight = 1 << 3,
		Italic = 1 << 4,
		Underline = 1 << 5,
		StrikeOut = 1 << 6,
		Charset = 1 << 7,
		OutPrecision = 1 << 8,
		ClipPrecision = 1 << 9,
		Quality = 1 << 10,
		PitchAndFamily = 1 << 11
	};

	std::wstring name;
	OverrideFlags overrideFlags = OverrideFlags::None;
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

DEFINE_ENUM_FLAG_OPERATORS(FontInfo::OverrideFlags);

enum struct GSOFontMode
{
	Disabled,
	UseNCMFont, // Use default font from SystemParametersInfo SPI_GETNONCLIENTMETRICS
	UseUserFont // Use user defined font
};

struct GPFontInfo
{
	enum struct OverrideFlags : uint32_t
	{
		None = 0,
		Size = 1 << 1,
		Style = 1 << 2,
		Unit = 1 << 3
	};

	enum struct Style
	{
		Regular,
		Bold,
		Italic,
		BoldItalic,
		Underline,
		Strikeout
	};

	enum struct Unit
	{
		World,
		Display,
		Pixel,
		Point,
		Inch,
		Document,
		Millimeter
	};

	OverrideFlags overrideFlags = OverrideFlags::None;
	float size;
	Style style;
	Unit unit;
};

DEFINE_ENUM_FLAG_OPERATORS(GPFontInfo::OverrideFlags);

std::unordered_map<std::wstring, FontInfo> fontsMap;
wil::unique_hfile logFile;
HFONT newGSOFont = nullptr;

std::unordered_map<std::wstring, std::wstring> gdipFontFamiliesMap;
std::unordered_map<std::wstring, GPFontInfo> gdipFontsMap;

std::wstring gdipGFFSansSerif;
std::wstring gdipGFFSerif;
std::wstring gdipGFFMonospace;

void OverrideLogFont(const FontInfo& info, LOGFONTW& lf)
{
	using OF = FontInfo::OverrideFlags;

	if (!info.name.empty())
		info.name.copy(lf.lfFaceName, LF_FACESIZE);
	if ((info.overrideFlags & OF::Height) == OF::Height)
		lf.lfHeight = info.height;
	if ((info.overrideFlags & OF::Width) == OF::Width)
		lf.lfWidth = info.width;
	if ((info.overrideFlags & OF::Weight) == OF::Weight)
		lf.lfWeight = info.weight;
	if ((info.overrideFlags & OF::Italic) == OF::Italic)
		lf.lfItalic = info.italic;
	if ((info.overrideFlags & OF::Underline) == OF::Underline)
		lf.lfUnderline = info.underLine;
	if ((info.overrideFlags & OF::StrikeOut) == OF::StrikeOut)
		lf.lfStrikeOut = info.strikeOut;
	if ((info.overrideFlags & OF::Charset) == OF::Charset)
		lf.lfCharSet = info.charSet;
	if ((info.overrideFlags & OF::OutPrecision) == OF::OutPrecision)
		lf.lfOutPrecision = info.outPrecision;
	if ((info.overrideFlags & OF::ClipPrecision) == OF::ClipPrecision)
		lf.lfClipPrecision = info.clipPrecision;
	if ((info.overrideFlags & OF::Quality) == OF::Quality)
		lf.lfQuality = info.quality;
	if ((info.overrideFlags & OF::PitchAndFamily) == OF::PitchAndFamily)
		lf.lfPitchAndFamily = info.pitchAndFamily;
}

HFONT WINAPI MyCreateFontIndirectExW(const ENUMLOGFONTEXDVW* lpelf)
{
	auto lplf = &lpelf->elfEnumLogfontEx.elfLogFont;

	if (logFile)
	{
		std::string name;
		if (Utf16ToUtf8(lplf->lfFaceName, name))
		{
			FormatToFile(logFile.get(),
				"[CreateFont] name = \"{}\", height = {}, "
				"width = {}, escapement = {}, "
				"orientation = {}, weight = {}, "
				"italic = {}, underline = {}, "
				"strikeout = {}, charset = {}, "
				"outprecision = {}, clipprecision = {}, "
				"quality = {}, pitchandfamily = {}\n",
				name, lplf->lfHeight,
				lplf->lfWidth, lplf->lfEscapement,
				lplf->lfOrientation, lplf->lfWeight,
				!!lplf->lfItalic, !!lplf->lfUnderline,
				!!lplf->lfStrikeOut, lplf->lfCharSet,
				lplf->lfOutPrecision, lplf->lfClipPrecision,
				lplf->lfQuality, lplf->lfPitchAndFamily);
		}
	}

	ENUMLOGFONTEXDVW elf;

	auto it = fontsMap.find(lplf->lfFaceName);
	if (it != fontsMap.end())
	{
		elf = *lpelf;
		LOGFONTW& lf = elf.elfEnumLogfontEx.elfLogFont;

		OverrideLogFont(it->second, lf);

		lpelf = &elf;
	}
	return addrCreateFontIndirectExW(lpelf);
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
	return addrGetStockObject(i);
}

using Gdiplus::GpStatus;
using Gdiplus::GpFontCollection;
using Gdiplus::GpFontFamily;
using Gdiplus::REAL;
using Gdiplus::Unit;
using Gdiplus::GpFont;

GpStatus WINGDIPAPI MyGdipCreateFontFamilyFromName(GDIPCONST WCHAR* name, GpFontCollection* fontCollection, GpFontFamily** fontFamily)
{
	if (logFile)
	{
		std::string u8name;
		if (Utf16ToUtf8(name, u8name))
		{
			FormatToFile(logFile.get(), "[GdipCreateFontFamilyFromName] name = \"{}\", fontCollection = {:x}\n", u8name, reinterpret_cast<size_t>(fontCollection));
		}
	}

	auto it = gdipFontFamiliesMap.find(name);
	if (it != gdipFontFamiliesMap.end())
		name = it->second.c_str();

	return addrGdipCreateFontFamilyFromName(name, fontCollection, fontFamily);
}

GpStatus WINGDIPAPI MyGdipCreateFont(GDIPCONST GpFontFamily* fontFamily, REAL emSize, INT style, Unit unit, GpFont** font)
{
	std::wstring name(LF_FACESIZE, 0);
	if (addrGdipGetFamilyName(fontFamily, name.data(), LANG_NEUTRAL) == GpStatus::Ok)
	{
		name.resize(wcslen(name.c_str()));

		if (logFile)
		{
			std::string u8name;
			if (Utf16ToUtf8(name, u8name))
			{
				FormatToFile(logFile.get(), "[GdipCreateFont] name = \"{}\", emSize = {}, style = {}, unit = {}\n", u8name, emSize, style, static_cast<uint32_t>(unit));
			}
		}

		auto it = gdipFontsMap.find(name);
		if (it != gdipFontsMap.end())
		{
			using OF = GPFontInfo::OverrideFlags;
			if ((it->second.overrideFlags & OF::Size) == OF::Size)
				emSize = it->second.size;
			if ((it->second.overrideFlags & OF::Style) == OF::Style)
				style = static_cast<INT>(it->second.style);
			if ((it->second.overrideFlags & OF::Unit) == OF::Unit)
				unit = static_cast<Unit>(it->second.unit);
		}
	}

	return addrGdipCreateFont(fontFamily, emSize, style, unit, font);
}

GpStatus WINGDIPAPI MyGdipGetGenericFontFamilySansSerif(GpFontFamily** nativeFamily)
{
	return addrGdipCreateFontFamilyFromName(gdipGFFSansSerif.c_str(), nullptr, nativeFamily);
}

GpStatus WINGDIPAPI MyGdipGetGenericFontFamilySerif(GpFontFamily** nativeFamily)
{
	return addrGdipCreateFontFamilyFromName(gdipGFFSerif.c_str(), nullptr, nativeFamily);
}

GpStatus WINGDIPAPI MyGdipGetGenericFontFamilyMonospace(GpFontFamily** nativeFamily)
{
	return addrGdipCreateFontFamilyFromName(gdipGFFMonospace.c_str(), nullptr, nativeFamily);
}

FontInfo GetFontInfo(const ryml::NodeRef& map)
{
	FontInfo info;
	for (const auto& i : map)
	{
		using OF = FontInfo::OverrideFlags;

		if (!i.has_val())
			continue;

		if (i.key() == "replace" || i.key() == "name")
		{
			if (!Utf8ToUtf16(i.val(), info.name))
				info.name.clear();
		}
		else if (i.key() == "size")
		{
			i >> info.height;
			info.overrideFlags |= OF::Height;
		}
		else if (i.key() == "width")
		{
			i >> info.width;
			info.overrideFlags |= OF::Width;
		}
		else if (i.key() == "weight")
		{
			i >> info.weight;
			info.overrideFlags |= OF::Weight;
		}
		else if (i.key() == "italic")
		{
			i >> info.italic;
			info.overrideFlags |= OF::Italic;
		}
		else if (i.key() == "underLine")
		{
			i >> info.underLine;
			info.overrideFlags |= OF::Underline;
		}
		else if (i.key() == "strikeOut")
		{
			i >> info.strikeOut;
			info.overrideFlags |= OF::StrikeOut;
		}
		else if (i.key() == "charSet")
		{
			i >> info.charSet;
			info.overrideFlags |= OF::Charset;
		}
		else if (i.key() == "outPrecision")
		{
			i >> info.outPrecision;
			info.overrideFlags |= OF::OutPrecision;
		}
		else if (i.key() == "clipPrecision")
		{
			i >> info.clipPrecision;
			info.overrideFlags |= OF::ClipPrecision;
		}
		else if (i.key() == "quality")
		{
			i >> info.quality;
			info.overrideFlags |= OF::Quality;
		}
		else if (i.key() == "pitchAndFamily")
		{
			i >> info.pitchAndFamily;
			info.overrideFlags |= OF::PitchAndFamily;
		}
	}
	return info;
}

void AddGdiplusFontInfo(const ryml::NodeRef& map)
{
	for (const auto& i : map)
	{
		if (!i.has_val())
			continue;

		if (i.key() == "replace" || i.key() == "name")
		{
			std::wstring find, name;
			if (Utf8ToUtf16(map.key(), find) && Utf8ToUtf16(i.val(), name))
				gdipFontFamiliesMap.emplace(std::move(find), std::move(name));
			return;
		}

		GPFontInfo info;
		if (i.key() == "size")
		{
			i >> info.size;
			info.overrideFlags |= GPFontInfo::OverrideFlags::Size;
		}
		else if (i.key() == "style")
		{
			using Style = GPFontInfo::Style;

			bool ok = true;
			if (i.val() == "regular")
			{
				info.style = Style::Regular;
			}
			else if (i.val() == "bold")
			{
				info.style = Style::Regular;
			}
			else if (i.val() == "italic")
			{
				info.style = Style::Italic;
			}
			else if (i.val() == "boldItalic")
			{
				info.style = Style::BoldItalic;
			}
			else if (i.val() == "underline")
			{
				info.style = Style::Underline;
			}
			else if (i.val() == "strikeout")
			{
				info.style = Style::Strikeout;
			}
			else
			{
				uint32_t style;
				if (read(i, &style))
					info.style = static_cast<Style>(style);
				else
					ok = false;
			}

			if (ok)
				info.overrideFlags |= GPFontInfo::OverrideFlags::Style;
		}
		else if (i.key() == "unit")
		{
			using Unit = GPFontInfo::Unit;

			bool ok = true;
			if (i.val() == "world")
			{
				info.unit = Unit::World;
			}
			else if (i.val() == "display")
			{
				info.unit = Unit::Display;
			}
			else if (i.val() == "pixel")
			{
				info.unit = Unit::Pixel;
			}
			else if (i.val() == "point")
			{
				info.unit = Unit::Point;
			}
			else if (i.val() == "inch")
			{
				info.unit = Unit::Inch;
			}
			else if (i.val() == "document")
			{
				info.unit = Unit::Document;
			}
			else if (i.val() == "millimeter")
			{
				info.unit = Unit::Millimeter;
			}
			else
			{
				uint32_t unit;
				if (read(i, &unit))
					info.unit = static_cast<Unit>(unit);
				else
					ok = false;
			}

			if (ok)
				info.overrideFlags |= GPFontInfo::OverrideFlags::Unit;
		}

		if (info.overrideFlags != GPFontInfo::OverrideFlags::None)
		{
			std::wstring find;
			if (Utf8ToUtf16(map.key(), find))
				gdipFontsMap.emplace(std::move(find), std::move(info));
		}
	}
}

bool LoadSettings(const fs::path& fileName, GSOFontMode& fixGSOFont, LOGFONT& userGSOFont, bool& debug, std::wstring& errMsg)
{
	auto config = LoadUtf8FileWithoutBOM(fileName.c_str());
	const auto tree = [&] {
		auto tree = ryml::parse(c4::substr(config.data(), config.size()));
		tree.resolve();
		return tree;
	}();

	if (!tree.is_map(tree.root_id()))
	{
		errMsg.append(L"Root node is not a map.");
		return false;
	}

	for (const auto& i : tree.rootref())
	{
		if (i.is_map() && i.key() == "fonts")
		{
			for (const auto& j : i)
			{
				if (j.is_map())
				{
					auto info = GetFontInfo(j);
					std::wstring find;
					if (Utf8ToUtf16(j.key(), find))
						fontsMap.emplace(std::move(find), std::move(info));
				}
			}
		}
		else if (i.key() == "fixGSOFont")
		{
			if (i.has_val())
			{
				bool b;
				i >> b;
				if (b)
					fixGSOFont = GSOFontMode::UseNCMFont;
			}
			else if (i.is_map())
			{
				auto info = GetFontInfo(i);
				OverrideLogFont(info, userGSOFont);
			}
		}
		else if (i.is_map() && i.key() == "gdiplus")
		{
			for (const auto& j : i)
			{
				if (j.is_map())
					AddGdiplusFontInfo(j);
			}
		}
		else if (i.has_val() && i.key() == "gdipGFFSansSerif")
		{
			if (!Utf8ToUtf16(i.val(), gdipGFFSansSerif))
				gdipGFFSansSerif.clear();
		}
		else if (i.has_val() && i.key() == "gdipGFFSerif")
		{
			if (!Utf8ToUtf16(i.val(), gdipGFFSerif))
				gdipGFFSerif.clear();
		}
		else if (i.has_val() && i.key() == "gdipGFFMonospace")
		{
			if (!Utf8ToUtf16(i.val(), gdipGFFMonospace))
				gdipGFFMonospace.clear();
		}
		else if (i.has_val() && i.key() == "debug")
		{
			i >> debug;
		}
	}

	return true;
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
					std::u8string u8str = f.path().filename().u8string();
					std::string_view sv(reinterpret_cast<const char*>(u8str.data()), u8str.size());
					FormatToFile(logFile.get(), "[LoadUserFonts] filename = \"{}\", ret = {}, lasterror = {}\n", sv, ret, GetLastError());
				}
			}
		}
	}
	catch (const std::exception& e)
	{
		if (logFile)
		{
			FormatToFile(logFile.get(), "[LoadUserFonts] exception: \"{}\"\n", e.what());
		}
	}
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, [[maybe_unused]] LPVOID lpReserved)
{
	if (ul_reason_for_call == DLL_PROCESS_ATTACH)
	{
		DisableThreadLibraryCalls(hModule);

#if _DEBUG
		MessageBoxW(0, L"DLL_PROCESS_ATTACH", L"", 0);
#endif

		SetRymlCallbacks();

		auto path = GetModuleFsPath(hModule);
		LoadDLL(path.filename());

		path = path.remove_filename();
		auto configPath = path / CONFIG_FILE;
		{
			wil::unique_hfile hFile(CreateFileW(configPath.c_str(), GENERIC_WRITE, FILE_SHARE_READ, nullptr, CREATE_NEW, FILE_ATTRIBUTE_NORMAL, nullptr));
			if (hFile)
			{
				DWORD written;
				WriteFile(hFile.get(), defConfigFile.data(), static_cast<DWORD>(defConfigFile.size()), &written, nullptr);
			}
		}

		GSOFontMode fixGSOFont = GSOFontMode::Disabled;
		LOGFONT userGSOFont = {};

		bool debug = false;
		std::wstring errMsg(L"LoadSettings error.\n");
		if (!LoadSettings(configPath, fixGSOFont, userGSOFont, debug, errMsg))
		{
			auto restore = SetThreadDpiAwareAutoRestore();
			MessageBoxW(0, errMsg.c_str(), L"Error", MB_ICONERROR);
			return TRUE;
		}

		if (debug)
		{
			auto logPath = path / LOG_FILE;
			logFile.reset(CreateFileW(logPath.c_str(), GENERIC_WRITE, FILE_SHARE_READ, nullptr, OPEN_ALWAYS, FILE_ATTRIBUTE_TEMPORARY, nullptr));
		}

		LoadUserFonts(path);

		switch (fixGSOFont)
		{
		case GSOFontMode::UseNCMFont:
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
						FormatToFile(logFile.get(), "[DllMain] SystemParametersInfo NONCLIENTMETRICS.lfMessageFont.lfFaceName=\"{}\"\n", name);
					}
				}
			}
			else if (logFile)
			{
				FormatToFile(logFile.get(), "[DllMain] SystemParametersInfo failed. ({})\n", GetLastError());
			}
		}
		break;
		case GSOFontMode::UseUserFont:
		{
			newGSOFont = CreateFontIndirectW(&userGSOFont);
		}
		break;
		}

		auto hGdiFull = GetModuleHandleW(L"gdi32full.dll");
		if (hGdiFull)
		{
			auto addrGetStockObjectFull = GetProcAddressByFunctionDeclaration(hGdiFull, GetStockObject);
			if (addrGetStockObjectFull)
				addrGetStockObject = addrGetStockObjectFull;

			auto addrCreateFontIndirectExWFull = GetProcAddressByFunctionDeclaration(hGdiFull, CreateFontIndirectExW);
			if (addrCreateFontIndirectExWFull)
				addrCreateFontIndirectExW = addrCreateFontIndirectExWFull;
		}

		DetourTransactionBegin();
		DetourUpdateThread(GetCurrentThread());

		if (fixGSOFont != GSOFontMode::Disabled)
		{
			DetourAttach(&(PVOID&)addrGetStockObject, MyGetStockObject);
		}
		DetourAttach(&(PVOID&)addrCreateFontIndirectExW, MyCreateFontIndirectExW);

		if (!gdipFontFamiliesMap.empty() || !gdipFontsMap.empty() || !gdipGFFSansSerif.empty() || !gdipGFFSerif.empty() || !gdipGFFMonospace.empty())
		{
			HMODULE hGdiplus = LoadLibraryW((GetSysDirFsPath() / L"gdiplus.dll").c_str());
			auto err = GetLastError();
			FormatToFile(logFile.get(), "[DllMain] Load GDI+ address = {:x}, lasterror = {}\n", reinterpret_cast<size_t>(hGdiplus), err);

			if (hGdiplus)
			{
				if (!gdipFontFamiliesMap.empty())
				{
					addrGdipCreateFontFamilyFromName = GetProcAddressByFunctionDeclaration(hGdiplus, GdipCreateFontFamilyFromName);
					if (addrGdipCreateFontFamilyFromName)
						DetourAttach(&(PVOID&)addrGdipCreateFontFamilyFromName, MyGdipCreateFontFamilyFromName);
				}

				if (!gdipFontsMap.empty())
				{
					addrGdipCreateFont = GetProcAddressByFunctionDeclaration(hGdiplus, GdipCreateFont);
					if (addrGdipCreateFont)
					{
						addrGdipGetFamilyName = GetProcAddressByFunctionDeclaration(hGdiplus, GdipGetFamilyName);
						if (addrGdipGetFamilyName)
							DetourAttach(&(PVOID&)addrGdipCreateFont, MyGdipCreateFont);
					}
				}

				if (!gdipGFFSansSerif.empty())
				{
					addrGdipGetGenericFontFamilySansSerif = GetProcAddressByFunctionDeclaration(hGdiplus, GdipGetGenericFontFamilySansSerif);
					if (addrGdipGetGenericFontFamilySansSerif)
						DetourAttach(&(PVOID&)addrGdipGetGenericFontFamilySansSerif, MyGdipGetGenericFontFamilySansSerif);
				}

				if (!gdipGFFSerif.empty())
				{
					addrGdipGetGenericFontFamilySerif = GetProcAddressByFunctionDeclaration(hGdiplus, GdipGetGenericFontFamilySerif);
					if (addrGdipGetGenericFontFamilySerif)
						DetourAttach(&(PVOID&)addrGdipGetGenericFontFamilySerif, MyGdipGetGenericFontFamilySerif);
				}

				if (!gdipGFFMonospace.empty())
				{
					addrGdipGetGenericFontFamilyMonospace = GetProcAddressByFunctionDeclaration(hGdiplus, GdipGetGenericFontFamilyMonospace);
					if (addrGdipGetGenericFontFamilyMonospace)
						DetourAttach(&(PVOID&)addrGdipGetGenericFontFamilyMonospace, MyGdipGetGenericFontFamilyMonospace);
				}
			}
		}

		auto error = DetourTransactionCommit();
		if (error != ERROR_SUCCESS)
		{
			auto msg = std::format(L"DetourTransactionCommit error: {}", error);
			{
				auto restore = SetThreadDpiAwareAutoRestore();
				MessageBoxW(0, msg.c_str(), L"Error", MB_ICONERROR);
			}
			return TRUE;
		}
	}
	return TRUE;
}
