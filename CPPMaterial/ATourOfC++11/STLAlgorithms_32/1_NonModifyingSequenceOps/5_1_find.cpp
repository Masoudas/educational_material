/**
*	-	constexpr InputIt find( InputIt first, InputIt last, const T& value );
*	-	constexpr InputIt find_if( InputIt first, InputIt last, UnaryPredicate p );
*	-	InputIt find_if_not( InputIt first, InputIt last, UnaryPredicate q );
* 
* Returns an iterator to the FIRST element in the range [first, last) that satisfies specific criteria:
*	1) find searches for an element equal to value
*	3) find_if searches for an element for which predicate p returns true
*	5) find_if_not searches for an element for which predicate q returns false
*/