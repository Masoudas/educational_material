/**
* -	inclusive_sum:
*		template< class InputIt, class OutputIt >
*		constexpr OutputIt inclusive_scan( InputIt first, InputIt last, OutputIt d_first );
* assigns through each iterator i in [d_first, d_first + (last - first)) the value of:
* -	the generalized noncommutative sum of *j... for every j in [first, first + (i - d_first + 1)) over binary_op
*	(i.e, the sum of elements including the current index)
* - An option to supply an init value.
* *** Therefore, this is equivalent to partial_sum, but can be run parallel too.
* 
* -	exclusive_sum:
*	same as inclusive sum, except that computes [first, first + (i - d_first)) (i.e, excludes last element).
*	Always requires an init value.
*/

#include <vector>
#include <numeric>
#include <iostream>
#include <execution>
#include <string>

using std::vector;

void inclusive_summation() {
	vector<std::string> v{"This", "is", "c++"};

	std::inclusive_scan(std::execution::par, v.begin(), v.end(), v.begin());
	std::copy(v.cbegin(), v.cend(), std::ostream_iterator<std::string>{std::cout, "\t"});
}

void exclusive_summation() {
	vector<int> v(4, 1);
	auto last = std::exclusive_scan(std::execution::par, v.begin(), v.end(), v.begin(), 0);
	
	std::copy(v.begin(), last, std::ostream_iterator<int>{std::cout, "\t"});
}


//int main() {
//	inclusive_summation();
//	exclusive_summation();
//}