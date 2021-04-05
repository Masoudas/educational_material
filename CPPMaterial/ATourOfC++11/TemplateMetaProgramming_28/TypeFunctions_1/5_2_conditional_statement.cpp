/**
* The std::conditional in the type_traits header is the go to structure for conditional statements. The definition of the
* template is according to the standard:
* 
* template< bool B, class T, class F >
* struct conditional;
* 
* Obviously, we need to provide a compile-time true or false in the first statement. If true, T is returned, otherwide F.
* The standard says something weird then, which I should think of in the future "The behavior of a program that adds 
* specializations for conditional is undefined."
*/

#include <type_traits>

struct checking_int_size {
	using Integer = std::conditional_t < sizeof(int) < 4, long int, int > ;

	Integer i = 10;	// On my current machine, evaluates to int, because it's actually four bytes.
};
