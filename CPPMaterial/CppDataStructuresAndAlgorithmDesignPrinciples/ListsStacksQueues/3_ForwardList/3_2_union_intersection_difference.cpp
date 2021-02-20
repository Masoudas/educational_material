/**
* The algorithm header as it happens provides fascilites for creating the difference, union, and intesection of sets. Note 
* however that these methods are not useful for computing the intersection of a set, as they require both collections to
* be sorted. 
* 
* As people over the interned have pointed out, the only solution (which is actually an optimal solution) is to simply
* iterate through the set and insert it in the new set. For example, for union, a simple insertion suffices. For intersection,
* we need to check the existence of the element in the other set. 
* 
* Don't merge for union son!
*/
#include <unordered_set>
#include <algorithm>

void union_of_u_sets() {
	std::unordered_set<int> s{ 1, 2, 3, 4 };
	std::unordered_set<int> s1{ 5, 6, 7 };

	for (auto& elem : s1) {
		s.insert(elem);
	}
}

void intersection_of_u_sets() {
	std::unordered_set<int> s{ 1, 2, 3, 4 };
	std::unordered_set<int> s1{ 2, 0 };

	std::unordered_set<int> intersection{};

	for (auto& elem : s1) {
		if (s.contains(elem)) intersection.insert(elem);
	}
}