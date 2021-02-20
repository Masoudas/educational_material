/**
* Here's a question: How do we merge two vectors together? Meaning putting v2 at the end of v1?
* 
* We can use the insert method. But we need to allocated new memory to ensure that end is valid and points
* to proper memory location. Therefore, we use reserve() to ensure that v1.size() + v2.size() elements are
* reserved. Note that even though end may appear invalid, it's perfectly fine to use it, and the vector
* increases size for us!
* 
* Some people! tried to first resize and then insert! But those people forgot that insert adds NEW elements
* to the vector (it's not the bracket operator those people!)
*/
#include <vector>
#include <iostream>
#include <algorithm>

void merge_two_vectors() {
	std::vector<int> v1{ 3, 5, 7 };	// Recall that the order of supplied vectors is irrelevant
	std::vector<int> v2{ 1, 2, 4, 6, 8 };

	v1.reserve(v1.size() + v2.size()); // Reserve enough elements first
	v1.insert(v1.begin() + 3, v2.begin(), v2.end());

	std::cout << "Capacity of merged vector is : " << v1.capacity() << '\n';
	std::cout << "Size of merged vector is : " << v1.size() << '\n';

	std::for_each(v1.begin(), v1.end(), [&](const int& v) {std::cout << v << '\t'; });
	std::cout << "\n";
}

//int main() {
//	merge_two_vectors();
//}

