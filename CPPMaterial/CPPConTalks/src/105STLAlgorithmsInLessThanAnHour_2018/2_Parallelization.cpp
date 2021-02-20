/**
* As it appears, many of the algorithms can also be executed in parallel. For doing so, we need to supply an
* rvalue function from the 'execution' header. For example, in the following, we perform is sorted using
* parallel execution policy
*/

#include <execution>
#include <algorithm>
#include <vector>

void parallelization_of_checking_for_sorted() {
	std::vector<int> v{ 1, 2, 3, 4 };

	bool is_sorted = std::is_sorted(std::execution::par, v.begin(), v.end());
}