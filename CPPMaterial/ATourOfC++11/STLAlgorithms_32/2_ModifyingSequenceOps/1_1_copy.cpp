/**
* Just like many other algorithms, we have copy and copy_if as two algorithms:
*	-	constexpr OutputIt copy( InputIt first, InputIt last, OutputIt d_first );
*	-	constexpr OutputIt copy_if( InputIt first, InputIt last, OutputIt d_first, UnaryPredicate pred );
* 
* Copies the elements in the range, defined by [first, last), to another range beginning at d_first.
* 
* Copies all elements in the range [first, last) starting from first and proceeding to last - 1. The behavior 
* is undefined if d_first is within the range [first, last). In this case, std::copy_backward may be used 
* instead.
* 
* Note: In practice, implementations of std::copy avoid multiple assignments and use bulk copy functions such 
* as std::memmove if the value type is TriviallyCopyable and the iterator types satisfy 
* LegacyContiguousIterator.
* 
* The most famous example of copy that I use right now is with ostream_iterator.
*/

#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
#include <numeric>
 
void using_copy_example()
{
    std::vector<int> from_vector(10);
    std::iota(from_vector.begin(), from_vector.end(), 0);
 
    std::vector<int> to_vector;
    std::copy(from_vector.begin(), from_vector.end(),
              std::back_inserter(to_vector));
// or, alternatively,
//  std::vector<int> to_vector(from_vector.size());
//  std::copy(from_vector.begin(), from_vector.end(), to_vector.begin());
// either way is equivalent to
//  std::vector<int> to_vector = from_vector;
 
    std::cout << "to_vector contains: ";
 
    std::copy(to_vector.begin(), to_vector.end(),
              std::ostream_iterator<int>(std::cout, " "));
    std::cout << '\n';
 
    std::cout << "odd numbers in to_vector are: ";
 
    std::copy_if(to_vector.begin(), to_vector.end(),
                 std::ostream_iterator<int>(std::cout, " "),
                 [](int x) { return (x % 2) != 0; });
    std::cout << '\n';
}