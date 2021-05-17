/**
* ranges::all_of, ranges::none_of, ranges::any_of:
* 
* It's the same as none range version, with the only difference being it accepts a projection method which
* is applied before the unary predicate. It also directly accepts a container.
* It uses concepts in C++20 to accept only the container.
*/

#include <vector>
#include <algorithm>
#include <functional>
#include <ranges>

void ranges_all_of() {
	std::vector<int> v{ 0, 2, 4, 6 };
	std::ranges::all_of(v, std::bind(std::modulus<int>{}, std::placeholders::_1, 2));

}