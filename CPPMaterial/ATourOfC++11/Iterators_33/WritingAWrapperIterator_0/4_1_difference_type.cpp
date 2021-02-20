/**
* This is one of the crucial aliases we use, as it allow us to use methods such as advance, next, and distance.
* 
* So the questions that we must ourselves when trying to determine the distance between two instance iterators 
* itr1 and itr2 is:
* 1- What is the unit of measuring the difference?
* 2- How is the difference calculated?
* 
* Answer to question one:
* So for example imagine the underlying iterator is an array of ints (so the iterator uses pointer to ints). So,
* what is the unit of measuring the difference between two pointers to ints? Yes, its ptr_diff (and not int :D).
* We need to define the difference type of our iterator (or more precisely the pointer under it). This alias is
* defined as 'difference_type' and is used by many of the C++ standard function. For example, if we check the
* std::distance, we see that the first thing the iterator checks is the difference type and if it's a proper 
* pointer difference, it will just use the difference of two iterators (which we discuss next).
* 
* Note: When we're defining the difference_type, we could consider what is the result of difference between the
* 'pointer' alias is. This is the simplest solution.
* 
* Answer to question two:
* See next file.
*/

#include <xutility>
#include <cstddef>

class an_int_array_iterator {
public:
	using iterator_category = std::contiguous_iterator_tag;
	
	using value_type = int;
	using pointer = value_type*;	
	using reference = value_type&;	

	using difference_type = std::ptrdiff_t;	// What is the result of pointer - pointer? It's ptrdiff_t.
};

template<typename _Itr>
class iterator_wrapper {
public:
	using iterator_category = typename _Itr::iterator_category;	

	using value_type = typename _Itr::value_type;	
	using reference = typename _Itr::reference;
	using pointer = typename _Itr::pointer;

	using difference_type = typename _Itr::difference_type;	// Just drag the difference type of the underlying itr.
};