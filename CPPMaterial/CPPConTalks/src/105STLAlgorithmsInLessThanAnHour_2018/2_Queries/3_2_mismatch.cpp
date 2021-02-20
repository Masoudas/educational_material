/**
* Mismatch compares two vectors to one another, and then returns a pair of iterators to unequal elements
* (for example, returns end if two vectors are equal). 
* If no mismatches are found when the comparison reaches last1 or last2, whichever happens first, the pair 
* holds the end iterator and the corresponding iterator from the other range.
* 
* So something to note: When we say two equal ranges, we're talking about operator == being satisfied. So
* for example {1, 1, 1, 2, 2, 2} is equal to {1, 1, 1, 2, 2, 2} for all elements, and not just till the first
* 2 (where elements change). So we should be cautious not to use this operator for finding where one range 
* changes value.
*/

#include <vector>
#include <algorithm>
#include <iostream>

using std::vector;

void find_all_mismatches() {
	vector<int> v{ 1, 1, 1, 4, 3, 3, 3, 8 };
	vector<int> v1{ 1, 1, 1, 2, 3, 3, 3, 1  };

	auto first_range = std::mismatch(v.cbegin(), v.cend(), v1.cbegin());

	std::cout << "First unequal element in range one is " << *first_range.first << " and in range two is "
		<< *first_range.second;

	// Now, move one past the first unequal element, or else it returns the same iterator!
	auto second_range = std::mismatch(first_range.first + 1, v.cend() , first_range.second + 1);

	std::cout << "\nSecond unequal element in range one is " << *second_range.first << " and in range two is "
		<< *second_range.second;

}

//int main() {
//	find_all_mismatches();
//}