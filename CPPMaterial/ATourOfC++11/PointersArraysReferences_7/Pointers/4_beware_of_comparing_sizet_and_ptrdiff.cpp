/**
* Like comparing any two unsigned and signed types, comparing size_t and ptrdiff_t may lead to 
* catastrophic consequences, as one is unsigned. 
* 
* When will this happen in practice? See the example below, and remeber to use sizeof carefully when
* it comes to checking for array size.
* 
* Especially, be aware of this fact when you use auto!
* 
* C++20 has moved towards representing size as signed value, they have a ssize method for returning size
* as signed value.
*/
#include <cstdint>
#include <string>
using namespace std;
void parsing_a_text_document() {
	char buffer[64];
	const char* field = "Something";
	const char* field_end = 4 + field;	// Imagine a function finding the location of h.

	ptrdiff_t length = field_end - field;
	auto len = field_end - field;	// Do you remember the type?!

	if (length < sizeof(buffer)) {	// Oops! comparing signed with unsigned,

	}



}

