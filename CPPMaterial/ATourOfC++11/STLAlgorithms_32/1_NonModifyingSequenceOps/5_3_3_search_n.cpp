/**
* - constexpr ForwardIt search_n( ForwardIt first, ForwardIt last, Size count, const T& value );
* 
* Searches the range [first, last) for the first sequence of count identical elements, each equal to the given 
* value.
* 
* In the following example, we try and find a sequence of exactly 24 ones for a class C subnet mask!
*/
#include <algorithm>
#include <iostream>
#include <iterator>

void stream_ip(bool* begin, bool* end) {

	std::cout << "Found a class C ip: ";

	std::ostream_iterator<bool> itr{ std::cout, " " };
	std::copy(begin, end, itr);

	std::cout << '\n';
}

void check_subnet_masks() {
	using namespace std;

	bool class_a[32] = { 0,1,1,1,1,1,1,1 };
	bool class_b[32] = { 1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1 };
	bool class_c[32] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 };

	if (std::search_n(cbegin(class_a), cend(class_a), 24, 1) != cend(class_a)) {
		stream_ip(class_a, class_a + 32);
	}
	else if (std::search_n(cbegin(class_b), cend(class_b), 24, 1) != cend(class_b)) {
		stream_ip(class_b, class_b + 32);
	}
	else if (std::search_n(cbegin(class_c), cend(class_c), 24, 1) != cend(class_c)) {
		stream_ip(class_c, class_c + 32);
	}
}

//int main() {
//	check_subnet_masks();
//}