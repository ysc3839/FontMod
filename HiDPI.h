#pragma once

void SetThreadDpiAware()
{
	HMODULE hUser32 = GetModuleHandleW(L"user32.dll");
	if (hUser32)
	{
		using SetThreadDpiAwarenessContextPtr = DPI_AWARENESS_CONTEXT(WINAPI *)(DPI_AWARENESS_CONTEXT);
		auto funcPtr = reinterpret_cast<SetThreadDpiAwarenessContextPtr>(GetProcAddress(hUser32, "SetThreadDpiAwarenessContext"));
		if (funcPtr)
			funcPtr(DPI_AWARENESS_CONTEXT_SYSTEM_AWARE);
	}
}
