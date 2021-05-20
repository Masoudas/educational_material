/**
*	-	constexpr OutputIt reverse_copy( BidirIt first, BidirIt last, OutputIt d_first );
* 
* Copies the elements from the range [first, last) to another range beginning at d_first in such a way that 
* the elements in the new range are in reverse order.
* 
* Behaves as if by executing the assignment *(d_first + (last - first) - 1 - i) = *(first + i) once for each 
* non-negative i < (last - first).
*/