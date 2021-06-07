/** 
* count: How many elements are equal to the given value
* count_if: Same, but with a predicate.
* 
* accumulate: Called accumulate and not sum, because accumulates elements of collection into one element. How?
* Can be multiplication, summation, etc. Accepts an initial value, then applies a binary op to all elements of
* a collection, using the initial value, together with each element of the collection. 
* Note on passing lambda: Lambda is f(const T& out, const T& val) or f(string&& out, const string& val). Aside 
* from the order which we should pay attention to, note that the first element is rvalue. Why? Because we don't
* want to copy the out value every time.
* 
* reduce: Same as accumulate, but only parallel (arranges subterms for parallelization). In other words, reduces
* the elements of the collection to one element.
* 
* transform_reduce: Accepts a binray and unary op. Transfroms using unary op and then applies binary op.
* There are several overloads. It also has a version for two collections, which is just inner product, 
* but parallel. The standard says:
*	Return value:
*	2) Generalized sum of init and binary_op2(*first,*first2), binary_op2(*(first+1),*(first2+1)), ..., 
		over binary_op1
	3) Generalized sum of init and unary_op(*first), unary_op(*(first+1)), ... unary_op(*(last-1)) 
		over binary_op,
  Unary operator is never applied to init.
* 
* inner_product: Use transform_reduce!
* 
* !!! NOTE !!! In MSVC, these algorithms are in numeric header.
*/

#include <algorithm>
#include <numeric>
#include <vector>
#include <string>
#include <iostream>
#include <execution>
#include <functional>
#include <iomanip>

using std::vector;
void transform_reduce() {
	vector<int> v{ 1, 2 };
	vector<int> v2{ 1, 2 };

	int inner = 0;
	inner = std::transform_reduce(
		std::execution::par, v.begin(), v.end(), v2.begin(), inner);

	std::cout << "Inner product of two vectors is: " << inner;
}

void more_complicated_transform_reduce() {
	// We intend to produce the accumulative sum of 1/n^2, for n = 1000. 
	// To review everything, we actually do this in two steps.

	// Create a vector of {1,...1000}. We cleverly use the cummulative sum so far to assign.
	vector<double> v(1000, 1);	// Start with a vector of one.
	for (auto begin = v.begin() + 1; begin != v.end(); ++begin)*begin += *(begin - 1);

	// Now, transform each element to 1/n^2, then sum with previous element.
	auto inverse = [](double x) { return 1 / (x * x); };
	
	double sum = 0.0;
	sum = std::transform_reduce(
		v.begin(), v.end(), sum, std::plus<double>{}, inverse);

	std::cout << "pi^2/6 is approximated to 1000 is equivalent to: " << std::setprecision(6) << sum;
}

//int main() {
//	more_complicated_transform_reduce();
//}