/**
*	-	constexpr ForwardIt2 swap_ranges( ForwardIt1 first1, ForwardIt1 last1, ForwardIt2 first2 );
* Exchanges elements between range [first1, last1) and another range starting at first2. 
* Precondition: the two ranges [first1, last1) and [first2, last2) do not overlap, where 
* last2 = std::next(first2, std::distance(first1, last1)).
*/