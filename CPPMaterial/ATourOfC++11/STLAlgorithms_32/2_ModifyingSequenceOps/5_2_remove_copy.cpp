/**
*	-	constexpr OutputIt remove_copy( InputIt first, InputIt last, OutputIt d_first, const T& value ); (1)
*	-	constexpr OutputIt remove_copy_if( InputIt first, InputIt last, OutputIt d_first, UnaryPredicate p ); 
*		(3)
* 
* Copies elements from the range [first, last), to another range beginning at d_first, omitting the elements 
* which satisfy specific criteria. Source and destination ranges cannot overlap.
* 
*	(1) Ignores all elements that are equal to value.
*	(3) Ignores all elements for which predicate p returns true.
* 
* Question from me: What's the difference between this method and the copy_if method? In that one, we define
* a predicate upon which we copy. In this one, we define a predicate upon which we remove. So, essentially
* they're the same.
* 
* The following example demonstrates that.
*/

#include <algorithm>
#include <iterator>
#include <string>
#include <iostream>
#include <iomanip>

void remove_copy_example()
{
    std::string str = "#Return #Value #Optimization";
    std::cout << "before: " << std::quoted(str) << "\n";
 
    std::cout << "after:  \"";
    std::remove_copy(str.begin(), str.end(),
                     std::ostream_iterator<char>(std::cout), '#');
    std::cout << "\"\n";
}