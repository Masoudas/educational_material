/**
* As we already know, a vector has the problem of reallocation for the entire vector upon insertion and deletion, 
* (hence cost N), whereas random access is possible. On the other hand, a list has the random access issue.
* 
* A Double-Ended Queue or dequeue tries to reach the middle ground by assuring:
*	1-	Random access of cost O(1).
*	2-	Push and pop of front and back of cost O(1)
*	3-	Insertion in the middle of O(N/2) cost (and less for other locations).
* Interestingly enough, dequeue is shorthanded for 'deque', and they drop the ending 'ue'!
* 
* Essentially what do is to have a chunck of memory, and we place elements from the middle of this chunk. Therefore,
* in the worst case, we need to move elements N/2 to left or right, and less than that as we get closer to either
* head of the memory chunk. 
* 
* Instead of having one contiguous chunk of memory, we'd keep several chunks of memory of the same size. This would
* allow an easy random access. Moreover, when it comes to push front and back, we wouldn't have to move around all
* the stored elements from one chunk of memory to another. We'd instead just append a chunk of memory in front of
* the previously allocated memory, and keep the pointer.
* 
* The point: know your data structures. If you're dealing with a situation where you constantly have to place
* elements at the front or end, use dequeues.
* 
* Note that the implementation detail of a dequeue differes for each compiler.
*/