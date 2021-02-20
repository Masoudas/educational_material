/**
* We can use auto after type deduction. 
* 
* If we need to create an object of a deduced type, we can often do that by calling a function 
* to do the deduction (and creation). For example, consider a simple variant of the standard library’s make_pair()
*/
#include <utility>
#include <string>


template<typename T1, typename T2>
std::pair<T1, T2> make_pair1(T1 a, T2 b)
{
	return { a, b };
}

void creating_pairs_by_taking_advantage_of_type_deduction() {
	auto x = make_pair1(1, 2); // x is a pair<int,int>
	auto y = make_pair1(std::string{ "New York" }, 7.7); // y is a pair<string,double> . 

	auto w = make_pair(std::string{ "New York" }, 7.7);	// make_pair is not in the std name space?!!!
	std::make_pair(std::string{ "New York" }, 7.7);
}

