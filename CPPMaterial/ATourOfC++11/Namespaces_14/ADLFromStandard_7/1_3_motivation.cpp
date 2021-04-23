/**
* The third motivation is of course the one I wasn't paying attention to this whole time. I needn't qualify 
* std functions with std arguments every single time. I could just use them, without even having to include
* them!
*/

#include <vector>

void use_functions_without_name_qualification() {
	std::vector<int> v{  };

	auto begin_itr = begin(v);	// Get a begin itr.
	advance(begin_itr, 2);
	auto n_itr = next(begin_itr);

	// for_each(begin_itr, n_itr, [](auto& val) {val++; }); This one is not possible :D Because for each has
															// no overload for vector iterator!
}