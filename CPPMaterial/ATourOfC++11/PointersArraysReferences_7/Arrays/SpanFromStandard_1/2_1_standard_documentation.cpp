/**
* The standard states that:
* template<class T, std::size_t Extent = std::dynamic_extent> class span;
* 
* The class template span describes an object that can refer to a contiguous sequence of objects with the first 
* element of the sequence at position zero. A span can either have a static extent, in which case the number of 
* elements in the sequence is known at compile-time and encoded in the type, or a dynamic extent.
*
* If a span has dynamic extent a typical implementation holds two members: a pointer to T and a size. A span 
* with static extent may have only one member: a pointer to T.
* 
* Template parameters
*	T	-	element type; must be a complete object type that is not an abstract class type
*	Extent	-	the number of elements in the sequence, or std::dynamic_extent if dynamic
* 
* Note: iterator is a mutable iterator if T is not const-qualified.
* All requirements on the iterator types of a Container apply to the iterator type of span as well.
*/