/**
* The implementation of enable_if is almost trivial (me: What's the point of defaulting to void?! Also, note
* that void itself can't be instantiated. However, recall that we have void pointer, or pointer to void pointer,
* etc.
* 
* Note that we can leave out the type argument and get void by default (me: This allows using them directly
* as merely a conditional for functions that return void!)
*/

template<bool condition, typename T = void>
struct enable_if {
	using type = T;
};

template<typename T>
struct enable_if<false, T>{};

template<bool condition, typename T = void>
using enable_if_t = typename enable_if<condition, T>::type;
