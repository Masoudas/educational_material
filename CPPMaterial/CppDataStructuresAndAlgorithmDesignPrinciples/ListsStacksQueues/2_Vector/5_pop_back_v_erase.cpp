/**
* pop_back and erase allow us to remove elements from the back and an arbitrary location. 
*
* When we remove an item from the back, the size decreases, but not the capacity (necessarily).
* The C++ standard doesn't require these functions to reduce the capacity of the vector. It depends 
* entirely on the compiler implementation. We expect access to the removed element to throw some sort 
* of error (or at least be undefined), which it is. Of course, the 'at' method most certainly throws an 
* exception in this case. pop_back therefore can be achieved with O(1). erase on the other hand requires
* the shifting of elements, thus has complexity O(n).
* 
* With erase, we could also erase an entire section of a vector, by passing the proper start and end
* iterator. One thing to note here is that iterators can be added a integer value as well (like any normal
* pointer). Therefore, we can apply an offset by direct addition to the iterator. Note that the first element 
* is inclusive, and the last one is exclusive.
* 
* Exercise: Write a program to eliminate every odd member of a vector?
* An interesting question here would be, wouldn't it be better to create a new vector based on the
* even elements of the old array?! The other solution would be to use remove_if, which we'll discuss
* later on.
* 
* Apparently (and at least for the most recent standard version it seems), the erase and pop_back
* methods use emplacing. There's no duplicate method like emplace for insert for removal methods.
*/

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

template <typename T>
void print_size_and_capacity(const vector<T>& vec) {	// Why wouldn't this throw a duplicate object?!
														// This is redifinition from 3_ section!
	cout << "Size is: " << vec.size() << " and capacity is: " << vec.capacity() << '\n';
}

void pop_back() {
	vector<int> vec{ 1,2,3,4,5,6,7,8 };
	
	cout << "Before removal: \n";
	print_size_and_capacity(vec);
	vec.pop_back();

	cout << "After removal: \n";
	print_size_and_capacity(vec);

	// cout << "Accessing removed index: " << vec[7] << '\n'; Error. Undefined behavior (exception in MSVC)
	
}

void erase() {
	vector<int> vec{ 1,2,3,4,5,6,7,8 };

	vec.erase(vec.begin() + 1, vec.begin() + 3);	// Erase second (inclusive) to forth element (exclusive)
	for_each(vec.begin(), vec.end(), [](int v)->void { cout << v << '\t'; });

}

void remove_every_odd_element() {
	vector<int> vec{ 1,2,3,4,5,6,7 };

	for (size_t i = 1; i < vec.size(); i++) {	// Attention! unsigned to signed comparison.
		vec.erase(vec.begin() + i);
	}

	for_each(vec.begin(), vec.end(), [](int v)->void { cout << v << '\t'; });
}

//int main() {
//	//pop_back();
//	//erase();
//	remove_every_odd_element();
//
//}