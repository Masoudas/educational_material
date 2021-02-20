/**
* Note that if we wanted the iterator wrapper to jump to each n-th element, we need to increment by multiples of 
* five. Moreover, for the operator- working on the distance between the operators, we needed to divide by n, 
* because each increment by one means n for the underlying element.
* 
* A reminder is that with input, output and bidirectional iterators, we cannot compute the distance for example.
* Therefore, for such iterators we needn't overload the operator- (even for difference_type). This is the reason
* why we can't calculate the distance between two nodes. Note however that we can still use the advance or next
* operators, because they solely rely on increment operators.
* 
* What should we use as the difference_type for such types? As an example, we see that C++ has used the allocator's
* difference_type alias to that end, which is once again ptrdiff_t, if we find the definition of the alias in the
* corresponding header. So, leave it to the standard to determine the type.
*/


