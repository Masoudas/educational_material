/**
* So it occured to me that I've rarely thought about the copy assignment. The copy assignment has
* a couple of overloads in the class. The most important one (as always) gives a const reference and then 
* copies that list. Another overload, takes an initializer_list and copies that.
* 
* Here's a thought: When we copy a vector, what happens to the pointer of the old list? Well, it gets destroyed.
* In fact, if we look inside the initializer_list overload, we see a call to a destroyer. Therefore, when implement
* such data structures, we should be cautious as to destroy the old data too.
*/

#include <vector>

void copy_assigning_another_vector() {
	std::vector<int> v1{ 1, 2, 3 };
	std::vector<int> v2{ 4, 5, 6 };

	v2 = v1;	// A normal copy assignment.
}

void copy_assigning_an_initializer_list() {
	std::vector<int> v1{ 1, 2, 3 };

	v1 = { 4, 5 , 6 };	// operator = is called with the initializer list overload.
}