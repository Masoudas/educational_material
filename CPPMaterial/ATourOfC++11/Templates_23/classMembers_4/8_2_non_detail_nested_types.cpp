/**
* Now imagine that a nested class is not an implementation detail, like an iterator of a List.
*
* Granted that we can implement the list as a nested class. However, we run into the same problem. That is,
* scoping to the iterator depends on both the type, and allocator of the class. This is obvious in the
* asking_for_iterator, where two iterators that don't depened on the allocator are used.
*
* We could make asking_for_iterator a template and generate separate specializations for each allocator. However,
* that would generate a new specialization for every use of Iterator, so this could lead to significant
* code bloat.
*
* Then again, Implementing the iterator outside the class solves this problem, which is the case for STL
* containers too.
* 
* Bjarne says: "My rule of thumb is ‘‘A void nested types in templates unless they genuinely rely on every 
* template parameter.’’
*
* NOTE: If we're faced with this situation, one solution is to use trains (chapter 28). Another solution is to
* use a wrapper, and wrap every iterator type in a common type.
*/

struct My_Alloc {};
struct Your_Alloc {};
template<typename T, typename ALLOC>
struct List_Nested_Iterator {
	class Iterator {

	};
};

using My_Itr = List_Nested_Iterator<int, My_Alloc>::Iterator;
using Your_Itr = List_Nested_Iterator<int, Your_Alloc>::Iterator;

void asking_for_iterator(My_Itr itr1, Your_Itr itr2) {}

template<typename CONTAINER>
struct Iterator {
	using type = typename CONTAINER::value_type;
};

template<typename T>
struct List {
	using value_type = T;
	using Iterator = Iterator<List<T>>;

	Iterator begin() { Iterator{}; }
};

using Itr = List<int>::Iterator;

void asking_for_iterator(Itr itr1, Itr itr2) {} // Iterator depends only on the type, and not the allocator.