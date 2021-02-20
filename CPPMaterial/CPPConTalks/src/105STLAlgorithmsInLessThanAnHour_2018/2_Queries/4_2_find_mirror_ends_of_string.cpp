/**
* Imagine an string, being mirrored from beginning and end, as abcXWTcba. Find and print the mirror string.
* 
* Answer: Again, mismatch can be used using a reverse iterator to determine the portion of the string equal.
* Moreover, the constructor of an string accepts an iterator for creating the string.
*/

#include <string>
#include <algorithm>
#include <iostream>

std::string find_mirror_string(const std::string& str) {
	auto last = std::mismatch(str.cbegin(), str.cend(), str.crbegin());
	return std::string{ str.cbegin(), last.first};
}

//int main() {
//	std::cout << find_mirror_string("abcXYZcba") << '\n';
//	std::cout << find_mirror_string("XYZ") << '\n';
//	std::cout << find_mirror_string("123XYZ321") << '\n';
//}