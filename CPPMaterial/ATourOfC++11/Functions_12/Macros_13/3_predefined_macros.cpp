/*
* __cdecl is the default calling convention for C and C++ programs. Because the stack is 
* cleaned up by the caller, it can do vararg functions. The __cdecl calling convention creates 
* larger executables than __stdcall, because it requires each function call to include stack cleanup code
*/

struct CMyClass {
	void __cdecl mymethod();
};

void __cdecl CMyClass::mymethod() { return; }	// We can also omit __cdecl

/* Here, the compiler is instructed to use C style name to call system function*/

// Example of the __cdecl keyword on function
int __cdecl system(const char*);
// Example of the __cdecl keyword on function pointer
//typedef BOOL(__cdecl* funcname_ptr)(void* arg1, const char* arg2, DWORD flags, ...);