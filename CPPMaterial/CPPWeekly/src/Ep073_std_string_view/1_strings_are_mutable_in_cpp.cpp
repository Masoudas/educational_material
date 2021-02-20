/**
* As opposed to modern languages like C# and Java, string class in C++ is mutable. In other words,
* changing an string does not create a new string, it actually changes the underlying string.
* Consequently, repeated long strings take different posititions in the memory, and string class is
* considered slow (relative to const char* for example).
*/

#include <string>
#include <iostream>
using namespace std;

void strings_are_mutable() {
	string str = "My face hurts";

	auto begin = str.begin();
	
	string sub_str = " doesn't";
	str.insert(begin + 7, sub_str.cbegin(), sub_str.cend());
	str.pop_back();
	cout << str;
}

//int main() {
//	strings_are_mutable();
//}