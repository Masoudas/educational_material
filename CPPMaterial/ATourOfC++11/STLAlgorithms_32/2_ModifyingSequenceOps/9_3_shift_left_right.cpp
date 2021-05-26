/**
* Note that these algorithms are added from C++20. Essentially, note that shift occurs by moving elements.
* Hence, if done on built-in type, copy equals move ({1, 2, 3} becomes {1, 1, 2}), and on custom types, the
* behavior depends on the type (for strings {"1", "2", "3"} becomes {"", "1", "2"}):
* 
* constexpr ForwardIt shift_left( ForwardIt first, ForwardIt last,
*           typename std::iterator_traits<ForwardIt>::difference_type n );  (1)
* constexpr ForwardIt shift_right( ForwardIt first, ForwardIt last, 
*           typename std::iterator_traits<ForwardIt>::difference_type n );  (3)
* 
* Shifts the elements in the range [first, last) by n positions. 
*	(1) Shifts the elements towards the beginning of the range. If n == 0 || n >= last - first, there are no 
*	effects. If n < 0, the behavior is undefined. Otherwise, for every integer i in [0, last - first - n), 
*	moves the element originally at position first + n + i to position first + i. The moves are performed in 
*	increasing order of i starting from ​0​.
*	(3) Shifts the elements towards the end of the range. If n == 0 || n >= last - first, there are no 
*	effects. If n < 0, the behavior is undefined. Otherwise, for every integer i in [0, last - first - n), 
*	moves the element originally at position first + i to position first + n + i. If ForwardIt meets the 
*	LegacyBidirectionalIterator requirements, then the moves are performed in decreasing order of i starting 
*	from last - first - n - 1.
* 
* Me: The algorithm is very simple. For right shift, we start from the back and move. For left shift, we do
* the reverse.
*/

#include <algorithm>
#include <iterator>
#include <iostream>
#include <string>
#include <vector>

void shift_built_in() {
	int arr[] = { 1, 2, 3 };
	std::shift_right(arr, arr + 3, 1);

	std::ostream_iterator<int> o{ std::cout, "\t" };
	std::copy(arr, arr + 3, o);
}

void shift_custom_type() {
	using namespace std;
	vector<string> v{"Shifting", "Left", "Prints", "Null", "For", "Last"};
	
	std::shift_left(v.begin(), v.end(), 1);

	std::ostream_iterator<string> o{ std::cout, "\t" };
	std::copy(v.cbegin(), v.cend(), o);
}

//int main() {
//	shift_custom_type();
//}
