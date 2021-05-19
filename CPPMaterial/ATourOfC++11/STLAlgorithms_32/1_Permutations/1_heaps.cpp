/**
* make_heap can be used to create a heap from an existing data structures (heap is a data structure where parent
* node is greater than or smaller than its children). The heap will be created inside the same container. 
* Recall the heap creation algorithm from Sedgewick, where we start from the bottom elements and move up. 
* 
* Can a list be turned into a heap? Nope. For example, we need to get the size of it, which can't be done
* from the iterators using their difference. Plus, a move is required directly between elements, which is 
* not possible for list (we need removal of node, then insertion). We can heapify a list in general, but not
* with this stl method.
* 
* By default, it creates a max heap.
* We can supply a predicate. The predicate checks whether in (left, right), left is less than right. Hence, a
* an object which returns false, turns our heap into a min heap.
* 
* Now, imagine we wanted to pop from the heap (equivalent to deleting the max element). We can use the 
* pop_heap method, which does this for us. What it does is push this element to the end of the heap (like 
* heap sort), and the remainder becomes another new heap (i.e, last and first elements are swapped, and then
* first is sinked). Therefore, if we repeat the heap k times, we get the greatest k elements at the bottom of
* the container. Notice that we need to provide an iterator for pop heap. Therefore, if we want the k larget
* elements, we need to repeat the loop k times, each time with end()-i (i=0,...,k-1)
* 
* We can also push new elements into the heap, making it a new larger heap. push_heap is like swim. Therefore
* the element is moved into its correct position IFF its put at the end of the heap. If put at a random position,
* the heap is distorted however.
* 
* A final note is that sort_heap does the pop_heap for all the elements, making it a sort based on heap.
*/

#include <vector>
#include <list>
#include <algorithm>
#include <sstream>
#include <iostream>

void printer(std::vector<int>& l, const std::string& message)
{
	std::ostringstream o{};
	o << message;
	std::for_each(l.begin(), l.end(), [&](int v) {o << v << '\t'; });

	std::cout << o.str();
}

void makeheap_from_container() {
	std::vector<int> vec{ 1, 2, 3, 4, 5 };
	std::make_heap(vec.begin(), vec.end(), [](int l, int r) { return l < r; });

	std::ostringstream o{};

	o << "The generated heap, which holds the max element on top, is as follows: \n";
	std::for_each(vec.begin(), vec.end(), [&](int v) {o << v << '\t'; });

	// Making a min heap.
	std::make_heap(vec.begin(), vec.end(), [](int l, int r) { return l > r; });
	printer(vec, "\nWe have a min heap, as follows: \n");
}

void pop_heap_of_made_heap() {
	std::vector<int> l{ 1, 3, 4, 5, 2 };
	std::make_heap(l.begin(), l.end(), [](int v, int w) {return v < w; });

	// Pop the first three elements.
	for (int k = 0; k < 3; k++) {
		std::pop_heap(l.begin(), l.end()-k);	// Pops top of heap and sinks.
	}
	printer(l, "The popped heap is as follows: \n");
}

void push_heap_of_made_heap() {
	std::vector<int> l{ 1, 3, 4, 5, 2 };
	std::make_heap(l.begin(), l.end(), [](int v, int w) {return v < w; });

	// Inserting an element at the end of the list
	l.push_back(12);

	// Reheapify
	std::push_heap(l.begin(), l.end());
	printer(l, "The popped heap is as follows: \n");

}

void sort_heap() {
	std::vector<int> l{ 1, 3, 4, 5, 2 };
	std::make_heap(l.begin(), l.end(), [](int v, int w) {return v < w; });

	std::sort_heap(l.begin(), l.end());

	printer(l, "The sorted array with heap algorithm is: \n");
}

//int main() {
//	pop_heap_of_made_heap();
//}