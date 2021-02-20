/**
* A priority_queue allows access to the min or max element of the heap. The underlying data structure of pq
* is of course a vector. However, heapification algorithms are implemented in pq. Note that priority_queue is
* in the queue header.
* 
* Note that the constructor of a priority queue does not accept keys directly. However, we can supply an 
* iterator to it, and it will take the elements of that iterator, copy them, and create a heap for us, using
* the copied elements.
* 
* Note that being a min or max pq depends on the comparator provided. If comparator is less, then if a value
* is less than the parent node goes down (making it a maxpq), otherwise a min pq.
* 
* As a reminder, we should recall that std::make_heap, std::pop_heap and std::push_heap can be used to create
* a contiguous heap.
* 
* Notice how the top method of priority_queue returns a const ref. The reason for this is that we don't want
* the user to go ahead and change the value in the pq, which undermines the order of it.
*/
#include <queue>
#include <iostream>

void using_pq(){
	using minPQ = std::priority_queue<int, std::vector<int>, std::greater<int>>;
	
	std::vector<int> v{ 2, 4, 1 ,3 };

	minPQ pq{v.begin(), v.end()};
	
	std::cout << "The top element of the pq is:" << pq.top();
}

//int main() {
//	using_pq();
//}