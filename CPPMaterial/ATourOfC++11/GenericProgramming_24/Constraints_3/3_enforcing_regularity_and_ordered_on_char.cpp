/**
* As first example, we want to impose the ordered and regular concepts on a char type given to a string.
* 
* First of all, notice again that we use constexpr functions (and not structs) to check the constraints here. 
* Second, notice that an ordered type is both regular and totally orderable. Third, notice that a totally ordered
* type has the following properties:
* 
* 1- It has less operator, and the result of that less operator is a boolean convertible (an int is also Ok, but not
* an string for example).
* 2- It has greater operator, and the result ...
* 3- It has less equal operator, and the ...
* 4- It has greater than equal operator, and the ...
* 5- The type is also equaly comparable, which implies that it has both the equal and not equal operators, and the
*	 result of both of them is boolean.
* 
* We can of course write the same set of constrains on regular as well. (Me: I've partially implemented the regular
* concept using the type_traits library, but I couldn't find any checks for 'is possible to get address'.)
* 
* Has_equals is implemented using enable_if and the techniques described in chapter 28.
* 
* The big guy also says "I capitalize my constraints names (e.g., Regular) even though doing so violates my 'house
* style' of capitalizing type and template names, but not functions. However, concepts are even more fundamental 
* than types, so I feel a need to emphasize them. I also keep them in a separate namespace (Estd) in the hope that 
* very similar names will eventually become part of the language or the standard library".
* 
* Finally, note that constraints can be checked inside a function, like we do for the streaming function. Note also
* that we check that it's both in and out streamable, even though only out is required for this case.
*/
#include <type_traits>
#include <iostream>

//template<typename T>
//constexpr bool Equality_comparable()
//{
//	std::
//	return Has_equal<T>() && Boolean<Equal_result<T>>()
//		&& Has_not_equal<T>() && Boolean<Not_equal_result<T>>();
//}

//template<typename T>
//constexpr bool Totally_ordered()
//{
//	return Equality_comparable<T>() // has == and !=
//		&& Has_less<T>() && Boolean<Less_result<T>>()
//		&& Has_greater<T>() && Boolean<Greater_result<T>>()
//		&& Has_less_equal<T>() && Boolean<Less_equal_result<T>>()
//		&& Has_greater_equal<T>() && Boolean<Greater_equal_result<T>>();
//}

//template<typename T>
//constexpr bool Ordered()
//{
//	return Regular<T>() && Totally_ordered<T>();
//}

template<typename T>
constexpr bool Semiregular() {
	return std::is_copy_constructible_v<T> && std::is_copy_assignable_v<T> && std::is_default_constructible_v<T>
		&& std::is_destructible_v<T> && std::is_move_constructible_v<T> && std::is_move_assignable_v<T> ;
}

//template<typename T>
//constexpr bool Regular()
//{
//	return Semiregular<T>() && Equality_comparable<T>();
//}

//template<typename C>
//class String {
//	static_assert(Ordered<C>(), "String's character type is not ordered");
//	// ...
//};

/////////////////////// Checking for streamable
//template<typename T>
//constexpr bool Streamable()
//{
//	return Input_streamable<T>() && Output_streamable<T>();
//}
//
//template<typename C>
//ostream& operator<<(ostream& out, String<C>& s)
//{
//	static_assert(Streamable<C>(), "String's character not streamable");
//	out << '"';
//	for (int i = 0; i != s.size(); ++i) cout << s[i];
//	out << '"';
//}

//int main() {
//	static_assert(Semiregular<char>(), "char is not regular");
//
//	std::cout << "Turns out, char is regular!";
//}