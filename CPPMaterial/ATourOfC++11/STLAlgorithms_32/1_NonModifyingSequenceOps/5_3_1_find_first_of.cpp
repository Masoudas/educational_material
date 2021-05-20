/**
*   -	constexpr InputIt find_first_of( InputIt first, InputIt last, ForwardIt s_first, ForwardIt s_last );
*	-	constexpr InputIt find_first_of( InputIt first, InputIt last, ForwardIt s_first, ForwardIt s_last, 
*			BinaryPredicate p );
* 
* Searches the range [first, last) for any of the elements in the range [s_first, s_last). Otherwise, it's the
* same as a normal find.
* 
* Note that copy_n copies exactly n values from the beginning.
*/

#include <algorithm>
#include <string>
#include <vector>

void search_for_eligbles() {
	using namespace std;

	vector<string> names{ "Masoud", "Morteza", "Hamed", "Maman", "Baba" };
	vector<string> eligbles{ "Asghar", "Akbar", "Masoud", "Baba" };

	auto first = find_first_of(names.begin(), names.end(), eligbles.begin(), eligbles.end());
}