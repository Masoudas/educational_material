/**
* Partioning algorithms are used for partioning a container using a predicate, and then placing the elements
* that satisfy the predicate to the left, and the ones that don't on the right.
* 
* 1- partition: partitions based on a predicate, and returns the end ptr (iterator to one after that satisfies
*	the partition. Once again, note that the partitioned elements are pushed to left.
*	To repetitvely partition, we can use this ptr and start partitioning from there, using a new predicate.
* 
* 2- stable_partition: Partitions a container, keeping the order of the elements.
* 
* 3- partition_point: For a partitioned collection, returns the partition_end. In other words, returns the first
* element that is not partitioned.
* 
* Note: One thing that we should not forget is that partitioning is not equivalent to the partition step of the
* quicksort algorithm. In fact, no assumption should be made about the iterator returned by this method. For
* example, for [2, 1, 3], if the predicate is x < 2, we can't assume that 2 would be at position 1, and this is
* what the returned iterator points to!
*/

#include <algorithm>
#include <vector>
#include <sstream>
#include <iostream>

void partition_vector() {
	std::vector<int> v1{ 3, 2, 7, 5, 1 , 3, 4, 5, 6, 7 };
	auto less_than_three = std::partition(v1.begin(), v1.end(), [](const int& elem) {return elem < 3; });
	auto less_than_five = std::partition(less_than_three, v1.end(), [](const int& elem) {return elem < 5; });

	std::ostringstream o{};
	o << "The elements that are less than three: \n";
	std::for_each(v1.begin(), less_than_three, [&](int v) {o << v << '\t'; });

	o << "\nThe elements that are less than five are: \n";
	std::for_each(less_than_three, less_than_five, [&](int v) {o << v << '\t'; });
	std::cout << o.str();
}

void partition_end() {
	std::vector<int> v1{ 3, 2, 7, 5, 1 , 3, 4, 5, 6, 7 };
	std::partition(v1.begin(), v1.end(), [](const int& elem) {return elem % 2 == 0; });

	auto end_partition = std::partition_point(v1.begin(), v1.end(), [](const int& elem) {return elem % 2 == 0; });

	std::ostringstream o{};
	o << "The elements that are less than three: \n";
	std::for_each(v1.begin(), end_partition, [&](int v) {o << v << '\t'; });

	std::cout << o.str();
}

//int main() {
//	partition_end();
//}