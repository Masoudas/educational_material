/**
* vector provides three methods concerning resizing the array:
* 
* ** clear(): Simply removes the underlying array. After this call, size() returns zero. Leaves the 
*	capacity() of the vector unchanged
* 
* ** reserve(): This function is used to specify the capacity of the vector. If the value specified as 
*	the parameter is greater than the current capacity, it reallocates memory and the new capacity will 
*	be equal to the parameter. However, for all other cases, it will not affect the vector's capacity. 
*	This function doesn't modify the size of the vector
* 
* ** shrink_to_fit(): This function can be used to free up the extra space. After calling this function, 
*	size and capacity become equal. This function can be used when we are not expecting a further increase 
*	in the size of the vector.
* 
* ** resize(): Resizes the container to contain count elements. If the current size is greater than count, 
*	the container is reduced to its first count elements. If the current size is less than count:
*		1) additional default-inserted elements are appended (Me: so there must be a default constructor).
*		2) additional copies of value are appended. (Me: if not, then values are copied?)
* 
* Me:
* Note that the end iterator does not depend on how much space is reserved. So long as the size method
* does not go there, end is the element right after size. Note however end is valid now (and points to 
* a reserved element on the vector) and we can use it. Note that end would always be valid after this 
* operation, even if reserve does not allocate new memory (because this would imply that memory was
* available for us).
* 
* Now consider resizing. Resizing in fact increases the size of vector. So end changes. The point is that
* at least with MSVC, the size increased more than what I ask! This is most likely due to the memory allocation
* algorithms
*/

#include <vector>
#include <iostream>
#include <algorithm>

void resizing_increases_num_elements_and_changes_end() {
	std::vector<int> v{ 1, 2, 3 };
	v.resize(v.size() + 5);

	std::cout << "Size of resized vector is : " << v.size() << '\n';
	std::for_each(v.begin(), v.end(), [&](const int& v) {std::cout << v << '\t'; });
	std::cout << "\n";
}


void after_reserve_end_is_still_the_one_after_last_but_not_may_be_used() {
	std::vector<int> v{ 1, 2, 3 };
	v.reserve(v.size() + 5);

	std::cout << "Size of reserved vector is : " << v.size() << '\n';
	std::for_each(v.begin(), v.end(), [&](const int& v) {std::cout << v << '\t'; });
	std::cout << "\n";
}

//int main() {
//	after_reserve_end_is_still_the_one_after_last_but_not_may_be_used();
//}