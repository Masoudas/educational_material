/**
* One basic implementation would be to use an array of size M. Then using an insertion sort like loop,
* we find the place where a new key belongs. In this method, insertion has o(n) complexity, but deletion 
* has o(1) complexity.
* 
* Another implementation is to keep the keys unordered, for example using a stack. When removing, we find the 
* largest item, by a simple comparison like insertion sort. This way, insertion has o(1) and del has o(n).
* This implies that the code for stack has to be inside the queue. We can't use a separate stack. We can resize the
* stack if needed.
* 
* We may also use a linked-list. This method would require o(1) for deletion and o(n) for insertion as well.
* 
* Using unordered containers is called LAZY implementation.
* 
* The heap data structure however, brings both operations to log(n) order.
*/