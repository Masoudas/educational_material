/**
* As is the case, both the find and contain method can be used to find a key. Note however that there may be
* several instances of a key in a set. 
* 
* Note that count returns how many instances of a particular key exist. The method find returns ONE iterator to
* one of many possiblities of a key. However, the method equal_range returns a list of all iterators whose key
* equals the given value. It returns a pair containing the begin and end iterator.
*/
#include <iostream>
#include <unordered_set>

using std::unordered_multiset;

void finding_a_key_in_a_multiset() {
	unordered_multiset<int> m{};

	m.emplace(5); m.emplace(1); m.emplace(5);

	auto itrs = m.equal_range(5);
	
	for (auto begin = itrs.first; begin != itrs.second; ++begin) {
		std::cout << *begin << '\n';
	}
	
}

//int main() {
//	finding_a_key_in_a_multiset();
//}