/**
* The standard defines the class reference_wrapper<T> for the purpose we just illustrated. Moreover, there's
* a function called std::ref (both of which in the type_traits header) that take care of this issue for us.
* 
* The following example is from the standard. In it, we put references to elements of a list in a vector.
* Thus, we can do operations on a list, as we do a vector, although the list does not change as such. You
* can contemplate why this happens. There's also an exercise I crafted in 'CPPAlgorithmsAndDataStructures,
* chapter 1, list_4, shuffle a list, which fully explains the point'
* 
*/

#include <algorithm>
#include <list>
#include <vector>
#include <iostream>
#include <numeric>
#include <random>
#include <functional>

void usage_of_wrapper_to_create_an_array()
{
    std::list<int> l(10);

    std::iota(l.begin(), l.end(), -4);  // Assigns increments, starting from -4 to l.
    std::vector<std::reference_wrapper<int>> v(l.begin(), l.end());     // Creating an array of ref.

    // can't use shuffle on a list (requires random access), but can use it on a vector
    std::shuffle(v.begin(), v.end(), std::mt19937{ std::random_device{}() });

    std::cout << "Contents of the list: ";
    for (int n : l) {
        std::cout << n << ' ';
    }

    std::cout << "\nContents of the list, as seen through a shuffled vector: ";
    for (int i : v) {
        std::cout << i << ' ';
    }

    std::cout << "\n\nDoubling the values in the initial list...\n\n";
    for (int& i : l) {
        i *= 2;
    }

    std::cout << "Contents of the list, as seen through a shuffled vector: ";
    for (int i : v) {
        std::cout << i << ' ';
    }
}
