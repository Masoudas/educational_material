/**
* Most algorithms have overloads that accept execution policies. The standard library algorithms support 
* several execution policies, and the library provides corresponding execution policy types and objects. Users 
* may select an execution policy statically by invoking a parallel algorithm with an execution policy object 
* of the corresponding type.
* 
* Standard library implementations (but not the users) may define additional execution policies as an 
* extension. The semantics of parallel algorithms invoked with an execution policy object of 
* implementation-defined type is implementation-defined.
* 
* Parallel version of algorithms (except for std::for_each and std::for_each_n) are allowed to make arbitrary 
* copies of elements from ranges, as long as both std::is_trivially_copy_constructible_v<T> and 
* std::is_trivially_destructible_v<T> are true, where T is the type of elements.
*/

#include <execution>
#include <algorithm>
#include <vector>

void parallelization_of_checking_for_sorted() {
	std::vector<int> v{ 1, 2, 3, 4 };

	bool is_sorted = std::is_sorted(std::execution::par, v.begin(), v.end());
}