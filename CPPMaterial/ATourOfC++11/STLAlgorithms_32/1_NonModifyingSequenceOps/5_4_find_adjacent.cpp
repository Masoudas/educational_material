/**
*	-	constexpr ForwardIt adjacent_find( ForwardIt first, ForwardIt last );
*	-	constexpr ForwardIt adjacent_find( ForwardIt first, ForwardIt last, BinaryPredicate p );
* 
* Finds the first two adjacent elements that are equal. 
* 
* The second example is quite interesting.
*/

#include <algorithm>
#include <iostream>
#include <vector>
#include <functional>
 
void find_adjacent()
{
    std::vector<int> v1{0, 1, 2, 3, 40, 40, 41, 41, 5};
 
    auto i1 = std::adjacent_find(v1.begin(), v1.end());
 
    if (i1 == v1.end()) {
        std::cout << "no matching adjacent elements\n";
    } else {
        std::cout << "the first adjacent pair of equal elements at: "
                  << std::distance(v1.begin(), i1) << '\n';
    }
 
    // Recall that greater means greater(a,b) --> a > b
    auto i2 = std::adjacent_find(v1.begin(), v1.end(), std::greater<int>());
    if (i2 == v1.end()) {
        std::cout << "The entire vector is sorted in ascending order\n";
    } else {
        std::cout << "The last element in the non-decreasing subsequence is at: "
                  << std::distance(v1.begin(), i2) << '\n';
    }
}

int main() {
    find_adjacent();
}