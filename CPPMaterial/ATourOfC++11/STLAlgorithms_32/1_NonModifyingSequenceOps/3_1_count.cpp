/**
*	-	constexpr typename iterator_traits<InputIt>::difference_type 
*			count( InputIt first, InputIt last, const T &value );		(1)
* 
*	-	constexpr typename iterator_traits<InputIt>::difference_type
*              count_if( InputIt first, InputIt last, UnaryPredicate p ); (3)
*	-	(2),(4) are parallel versions of (1) and (3).
* 
*	1) counts the elements that are equal to value.
*	3) counts elements for which predicate p returns true.
*/