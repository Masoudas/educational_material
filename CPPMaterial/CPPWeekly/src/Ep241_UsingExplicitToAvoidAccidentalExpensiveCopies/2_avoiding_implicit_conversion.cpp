/**
* For build-in types, we can avoid narrowing implicit conversion using {}.
* 
* For user-defined types, we have to use the keyword explicit to avoid implicit conversion. If explicit
* conversion is specified, then we can't instantiate an object by implicit type conversion, and we have to
* use X{} notation only, and can't use = in initialization;
* 
* Note that any constructor can be called explicit, including copy and move constructor.
*/
#include <utility>

struct string {
	explicit string(const char* s){}
	explicit string(const string& ref) {}
	explicit string(string&& ref) noexcept {}
};

void using_explicit_string_construction() {
	string s{ "My My" };
	//string s = "My My"; This is impossible.
	
	string s1{ s };	// Ok
	// string s1 = s; This is impossible.

	// string s2 = std::move(s); Nope! Can't assign the rvalue reference directly.
	// string s2 = string{ std::move(s) };	Nope! Because right hand side is a temp (rvalue object), and we said
										// to explicitly use the move constructor
	string s2{ std::move(s1) };	// Now. it's fine
}