#pragma once

// Windows Header Files
#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
#define NOMINMAX
#include <windows.h>
#include <objidl.h>

// Fix gdiplustypes.h requires min/max
#include <algorithm>
using std::min;
using std::max;

#pragma warning(push)
#pragma warning(disable:4458)
#include <gdiplus.h>
#pragma warning(pop)

// C RunTime Header Files
#include <cstdint>
#include <unordered_map>
#include <string>
#include <string_view>
#include <filesystem>
#include <format>
