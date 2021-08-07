#pragma once

// https://msdn.microsoft.com/en-us/magazine/mt763237
bool Utf8ToUtf16(std::string_view utf8, std::wstring& utf16)
{
	if (utf8.empty())
	{
		utf16.clear();
		return true;
	}

	constexpr DWORD kFlags = MB_ERR_INVALID_CHARS;

	const int utf8Length = static_cast<int>(utf8.length());

	const int utf16Length = MultiByteToWideChar(
		CP_UTF8,
		kFlags,
		utf8.data(),
		utf8Length,
		nullptr,
		0
	);

	if (utf16Length == 0)
	{
		return false;
	}

	utf16.resize(utf16Length);

	int result = MultiByteToWideChar(
		CP_UTF8,
		kFlags,
		utf8.data(),
		utf8Length,
		utf16.data(),
		utf16Length
	);

	if (result == 0)
	{
		return false;
	}

	return true;
}

bool Utf8ToUtf16(c4::csubstr utf8, std::wstring& utf16)
{
	return Utf8ToUtf16(std::string_view(utf8.data(), utf8.size()), utf16);
}

bool Utf16ToUtf8(std::wstring_view utf16, std::string& utf8)
{
	if (utf16.empty())
	{
		utf8.clear();
		return true;
	}

	constexpr DWORD kFlags = WC_ERR_INVALID_CHARS;

	const int utf16Length = static_cast<int>(utf16.length());

	const int utf8Length = WideCharToMultiByte(
		CP_UTF8,
		kFlags,
		utf16.data(),
		utf16Length,
		nullptr,
		0,
		nullptr, nullptr
	);

	if (utf8Length == 0)
	{
		return false;
	}

	utf8.resize(utf8Length);

	int result = WideCharToMultiByte(
		CP_UTF8,
		kFlags,
		utf16.data(),
		utf16Length,
		utf8.data(),
		utf8Length,
		nullptr, nullptr
	);

	if (result == 0)
	{
		return false;
	}

	return true;
}

inline bool stol(const std::string& str, long& out)
{
	int& errno_ref = errno;
	const char *ptr = str.c_str();
	char *eptr;
	errno_ref = 0;
	out = strtol(ptr, &eptr, 10);

	if (ptr == eptr)
		return false;
	if (errno_ref == ERANGE)
		return false;
	return true;
}

inline bool stoul(const std::string& str, unsigned long& out)
{
	int& errno_ref = errno;
	const char *ptr = str.c_str();
	char *eptr;
	errno_ref = 0;
	out = strtoul(ptr, &eptr, 10);

	if (ptr == eptr)
		return false;
	if (errno_ref == ERANGE)
		return false;
	return true;
}

// https://docs.microsoft.com/en-us/windows/uwp/cpp-and-winrt-apis/author-coclasses#add-helper-types-and-functions
auto GetModuleFsPath(HMODULE hModule)
{
	std::wstring path(MAX_PATH, L'\0');
	DWORD pathSize;
	DWORD actualSize;

	do
	{
		pathSize = static_cast<DWORD>(path.size());
		actualSize = GetModuleFileNameW(hModule, path.data(), pathSize);

		if (actualSize + 1 > pathSize)
		{
			path.resize(pathSize * 2);
		}
	} while (actualSize + 1 > pathSize);

	path.resize(actualSize);
	return fs::path(path);
}

auto SetThreadDpiAwareAutoRestore() noexcept
{
	static std::optional<decltype(SetThreadDpiAwarenessContext)*> _SetThreadDpiAwarenessContext;

	struct thread_dpi_awareness_context
	{
		thread_dpi_awareness_context() noexcept : context(0) {}
		thread_dpi_awareness_context(DPI_AWARENESS_CONTEXT _context) noexcept : context(_context) {}
		~thread_dpi_awareness_context()
		{
			if (context != 0 && _SetThreadDpiAwarenessContext && *_SetThreadDpiAwarenessContext)
			{
				(*_SetThreadDpiAwarenessContext)(context);
			}
		}
		DPI_AWARENESS_CONTEXT context;
	};

	if (!_SetThreadDpiAwarenessContext)
	{
		auto funcPtr = GetProcAddressByFunctionDeclaration(GetModuleHandleW(L"user32.dll"), SetThreadDpiAwarenessContext);
		_SetThreadDpiAwarenessContext.emplace(funcPtr);
	}

	if (*_SetThreadDpiAwarenessContext)
		return thread_dpi_awareness_context((*_SetThreadDpiAwarenessContext)(DPI_AWARENESS_CONTEXT_PER_MONITOR_AWARE_V2));
	return thread_dpi_awareness_context();
}

auto GetSysDirFsPath()
{
	std::wstring path(MAX_PATH, L'\0');
	while (1)
	{
		const UINT pathSize = static_cast<UINT>(path.size());
		const UINT requiredSize = GetSystemDirectoryW(path.data(), pathSize);
		path.resize(requiredSize);

		if (requiredSize < pathSize)
			break;
	}
	return fs::path(path);
}

// https://stackoverflow.com/a/4119881/6911112
bool iequals(std::wstring_view a, std::wstring_view b)
{
	return (a.size() == b.size()) && std::equal(a.begin(), a.end(), b.begin(), b.end(),
		[](wchar_t a, wchar_t b) { return a == b || tolower(a) == tolower(b); });
}

template <size_t buf_size = 64>
struct format_to_file_buffer
{
	using value_type = char;
	format_to_file_buffer(HANDLE _hFile) noexcept : hFile(_hFile) {}
	~format_to_file_buffer() noexcept { flush(); }

	void flush() noexcept
	{
		DWORD written;
		WriteFile(hFile, buf, static_cast<DWORD>(len), &written, nullptr);
		len = 0;
	}

	void push_back(char c) noexcept
	{
		buf[len] = c;
		++len;
		if (len >= buf_size)
			flush();
	}

private:
	HANDLE hFile;
	char buf[buf_size];
	size_t len = 0;
};

template <class... Types>
void FormatToFile(HANDLE hFile, const std::string_view fmt, const Types&... args)
{
	format_to_file_buffer buf(hFile);
	std::format_to(std::back_insert_iterator(buf), fmt, args...);
}

inline void ReadFileCheckSize(HANDLE hFile, void* buffer, DWORD size)
{
	DWORD read;
	THROW_IF_WIN32_BOOL_FALSE(ReadFile(hFile, buffer, size, &read, nullptr));
	THROW_HR_IF(HRESULT_FROM_WIN32(ERROR_HANDLE_EOF), size != read);
}

std::string LoadUtf8FileWithoutBOM(LPCWSTR fileName)
{
	wil::unique_hfile hFile(CreateFileW(fileName, GENERIC_READ, FILE_SHARE_READ, nullptr, OPEN_EXISTING, 0, nullptr));
	THROW_LAST_ERROR_IF(!hFile);

	LARGE_INTEGER size;
	THROW_IF_WIN32_BOOL_FALSE(GetFileSizeEx(hFile.get(), &size));

	if (size.QuadPart == 0)
		return {};

	std::string result(static_cast<size_t>(size.QuadPart), 0);

	char* ptr = result.data();
	if (size.QuadPart >= 3)
	{
		ReadFileCheckSize(hFile.get(), ptr, 3);
		size.QuadPart -= 3;

		if (uint8_t(ptr[0]) == 0xEF && uint8_t(ptr[1]) == 0xBB && uint8_t(ptr[2]) == 0xBF) // Skip UTF-8 BOM
		{
			result.resize(static_cast<size_t>(size.QuadPart));
			ptr = result.data();
		}
		else
		{
			ptr += 3;
		}

		if (size.QuadPart != 0)
		{
			ReadFileCheckSize(hFile.get(), ptr, static_cast<DWORD>(size.QuadPart));
		}
	}

	return result;
}
