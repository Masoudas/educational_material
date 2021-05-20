/**
* Me: I was hoping this would swap all elements pointed by two iterators, but it doesn't! Swaps just one.
* 
*	-	constexpr void iter_swap( ForwardIt1 a, ForwardIt2 b );
*	Swaps the values of the elements the given iterators are pointing to.
* 
*	Possible implementation is:

template<class ForwardIt1, class ForwardIt2>
constexpr void iter_swap(ForwardIt1 a, ForwardIt2 b) // constexpr since C++20
{
   using std::swap;
   swap(*a, *b);
}

* The standard hence says "This function template models the semantics of the swap operation given by 
* Swappable. That is, overloads of swap found by ADL and the fall back of std::swap are considered."
*/

#include <random>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>

// A simple implementation of selection sort in one line.
template<class ForwardIt>
void selection_sort(ForwardIt begin, ForwardIt end)
{
    for (ForwardIt i = begin; i != end; ++i)
        std::iter_swap(i, std::min_element(i, end));
}

void sorting_a_vector()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(-9, +9);
    std::vector<int> v;
    std::generate_n(back_inserter(v), 20, bind(dist, gen));

    std::cout << "Before sort: " << std::showpos;
    for (auto e : v) std::cout << e << ' ';

    selection_sort(v.begin(), v.end());

    std::cout << "\nAfter sort : ";
    for (auto e : v) std::cout << e << ' ';
    std::cout << '\n';
}