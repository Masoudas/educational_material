/**
*	-	constexpr std::pair<InputIt1,InputIt2> mismatch( InputIt1 first1, InputIt1 last1, InputIt2 first2 )
*	-	constexpr std::pair<InputIt1,InputIt2> mismatch( InputIt1 first1, InputIt1 last1, InputIt2 first2,
*                 BinaryPredicate p);
*	-	constexpr std::pair<InputIt1,InputIt2> mismatch( InputIt1 first1, InputIt1 last1, InputIt2 first2, 
*				  InputIt2 last2, BinaryPredicate p );
* 
* Returns the first mismatching pair of elements from two ranges: one defined by [first1, last1) and another 
* defined by [first2,last2). If last2 is not provided (overloads (1-4)), it denotes first2 + (last1 - first1).
* 
* Elements are compared either using == or binary operator. If no mismatches are found when the comparison 
* reaches last1 or last2, whichever happens first, the pair holds the end iterator and the corresponding 
* iterator from the other range.
* 
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