/*
* Question: Find (the index of) all unique keys in an array using heaps? So for a vector
* like [1, 5, 1, 0] it should return 2 and 4, and for [1, 1, 2, 2] is should return nothing.
* (Note: A more prominent solution to this problem is to use hastables. Seriously, use hash tables).
* 
* Answer: Create an index vector equivalent to the original vector size, and heapify it, based on the corresponding
* value of each index in the original vector.
* 
* Now, in a loop, pop until an unequivalent element is observed. If the number of pops is zero before seeing
* an unequivalent key, then that key is unique.
* 
* Note that the extra space of keeping the index can be erradicated if we only require to return the value,
* rather than the index.
* 
* Note that if we wanted non-unique keys, we just need to change the condition. 
* 
* The cost of this algorithm is equivalent to cost of a sort, because we're sorting in a way, which makes
* me wonder what if we used entropy optimal sort and a linear traverse perhaps!
*/
#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <unordered_map>

void finding_unique_keys(int* begin, int* end) {
	int n = std::distance(begin, end);

	std::vector<int> index(n, 1);
	std::partial_sort(index.begin(), index.end(), index.begin());

	auto cp = [&](int left, int right) {return begin[left] < begin[right]; };
	std::make_heap(index.begin(), index.end(), cp);

	while (n > 0) {
		std::pop_heap(index.begin(), index.begin() + n--, cp);

		int k = 0;
		while (n > 0 && begin[index[n]] == begin[index[0]]) {
			k++;
			std::pop_heap(index.begin(), index.begin() + n--, cp);
		}

		if (k == 0) {
			std::cout << "unique key: " << index[n] + 1 << '\n';
		}
	}
}

void finding_unique_keys_using_hash_tables(int* begin, int* end) {
	int n = std::distance(begin, end);
	std::unordered_map<int, int> map{};

	for (int k = 0; k < n; k++) {
		map[begin[n]]++;
	}

	for (const auto& pair : map) {
		if (pair.second == 1) {
			std::cout << "unique key: " << pair.first << '\n';
		}
	}
}