/**
*	-	constexpr OutputIt transform( InputIt first1, InputIt last1, OutputIt d_first, 
*			UnaryOperation unary_op );
*	-	constexpr OutputIt transform( InputIt1 first1, InputIt1 last1, InputIt2 first2,
*			OutputIt d_first, BinaryOperation binary_op );
* 
* Transform: applies the given function to a range and stores the result. This method is perfect for transforming
* the elements of a range.
* 
* The binary operation binary_op is applied to pairs of elements from two ranges: one defined by 
* [first1, last1) and the other beginning at first2. 
*/

#include <algorithm>
#include <vector>
#include <string>
#include <functional>
#include <iostream>
#include <execution>

using std::vector;

void getting_the_power_of_a_range() {
	vector<int> v1{ 1, 2, 3, 4 };
	std::transform(v1.cbegin(), v1.cend(), v1.begin(), [](const int& val) {return std::pow(2, val); });

	std::copy(v1.cbegin(), v1.cend(), std::ostream_iterator<int>{std::cout, "\t"});
}

void multiplying_two_vectors() {
	// In this example, we intend to put the product of two vectors into another.
	vector<int> v1{ 1, 2, 3, 4 };
	vector<int> v2{ 1, 2, 3, 4 };
	vector<int> v3(4, 1);

	// We pass three iterators, with out being the one we want to put the result in.
	std::transform(
		std::execution::par, v1.cbegin(), v1.cend(), v2.cbegin(), v3.begin(), std::multiplies<int>{});

	std::copy(v3.cbegin(), v3.cend(), std::ostream_iterator<int>{std::cout, "\t"});
}

void string_to_uppercase() {
	std::string str = "Yo man";

	std::transform(
		str.cbegin(), str.cend(), str.begin(), 
		[](const unsigned  c)->unsigned char {return std::toupper(c); }
	);

	std::cout << "Upper version of the string is: " << str;
}

//int main() {
//	getting_the_power_of_a_range();
//}

