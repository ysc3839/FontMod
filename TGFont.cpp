#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <stdint.h>

#include "winmm.h"

#pragma pack(push, 1)
struct jmp
{
	uint8_t opcode;
	size_t address;
};
#pragma pack(pop)

typedef HFONT(WINAPI* fnCreateFontIndirectW)(const LOGFONTW *lplf);

wchar_t find[32];
wchar_t replace[32];
int size;
fnCreateFontIndirectW origAddr = nullptr;

__declspec(naked) HFONT WINAPI CallOrigFn(const LOGFONTW *lplf)
{
	_asm
	{
		mov edi, edi
		push ebp
		mov ebp, esp
		jmp origAddr
	}
}

HFONT WINAPI MyCreateFontIndirectW(LOGFONTW *lplf)
{
	if (size != 0)
		lplf->lfHeight = size;

	if (wcsncmp(lplf->lfFaceName, find, _ARRAYSIZE(find)) == 0)
	{
		wcscpy_s(lplf->lfFaceName, replace);
	}
	return CallOrigFn(lplf);
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
	if (ul_reason_for_call == DLL_PROCESS_ATTACH)
	{
		DisableThreadLibraryCalls(hModule);

		if (!LoadDLL())
			return FALSE;

#if _DEBUG
		MessageBox(0, L"DLL_PROCESS_ATTACH", L"", 0);
#endif
		GetPrivateProfileString(L"TGFont", L"Find", L"SimSun", find, _ARRAYSIZE(find), L".\\TGFont.ini");
		GetPrivateProfileString(L"TGFont", L"Replace", L"Microsoft YaHei UI", replace, _ARRAYSIZE(replace), L".\\TGFont.ini");
		size = GetPrivateProfileInt(L"TGFont", L"Size", 0, L".\\TGFont.ini");

		size_t pfnCreateFontIndirectW = (size_t)GetProcAddress(GetModuleHandle(L"gdi32.dll"), "CreateFontIndirectW");
		if (pfnCreateFontIndirectW)
		{
			DWORD oldProtect;
			if (VirtualProtect((LPVOID)pfnCreateFontIndirectW, 5, PAGE_EXECUTE_READWRITE, &oldProtect))
			{
				jmp *hook = (jmp *)pfnCreateFontIndirectW;
				hook->opcode = 0xE9; // jmp
				hook->address = (size_t)MyCreateFontIndirectW - (size_t)pfnCreateFontIndirectW - 5;
				origAddr = (fnCreateFontIndirectW)(pfnCreateFontIndirectW + 5);
				VirtualProtect((LPVOID)pfnCreateFontIndirectW, 5, oldProtect, &oldProtect);
			}
		}
	}
	return TRUE;
}
