/**
* __cdecl is the default calling convention for C and C++ programs. 
* Because the stack is cleaned up by the caller, it can do vararg functions. 
* The __cdecl calling convention creates larger executables than __stdcall, 
* because it requires each function call to include stack cleanup code. The following list shows the 
* implementation of this calling convention. The __cdecl modifier is Microsoft-specific. 
*/

struct CMyClass {
	void __cdecl mymethod();
};