/**
* Relational operators are for comparing two arrays. As of cpp20, only == and <=> remain.
* 
* The <=> operators use lexico_graphical comaprison. They're supposed to say 'axx'< 'bxx'. Therefore, when
* we compare two arrays, if the first unequal element is less, it returns true, otherwise returns false.
* 
* While we're here, the std::lexico_graphical method is used for lexicographical comparison of any two 
* iterators.
*/

#include <array>
#include <iostream>

using std::array;

void comparing_arrays() {
	array<int, 3> arr{ 1, 2, 3 };
	array<int, 3> arr1{ 1, 3, 4, };
	
	array<int, 3> arr2{ };
	arr2 = arr;	// Just checking the copy assignment!

	array<int, 2> arr_dsize{ 5, 4 };

	if (arr < arr1) {	
		std::cout << "Lexicographically, \'arr\' is less than \'arr1\'\n";
	}

	if (arr == arr2) { // Check if every index is unequal
		std::cout << "Every element of arr and arr2 is equal\n";
	}

	if (arr != arr1) {
		std::cout << "Every element of arr is unequal to arr\n";
	}

	// if (arr < arr_dsize) {} Not possible, comparing two different types.
	std::lexicographical_compare(arr.begin(), arr.end(), arr1.begin(), arr1.end());	// Returns true.
}

//int main() {
//	comparing_arrays();
//}