/**
*	-	constexpr void replace( ForwardIt first, ForwardIt last, const T& old_value, const T& new_value );
*	-	constexpr void replace_if( ForwardIt first, ForwardIt last, UnaryPredicate p, const T& new_value );
* 
* Replaces all elements satisfying specific criteria with new_value in the range [first, last). (or based on
* the predicate.)
*/

#include <algorithm>
#include <array>
#include <iostream>
#include <functional>

void using_replace()
{
    std::array<int, 10> s{ 5, 7, 4, 2, 8, 6, 1, 9, 0, 3 };

    std::replace(s.begin(), s.end(), 8, 88);

    for (int a : s) {
        std::cout << a << " ";
    }
    std::cout << '\n';

    std::replace_if(s.begin(), s.end(),
        std::bind(std::less<int>(), std::placeholders::_1, 5), 55);
    for (int a : s) {
        std::cout << a << " ";
    }

    std::cout << '\n';
}