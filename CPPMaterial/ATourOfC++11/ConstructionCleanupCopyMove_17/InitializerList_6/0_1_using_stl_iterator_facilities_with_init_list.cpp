/**
* Don't forget to use stl facilities such as std::advance, std::next, std::prev, str::rbegin and
* std::rend to fasciliate working with initializer_lists. Particularly, rbegin and rend are interesting,
* because they allow us to reverse iterate over a list, with INCREMENT! Cuol! All these babies are in
* the iterator header.
*/

#include <initializer_list>
#include <iterator>
#include <iostream>

using std::initializer_list;

void reverse_iterating_initializer_list(initializer_list<int> list) {
	for (auto it = std::rbegin(list); it != std::rend(list); it++){
		std::cout << *it << '\t';
	}
}