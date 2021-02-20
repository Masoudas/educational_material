/**
* Apparently, the best libarary method to generate a vector, where each one has a value set by a function
* is std::generate. See the following examples on how to generate a vector from 0 to N-1. Particularly,
* notice how we pass the parameter to lambda
* 
*/
#include <vector>
#include <algorithm>

void generate_increasing_vector() {
	std::vector<int> v(5);

	auto generator = [i = 0]()mutable{ return i++; };
	std::generate(v.begin(), v.end(), generator);

	auto generator1 = [i = 0]()mutable{ return i*=2; };
	std::generate(v.begin(), v.end(), generator1);
}