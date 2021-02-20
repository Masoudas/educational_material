/**
* As is the case with numeric queries, we can add a transform to the beginning of the inclusive_sum or
* exclusive_sum to transform each element before we apply the commulative sum.
*/
#include <numeric>
#include <vector>
#include <cmath>
#include <iostream>

using std::vector;

void transform_inclusive_sum() {
	vector<int> v(4, 1);

	auto pow2 = [](const int v) {return std::pow(2, v); };

	std::transform_inclusive_scan(v.cbegin(), v.cend(), v.begin(), std::multiplies<>{}, pow2);
	std::copy(v.cbegin(), v.cend(), std::ostream_iterator<int>{std::cout, "\t"});
}

//int main() {
//	transform_inclusive_sum();
//}