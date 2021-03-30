/**
* One might wonder how we can shuffle a list. Despite the fact that there are methods to do so, an interesting
* approach is to convert a list to a vector, then suffle the vector. Question is, how can we do that without 
* too much excessive space? If only there was a way so that we could put a reference to elements of a list 
* inside a vector, then that would be possible. Note that we're not 
* 
* The problem however is that as we may recall, we can't define a vector of references in C++.
* 
* To circumvent this problem this, we can take an intermediary step. That is, we need a sort of wrapper around 
* elements of a list that work as references to elements. This is exactly the concept we talked about when 
* trying to circumvent decay_t<T> (See Chapter 35 of A tour of C++, under type functions.) 
* 
* Now, note that when we create the vector of reference_wrappers, it's like we've created an array if thin
* wrappers around elements of the list. Thus, when we shuffle the vector, we shuffle these classes (not the
* actual integers of the list!). The point however is that this array is so thin, that this shuffling essentially
* does not take that much of an extra space in memory. However, the original array remains in tact.
*  
* Now, to overcome this last issue, we need to write an iterator that actually returns the int&, rather than
* reference_wrapper. The most important method of this iterator is the operator* for this end. If we do this
* 
* In conclusion, we can use the reference_wrapper class of C++ and simulate an array of references. Then,
* we can sort, shuffle, or do anything with a vector. If we don't generate the iterator wrapper, the original
* container remains in tact.
*/
#include <forward_list>
#include <vector>
#include <algorithm>
#include <numeric>
#include <random>
#include <iostream>
#include <iterator>

struct itr_wrapper {
	using itr = std::vector<std::reference_wrapper<int>>::iterator;

	itr iterator;

	itr_wrapper(itr i) : iterator{ i } {}

	int& operator*() {
		return *iterator;
	}
};

void shuffle_a_list() {
	std::forward_list<int> l(10, 0);
	std::iota(l.begin(), l.end(), 0);	// Set increasing elements from 0.
	
	std::vector<std::reference_wrapper<int>> v{ l.begin(), l.end() };	// Cleverly create an array of refs!
	
	// Should write something like this to actually shuffle the list.
	// std::shuffle(itr_wrapper{v.begin()}, itr_wrapper{v.end()}, std::mt19937{ std::random_device{}() });
	
	// But Ok. Let's continue with this.
	std::shuffle(v.begin(), v.end(), std::mt19937{ std::random_device{}() }); // Note that only shuffles the 
																			// the wrappers, not the ints!
	
	std::ostream_iterator<int> o{ std::cout, "\t" };
	std::copy(l.begin(), l.end(), o);
}

//int main() {
//	shuffle_a_list();
//}