/**
 * Before we forget, a char literal that goes between single quotes like 'a' is of type char.
 * A string literal that goes between "" is a c-string style char. This would imply that it's an array
 * of const chararacters (const char* or const char[]), which terminates in '\0' or all zero char.
 * It's NOT a string class of C++.
 *
 * If we want our string literal to be of type string in std, we have to use the suffix s.
 * 
 * Note that when we write string s = "abc", an implicit conversion takes place.
 *
 * Question: Why does '\0' print a question mark in Windows? Well, the all zero char equals a question mark in Windows
 * char s1 = 0; cout << s1; // would print a question mark.
 * The actual question mark is 63!
 *
 * 
 */
#include <iostream>
using namespace std;
namespace Literals_0 {
	void literals_in_depth() {
		const char* s = "abs";

		if (s[3] == '\0') {
			cout << "A C-Style string ends in: " << (char)'\0' << ". So its length is number of chars plus 1." << endl;
			cout << s << endl;
		}

		auto s_std = "This is an std string"s;
		cout << " Size of string (not c-string) literal is: " << s_std.length() << endl;


		cout << "Printing null char actually prints null in VS 2019: "<< '\0';
	}
}

