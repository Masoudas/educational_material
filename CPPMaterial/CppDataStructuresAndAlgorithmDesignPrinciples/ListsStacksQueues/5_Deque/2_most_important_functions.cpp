/**
* As dequeues try and imitate the behavior of both lists and vectors, they share a combination of their functions:
*	- emplace_front
*	- emplace
*	- pop_front
*	- pop_back
*	- push_front
*	- push_back
*	- size	
*	- spaceship operator (for lexicographical comparison)
* 
* The resize method resizes the container so that:
*	-	If the current size is greater than count, the container is reduced to its first count elements.
*	-	If the current size is less than count,
*			1) additional default-inserted elements are appended
*			2) additional copies of value are appended.
*
* They also support [], and bidirectional random access iterators. 
* 
* There's also a shrink_to_fit method, yet, there's no capacity method, because the capacity depends on 
* the implementation.
* 
*/
#include <deque>
#include <iostream>

void deque_investigation() {
	using std::deque;

	deque<int> d1{1, 2, 3, 4};
	deque<int> d2{ d1 };	// Copy constructor

	int front = d2[0];	// Always returns a reference to the back, so that we can assign to it.
	int& back = d2.back();	// Returns a reference to the back element

	d2.emplace_back(5);	// Emplaces the element at the back, avoiding separate construction
	d2.emplace_front(0); 

	d2.emplace(d2.begin(), -1);	// Places the element at the place of the current begin. So the new vector is
								// {-1, 0, 1, 2, ...} 

	d2.clear();	// Erases all elements from the deque. After this, the size method returns 0.

}

void resize_deque() {
	using std::deque;
	using std::cout;

	deque<int> d1{ 1, 2, 3, 4 };

	d1.resize(5);
	std::cout << "A new element has been inserted, making the size equal to: " << d1.size();
	std::cout << "\nThe new element is default constructed, so its value is: " << d1[4];

}

//int main() {
//	resize_deque();
//}
