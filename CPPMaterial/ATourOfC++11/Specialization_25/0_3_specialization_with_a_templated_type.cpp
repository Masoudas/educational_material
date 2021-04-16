/**
* Recall that we specialized for general pointers, we wrote 

template<typename T>
struct S<T*>{}

* and we concluded T itself is not a pointer, but rather the type behind the pointer. In the same manner, if the type 
* we're specializing to is itself templated, we essentially use the same syntax. Note once again that the template parameter
* is the template of the template, not the template itself. For example below, T is char, and not basic_string. Moreover,
* when we construct the class with basic string, the user of the class sees the template as string, and not char. That is,
* we can't say s_specializer<string> and then assign it to s_specialier<char>.
* 
* One final note is that the template of string is char and not const char*. This gave me a bit of headache, because for
* one second, I saw that the consruction as s_specializer("aaa") was using the basic_string constructor, until I remembered
* T here is char, and not const char!
*/
#include <string>
#include <iostream>

template<typename T>
struct s_specializer{};

template<typename T>
struct s_specializer<std::basic_string<T>> {
	using type = T;
	s_specializer(T) { std::cout << "inside char constructor\n"; }	// This would be a char specialization
	s_specializer(std::basic_string<T>) { std::cout << "Inside basic_string specialization\n"; } // The string specialization
};

void instantiating_s_specializer() {
	s_specializer<std::string> s3{ 'a' };
	s_specializer<std::string>::type s2 = 'a';	// s2 is a char type. Also notice that we didn't precede this
						// expression with typename, because we're not using a template as template argument,
						// rather the type is concrete.
	
	s_specializer<std::string> s{ "aaa" };	// Uses basic string, because there's no const char* constructor!
	s_specializer<std::string> s1{ std::string("aaa") };
}

//int main() {
//	instantiating_s_specializer();
//}