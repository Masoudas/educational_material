/**
* Now, as we know we usually don't inherit from an interface to specify the type of iterators we write. Moreover,
* We know that we have the following types of iterators, which are discussed in chapter 24 under famous concepts:
* 
* - Input iterator
* - Output iterator
* - Forward iterator
* - Bidirectional iterator
* - Random access iterator
* - Contiguous iterator (which can be different from RA)
* 
* So how do we determine what sort of iterator we're dealing with? It's done by defining an alias inside the iterator.
* Now, what do we assign to these iterators? There are the following structures defined in the xutility header that
* are the tags for the iterators. The tags are as follows:
* 
* -	struct input_iterator_tag {};
* -	struct output_iterator_tag {};
* -	struct forward_iterator_tag : input_iterator_tag {};
* -	struct bidirectional_iterator_tag : forward_iterator_tag {};
* -	struct random_access_iterator_tag : bidirectional_iterator_tag {};
* -	struct contiguous_iterator_tag : random_access_iterator_tag {};
* 
* So we see that each tag corresponds to one type of iterator. We can also inspect the iterators of vector to see
* how these tags are used.
* 
* The name of the alias we use to determine the type of the iterator is iterator_category.
* 
* Note: As of C++20, they also use iterator concept.
* 
* Now, note that because we're writing a wrapper for an existing iterator, we're not going to use these tags 
* directly. We rather use the tag of the existing iterator we want to wrap.
*/

#include <xutility>

class an_int_array_iterator {
public:
	using iterator_category = std::contiguous_iterator_tag;
};

template<typename _Itr>
class iterator_wrapper {
public:
	using iterator_category = typename _Itr::iterator_category;	// Aliasing the type of the iterator to be wrapped.
};

