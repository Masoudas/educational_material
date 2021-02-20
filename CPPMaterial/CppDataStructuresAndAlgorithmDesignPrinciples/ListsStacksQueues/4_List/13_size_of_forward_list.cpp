/**
* As we already discussed, there's no function in forward list that returns the size of the list. So,
* how can we get the size of a list? 
* 
* Well, there's no good answer here. We need to iterate over the list, and calculate the number of itrs
* required to get there. Because we're going from one place of memory to another, this is indeed time
* consuming. Notice the use of distance function for doing so, also note that we use start to end,
* because end is one element after the last element.
*/
#include <forward_list>
#include <iostream>

void getting_size_of_forward_list() {
	std::forward_list<int> l{ 1, 2, 3, 4, 5 };

	ptrdiff_t distance = std::distance(l.cbegin(), l.cend());

	std::cout << "Size of the list after some brutal calculation is: " << distance;
}

//int main() {
//	getting_size_of_forward_list();
//}