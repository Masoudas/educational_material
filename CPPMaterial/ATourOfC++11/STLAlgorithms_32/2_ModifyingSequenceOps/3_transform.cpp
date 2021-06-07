/**
* Me: Note that transform can transform one range or two ranges INTO a new range.
* 
*	-	constexpr OutputIt transform( InputIt first1, InputIt last1, OutputIt d_first, 
*			UnaryOperation unary_op ); (1)
*	-	constexpr OutputIt transform( InputIt1 first1, InputIt1 last1, InputIt2 first2,
*			OutputIt d_first, BinaryOperation binary_op );	(3)
* 
* (1)	The unary operation unary_op is applied to the range defined by [first1, last1).
* (3)	The binary operation binary_op is applied to pairs of elements from two ranges: one defined by [first1, last1) and 
*		the other beginning at first2.
* 
* The signature of UnaryOp can be Ret fun(const Type &a); Note also that the possible implemenation of the algorithm is:

template<class InputIt, class OutputIt, class UnaryOperation>
OutputIt transform(InputIt first1, InputIt last1, OutputIt d_first,
				   UnaryOperation unary_op)
{
	while (first1 != last1) {
		*d_first++ = unary_op(*first1++);
	}
	return d_first;
}

* Me: The point I'm making is this. The assignment is after the unary op, and it would be a copy assignment. Hence, even
* if I get the object by reference from the iterator (which I normally do,) I only assign to the iterator once the lambda
* is finished. So, feel free to get by reference, and then return an object. On the other hand, if I return an rvalue,
* it will be moved. The point is that if we don't want any copy to take place, we must use a normal for each, and not a
* transform. On the other hand, if we want to change the type and truly transform one type, or two types, then that's the
* place to use transform.
*/

#include <algorithm>
#include <vector>
#include <string>
#include <functional>
#include <iostream>
#include <execution>

using std::vector;

// Unnecessary use of transform
void getting_the_power_of_a_range() {
	vector<int> v1{ 1, 2, 3, 4 };
	// Involves one additional copy. Not useful.
	std::transform(v1.cbegin(), v1.cend(), v1.begin(), [](const int& val) {return std::pow(2, val); });

	// Better use for each
	std::for_each(v1.begin(), v1.end(), [](auto& v) { v += 2; });

	std::copy(v1.cbegin(), v1.cend(), std::ostream_iterator<int>{std::cout, "\t"});
}

// A possibly good use of transform from standard
void good_uses_of_transform() {
	// Again, possibly it's better to use for_each :D
	std::string s("hello");
	std::transform(s.begin(), s.end(), s.begin(),
		[](unsigned char c) -> unsigned char { return std::toupper(c); });

	std::vector<std::size_t> ordinals;
	std::transform(s.begin(), s.end(), std::back_inserter(ordinals),	// Any thing can be converted to iterators! 
		[](unsigned char c) -> std::size_t { return c; });

	std::cout << s << ':';
	for (auto ord : ordinals) {
		std::cout << ' ' << ord;
	}

	std::transform(ordinals.cbegin(), ordinals.cend(), ordinals.cbegin(),
		ordinals.begin(), std::plus<>{});

	std::cout << '\n';
	for (auto ord : ordinals) {
		std::cout << ord << ' ';
	}
	std::cout << '\n';
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

//int main() {
//	getting_the_power_of_a_range();
//}

