/**
* Me: Don't just go past these sorts of functions! God knows how many times I've wanted to copy or move one array into
* another. That being said, a reverse iterator does the same thing with the copy operator.
* 
*	-	constexpr BidirIt2 copy_backward( BidirIt1 first, BidirIt1 last, BidirIt2 d_last );
*	
* Copies backward.
*/

#include <algorithm>
#include <iostream>
#include <vector>
 
void backward_copy_example()
{
    std::vector<int> from_vector;
    for (int i = 0; i < 10; i++) {
        from_vector.push_back(i);
    }
 
    std::vector<int> to_vector(15);
 
    std::copy_backward(from_vector.begin(), from_vector.end(), to_vector.begin());

    // back warnd copy by getting reverse iterators
    //std::copy(from_vector.rbegin(), from_vector.rend(), to_vector.begin());
 
    std::cout << "to_vector contains: ";
    for (auto i: to_vector) {
        std::cout << i << " ";
    }
 }