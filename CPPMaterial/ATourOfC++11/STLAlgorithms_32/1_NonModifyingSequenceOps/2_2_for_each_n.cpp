/**
* Essentially, as we may recall, _n algorithms are for applying the algorithm to n values. So here, it would
* be [begin, begin + n). Like always, begin + n is excluded. Also, notice that these babies return an iterator
* as opposed to the function. The iterator is begin + n.
* 
*	-	constexpr InputIt for_each_n( InputIt first, Size n, UnaryFunction f );
*	-	ForwardIt for_each_n( ExecutionPolicy&& policy, ForwardIt first, Size n, UnaryFunction2 f );
*/

#include <algorithm>

void for_each_n_example(int* begin, int n) {
	auto n_minus_two = std::for_each_n(begin, n - 2, [](int& v) { v++; });
}