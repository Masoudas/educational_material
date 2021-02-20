/*
* The problem with sorting a c-style string is that we can't tamper with an array of constants.
* The only solution that comes to mind is to use an array of chars. Hence, it seems we need a copy.
* Note also that with sort, we're not sorting the termination null char.
*/

#include <algorithm>
#include <iostream>
using namespace std;

void sort_cstyle_string_using_sort() {
	const char* s = "cda";
	//sort(const_cast<char*>(s), const_cast<char*>(s) + 3); //This is not possible. const_cast can only give pointer to
	// to the first location, not the rest.

	char c[4];
	strcpy_s(c, s);
	sort(c, c + 3);
	s = c;	// This is fine, s is not constant, but pointer to const.
	cout << s << endl;
	
}

void sort_cstyle_string_using_qsort() {
	const char* s = "cda";
	char c[4];
	strcpy_s(c, s);

	auto compare = [](const void* a1, const void* a2) ->int {
		const char c1 = *(const char*)a1;
		const char c2 = *(const char*)a2;

		if (c1 == c2) return 0;
		else if (c1 < c2) return -1;
		else return 1;
	};

	qsort(c, 3, sizeof(char), compare);
	s = c;
	cout << s;
}

//int main() {
//	sort_cstyle_string_using_sort();
//	sort_cstyle_string_using_qsort();
//}