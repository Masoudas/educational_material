/**
* Finds the first character equal to one of the characters in the given character sequence. 
* The search considers only the interval [pos, size()). If the character is not present in the interval, 
* npos will be returned.
* 
* For example, in the following bz has z appeared in azimuth, and it will be returned.
* 
* Similarly, find_first_not_of finds the first position that has nothing in common with the given string.
* Finally a similair method exists with last for finding the position from the end of the string.
*/

#include <string_view>
#include <iostream>

void find_first_of() {
	using std::string_view;
	string_view str = "az azimuth";

	auto index = str.find_first_of("bz");
	std::cout << str.substr(index, 10)<< '\n';

	index = str.find_first_not_of("a zi");
	std::cout << str.substr(index, 10) << '\n';

}

//wint main() {
//	find_first_of();
//}
