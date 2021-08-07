#pragma once

void* ryml_allocate(size_t size, void* /*hint*/, void* /*user_data*/)
{
	return operator new(size);
}

void ryml_free(void* mem, size_t size, void* /*user_data*/)
{
	operator delete(mem, size);
}

struct ryml_exception : std::runtime_error
{
	explicit ryml_exception(const char* msg) : runtime_error(msg) {}
};

[[noreturn]] void ryml_error(const char* msg, size_t /*msg_len*/, ryml::Location /*location*/, void* /*user_data*/)
{
	throw ryml_exception(msg);
}

void SetRymlCallbacks()
{
	ryml::set_callbacks({ nullptr, ryml_allocate, ryml_free, ryml_error });
}
