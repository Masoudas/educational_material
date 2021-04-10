/**
* The standard library relies heavily on traits. A trait is used to associate properties with a type. For example, the 
* properties of an iterator are defined by its iterator_traits, as demonstrated below:
* 
* Note from me: Recall the example I did in chapter 33, WritingAWrapperIterator. In that example, to write a proper 
* iterator that can be used in conjunction with the std libraries, I needed to define Alises such as ptr_difference,
* value_type, pointer, etc inside the definition of the iterator. The big guy now is talking about such traits, and in fact
* he's going to talk about it more in the coming sections.
* 
* Note from me: If we check the definition of std::vector<>::iterator, we find the allocator trait functions such as 
*  _Default_allocator_traits or _Normal_allocator_traits in the xmemory header. Note that the traits must be defined 
* inside the iterator definiton. Them we can use the iterator_traits function to access them.
* 
* Note: The following function is implemented in the iterator header. We shall discuss this further.
*/

// An iterator has all these parameters defined inside of it as an alias. We use this function just to access them in a
// uniform manner. We might not want to forget that a type has to be passed to this function, that is vector_iterator<int>
// for example, and not vector_iterator!

template<typename Iter>
struct iterator_traits {
	using value_type = typename Iter::value_type;
	using pointer = typename Iter::pointer;
	using pointer_difference = typename Iter::pointer_difference;
	using reference = typename Iter::reference;
	using iterator_category = typename Iter::iterator_category;	// Five categories: input iterator, output iterator,
																// forward, bidirectional, random access. See Chapter 24,
																// concepts
};
