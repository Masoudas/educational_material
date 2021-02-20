/**
* These are three very cool and useful algorithms:
* 
* 1- nth element: Sort only the n-th element, and put it in its place (probably uses something like pivot
* sort, or I read somewhere a combination of median of median and pivot sort)
* 
* 2- partial sort: Sort up until some particular index (probably uses heap sort). Note that (begin, mid, end),
* and mid itself is not sorted (imagine mid = end, it would sort the entire list, hence mid is not sorted itself).
* 
* 3- in place merge: This is the merge step of the merge sort. Sometimes, we have to sorted sub-containers,
* and we just want to merge them together, and leave the merged array sorted. This is what this algorithm
* does for us. Note that it accepts iterators over one vector. Therefore, we need to put one container at 
* the end of another if we want to merge two vectors. Note also that this is in place merge, meaning no extra
* memory is used for merge. Again, note that mid is exclusive.
* 
* Unfortunately none of these work with lists, because list don't have plus integer iterator operators.
*/

#include <algorithm>
#include <vector>
#include <sstream>
#include <iostream>

void nth_element_sort() {
	std::vector<int> v{ 4, 2, 3, 5, 6 };

	std::nth_element(v.begin(), v.begin() + 2, v.end());	// Find the third element

	std::cout << "The third element of the list is: " << *(v.begin() + 2);
}

void partial_sort() {
	std::vector<int> v{ 6, 4, 2, 3, 5 };

	std::partial_sort(v.begin(), v.begin() + 2, v.end());	// Sort from first to third exclusive.

	std::ostringstream o{};
	o << "Vector sorted excluding third element is \n";
	std::for_each(v.begin(), v.end(), [&](const int& v) {o << v << '\t'; });

	std::cout << o.str();
}

// Merging two sorted vectors
void inplace_merge() {
	std::vector<int> v1{ 3, 5, 7 };	// Recall that the order of supplied vectors is irrelevant
	std::vector<int> v2{ 1, 2, 4, 6, 8 };

	v1.reserve(v1.size() + v2.size()); // Reserve these elements, making end available for insertion.
	v1.insert(v1.begin() + 3, v2.begin(), v2.end());
	v1.shrink_to_fit();		// Yeah, why not!

	std::inplace_merge(v1.begin(), v1.begin() + 3, v1.end());

	std::ostringstream o{};
	o << "The merge result of two already sorted vectors is \n";
	std::for_each(v1.begin(), v1.end(), [&](const int& v) {o << v << '\t'; });

	std::cout << o.str();
}

//int main() {
//	inplace_merge();
//}