/**
*	template< class ForwardIt, class Generator >
*	-	constexpr void generate( ForwardIt first, ForwardIt last, Generator g ); 
*	Assigns each element in range [first, last) a value generated by the given function object g.
* 
* generator_n does this for exactly n elements.
* 
* Note: This method is perfect for initialization purposes of in particular vectors, as the following example
* demonstrates, using mutable lambdas
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