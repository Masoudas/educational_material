/**
* Something fundamentally important regarding iterators is that we should pay attention to if the 
* underlying pointer of iterator goes out of scope after deletion of some elements, or possibly addition
* of some elements.
* 
* Example 1: With vector emplace_back, we may regenerate an entirely new underlying array, thus invalidating
* the iterator (note that no deletion occurs here!). 
* 
* Example 2: If we emplace a new element inside the vector, a current reference or pointer may not expire, 
* but it will point to a new element (to say the least). Worst, if array reallocation occurs, the reference
* my become invalid.
* 
* As opposed to vector and array, linked list types are safer for removal and insertion. This is because no
* reallocation occurs. The only situation we really have to be worried about is when we remove an element, and
* then the iterator points to the removed element. 
*/
#include <vector>
#include <list>

using std::vector;

void vector_iterator_invalidation() {
	std::vector<int> vec = { 1, 2, 3, 4, 5 };
	auto it4 = vec.begin() + 4;

	vec.insert(vec.begin() + 2, 0);
	// vec becomes {1, 2, 0, 3, 4, 5}

	// it4 is now invalid. Accessing it has undefined behavior.
}

void list_iterator_invalidation() {
	std::list<int> lst = { 1, 2, 3, 4, 5 };
	auto l_it4 = next(lst.begin(), 4);
	lst.insert(next(lst.begin(), 2), 0);
	// l_it4 remains valid
}