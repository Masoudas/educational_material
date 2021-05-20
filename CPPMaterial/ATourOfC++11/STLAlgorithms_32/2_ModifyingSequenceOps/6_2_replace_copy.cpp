/**
*	-	constexpr OutputIt replace_copy( InputIt first, InputIt last, OutputIt d_first,  const T& old_value,
*           const T& new_value );
*	-	constexpr OutputIt replace_copy_if( InputIt first, InputIt last, OutputIt d_first, UnaryPredicate p, 
*			const T& new_value );
* 
* Copies the elements from the range [first, last) to another range beginning at d_first replacing all 
* elements satisfying specific criteria with new_value. The source and destination ranges cannot overlap.
* 
* Me: So note that replacement occurs when copying to the destination vector, not in the original vector.
*/

#include <algorithm>
#include <vector>
#include <iostream>
#include <iterator>
#include <functional>
 
void replace_and_copy_example()
{
    std::vector<int> v{5, 7, 4, 2, 8, 6, 1, 9, 0, 3};
    std::replace_copy_if(v.begin(), v.end(),
                         std::ostream_iterator<int>(std::cout, " "),
                         [](int n){return n > 5;}, 99);
    std::cout << '\n';
}