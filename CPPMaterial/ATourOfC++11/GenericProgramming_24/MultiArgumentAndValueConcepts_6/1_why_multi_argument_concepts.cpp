/**
* It's often the case that for an operation to be perfomed between two templates, they have to satisfy an inter
* concept (or constraint).
* 
* Consider for example, consider the find method of STL. It depends critically on comparing x to elements of the 
* sequence [b:e). We need to specify that comparison is required; that is, we need to state that Val and the value
* type of the input iterator are equality comparable. That requires a two-argument version of Equality_comparable.
* 
* This implementation is shown below. This is rather verbose for a simple concept. However, I wanted to be explicit 
* about all of the operators and about the symmetry of their use rather than burying the complexity in a 
* generalization. (Me: particularly note the check for symmetry, where we check that we can write U < T as well as
* T < U.)
* (Me: Also notice that we check that U and T have a common (type they can be both converted to, or more precisely,
* their pointers.) This is articulation of the language rule that both types can be used in a ternary if '?:'
* operator.) 
* 
* Multi-argument concepts are particularly common and useful when specifying generic algorithms. This is also the 
* area where we find the greatest number of concepts and the greatest need to specify new concepts (as opposed to 
* picking "standard ones" from a catalog of common concepts). The variations among well-defined types appear to 
* be somewhat more limited than the variations among algorithms’ requirements on their arguments.
* 
*/

template<typename Iter, typename Val>
Iter find(Iter b, Iter e, Val x) { return b; };

//template<typename T, typename U>
//constexpr bool Equality_comparable(T a, U b)
//{
//	return Common<T, U>()
//		&& Totally_ordered<T>()
//		&& Totally_ordered<U>()
//		&& Totally_ordered<Common_type<T, U>>()
//		&& Has_less<T, U>() && Boolean<Less_result<T, U>>()
//		&& Has_less<U, T>() && Boolean<Less_result<U, T>>()
//		&& Has_greater<T, U>() && Boolean<Greater_result<T, U>>()
//		&& Has_greater<U, T>() && Boolean<Greater_result<U, T>>()
//		&& Has_less_equal<T, U>() && Boolean<Less_equal_result<T, U>>()
//		&& Has_less_equal<U, T>() && Boolean<Less_equal_result<U, T>>()
//		&& Has_greater_equal<T, U>() && Boolean<Greater_equal_result<T, U>>()
//		&& Has_greater_equal<U, T>() && Boolean<Greater_equal_result<U, T>>();
//};
