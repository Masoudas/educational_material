/**
* Find finds the first position where a substring occurs
* 
* string::find(const string& str, size_t pos) returns (in size_t) the first position where str occurs in string.
* Note that as expected, this method returns the exact (first) occurance of the string. Also, if it can't find
* a position, it returns npos, and if str is zero length, returns current position.
*/
#include <string_view>
#include <iostream>

void find_all_instance_index() {
	using std::string_view;
	string_view str = "az/az/az/az/az/";

	size_t start = 0;
	while (true) {
		start = str.find('w', ++start);

		if (start == string_view::npos) return;
		std::cout << start << '\t';
	}
}

//int main() {
//	find_all_instance_index();
//}