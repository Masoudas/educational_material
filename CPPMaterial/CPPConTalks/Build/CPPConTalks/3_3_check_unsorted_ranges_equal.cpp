/**
* Question: How can we we check if two unsorted collections are equal? 
* 
* At least three solutions come to mind:
* 1- Sort the collection, then compare range.
* 2- Heapify the collection (if possible), then pop and compare.
* 3- Use a hash table and then compare the two.
* 
* Of course except for the first solution, we should check that the two ranges have the same number of elements.
*/
#include <vector>
#include <list>
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <numeric>

void check_unsorted_ranges_equal() {
	std::vector<int> v1{ 1, 3, 2 };
	std::vector<int> v2{ 2, 1, 3 };

	if (v1.size() != v2.size()) std::cout << "unequal";

	std::make_heap(v1.begin(), v1.end());
	std::make_heap(v2.begin(), v2.end());

	int ctr = 0;
	while (++ctr <= v1.size()) {
		if (v1[0] != v2[0]) { std::cout << "unequal"; break; }

		std::pop_heap(v1.begin(), v1.end());
		std::pop_heap(v2.begin(), v2.end());
	}
}

void check_unordered_lists_equal() {
	std::list<int> v1{ 1, 3, 2 };
	std::list<int> v2{ 2, 1, 3 };

	std::unordered_map<int, int> map;

	for (auto& elem : v1) map[elem]++;
	for (auto& elem : v1) map[elem]--;

	std::all_of(map.cbegin(), map.cend(), [](auto pair) {return pair.second == 0; });

}