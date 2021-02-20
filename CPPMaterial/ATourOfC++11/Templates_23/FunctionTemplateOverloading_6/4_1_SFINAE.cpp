/**
* Consider the following template declaration. Note that the second call using pointer fails, because
* Iter::value_type is non-sensical for int* (int*::value_type does not make sense).
*/
#include <vector>
using namespace std;

template<typename Iter>
typename Iter::value_type mean_1(Iter first, Iter last) { 
	return {}; 
}

void making_a_nonsensical_template(vector<int>& v, int* p, int n){
	auto x = mean_1(v.begin(), v.end()); // OK
	// auto y = mean_1(p, p + n); // error.
}