/**
* As is the case for sets, a multimap can keep equivalent keys in a map. Therefore, as opposed to a map where
* reassigning a key there replaces a value, with a multimap reassigning a key creates a duplicate key.
* 
* The standard says "Unordered multimap is an unordered associative container that supports equivalent keys 
* (an unordered_multimap may contain multiple copies of each key value) and that associates values of another type 
* with the keys. The unordered_multimap class supports forward iterators. Search, insertion, and removal have 
* average constant-time complexity.
* 
* Naturally, there's no bracket operator associated with this map, because there may not be a unique key. 
* Therefore, we need to directly use insert and find methods.
*/
#include <iostream>
#include <unordered_map>

using std::unordered_multimap;

void creating_a_multimap() {
	unordered_multimap<const char*, int> m{};
	
	m.emplace("val1", 1);
	m.emplace("val2", 2);
	m.emplace("val1", 3);

	for (auto&& [key, value] : m) {
		std::cout << key << '\t' << value << '\n';
	}	
}

//int main() {
//	creating_a_multimap();
//}