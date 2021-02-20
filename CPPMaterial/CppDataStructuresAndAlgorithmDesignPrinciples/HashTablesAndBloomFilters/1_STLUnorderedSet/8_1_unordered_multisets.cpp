/**
* An important feature of unordered_set is that it does not allow duplicate keys inside the set. This can be
* remedied using unordered_multisets.
* 
* The standard specifies that "Unordered multiset is an associative container that contains set of possibly 
* non-unique objects of type Key. Search, insertion, and removal have average constant-time complexity."
* 
* Internally, the elements are not sorted in any particular order, but organized into buckets. Which bucket an 
* element is placed into depends entirely on the hash of its value. This allows fast access to individual elements, 
* since once hash is computed, it refers to the exact bucket the element is placed into.
* 
* As is the case for a set, iterators of a multiset are unstable. Hence, they can't be compared using a method
* such as equal.
*/
#include <iostream>
#include <unordered_set>

using std::unordered_multiset;

void creating_a_multiset() {
	unordered_multiset<const char*> m{};

	m.emplace("val1");
	m.emplace("val1");
	m.emplace("val2");
	
	for (auto&& val : m) {
		std::cout << val << '\n';
	}
}



