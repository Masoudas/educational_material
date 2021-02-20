/** This is me:
*
* A point needs clarification here. A templated type cannot be aliased without the template parameter. It
* HAS TO have a template type. 
*/

template<typename T>
struct this_is_a_class_with_a_very_long_name {

};

template<typename U>
struct user {
	// using short_name = this_is_a_class_with_a_very_long_name;	// Error! aliasing tempalated type name without temp.
	using templated_short_hand = this_is_a_class_with_a_very_long_name<U>;	// Ok! So that we have	
																	// a short hand for t
	using int_short_hand = this_is_a_class_with_a_very_long_name<int>;
};