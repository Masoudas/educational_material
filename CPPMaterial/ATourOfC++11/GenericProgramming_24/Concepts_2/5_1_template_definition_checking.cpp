/**
* A constraints-check template ensures that a type provides the properties required by the concept. If the 
* implementation of a template (Me: meaning the function or the type that uses the template) in fact uses more 
* properties than its concepts guarantee, we may get type errors.
* 
* For example, consider the following implementation of find method. We see that for example, we're not using the
* b++ or ++b method of the iterator, but rather a random access operation (by addition with int). Consequently, 
* even though we check for an input iterator (as the big guy discusses in 4), we in practice work a random access
* iterator. Hence this find method does not work with the iterator of a list.
* 
* Note that at this point (point of C++11 at least), there's no check provided by the language to dissuade us from
* using more properties than a concept guarantees for a template. However, concepts provide a strong guideline: 
* the implementation should use no property of an argument that isn’t specified by the concepts, so we should test 
* the implementation with arguments that provide the properties specified by the implementation’s concepts, and 
* only those. Such a type is sometimes called a (bloody!) archetype.
* 
* So, for the find() example, we look at Forward_iterator and Equality_comparable or at the standard’s definition 
* of the forward-iterator and equal-comparable concepts (§iso.17.6.3.1, §iso.24.2.5). Then, we decide that we need 
* an Iterator type that provides at least:
*	-	A default constructor
*	-	A copy constructor and a copy assignment
*	-	Operators == and !=
*	-	A prefix operator ++
*	-	A type Value_type<Iterator>
*	-	A prefix operator*
*	-	The ability to assign the result of * to a Value_type<Iterator>
*	-	The ability to assign a Value_type<Iterator> to the result of *
* 
* 
*/
#include <type_traits>

template<typename Itr>
constexpr bool Input_iterator() {
	return false;
}

template<typename U, typename V>
constexpr bool Equality_comparable() {
	return false;
}

template<typename T>
using Value_type = typename T::value_type;

template<typename _InputItr, typename Val>
_InputItr find(_InputItr begin, _InputItr end, Val v) {
	static_assert(Input_iterator<_InputItr>(), "find(): Iter is not a Forward iterator");
	static_assert(Equality_comparable<Value_type<_InputItr>, Val>(), "find(): value type doesn't match iterator");

	while (begin != end) {
		if (*begin == v) return begin;
		begin = begin + 1;	// Not using begin++;
	}

	return end;
}