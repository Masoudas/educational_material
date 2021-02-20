/**
* Just like rbegin(), rfind means reverse_find, and it starts looking for the first occurance of a string or
* const char* from the back of a string.
* 
* Naturally, this one returns -1 when it goes beyond string, but because -1 is the same as npos (unsigned values),
* we again compare with npos.
*/
#include <string_view>
#include <iostream>

void find_all_instances_reverse() {
	using std::string_view;
	string_view str = "az/az/az/az/az/";

	size_t start = str.size();
	while (true) {
		start = str.rfind('z', --start);

		if (start == std::string::npos) return;
		std::cout << start << '\t';
	}
}

//int main() {
//	find_all_instances_reverse();
//}