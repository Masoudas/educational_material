/**
* Here are some of the very important functions of unique_ptr:
* - explicit bool()(): For conversion to a bool, and explicit (which as we may recall, does not affect the if 
* loop implicit conversion).
* - operator*(); Value of the pointer. for contained non-arrays only
* - operator->(): Dereferences the pointer. for contained non-arrays only.
* - operator[](): equivalent to cp[n], where 'cp' is the underlying pointer (me: appears only if initialized with
*	T[]).
* - release(): Returns the pointer, and sets the underlying pointer to null.
* - up.reset(p): Calls delete on current pointer, then sets the value to p.
* - up.reset(): Deletes the underlying pointer.
* - up.swap(up2): Swaps the value of the two pointers.
* - operator <=>: For comparing the value of two pointers.
* 
* Note that for T[], an specialization has been written. Note that we should always use this specialization for
* arrays. We can delete the pointer with a delete, which implies just destroying the first element of an array, 
* which is an error. 
* 
* To avoid slicing, a Derived[] is not accepted as an argument to a unique_ptr<Base[]> even if Base is a public 
* base of Derived. See an example below.
*/

#include <memory>

void the_star_operator_of_unqiue_ptr() {
	std::unique_ptr<int> int_ptr = std::unique_ptr<int>{ new int{5} };

	// Very well, this is a pointer for an array, but no [] operator would be supplied.
	std::unique_ptr<int> int_arr_ptr = std::unique_ptr<int>{ new int[10]{5} };

	// This initialization provides a bracket operator
	std::unique_ptr<int[]> better_int_arr_ptr = std::unique_ptr<int[]>{ new int[10]{5} };

	// Recall that the following would generate a pointer to pointer array.
	std::unique_ptr<int*> int_arr_arr_ptr = std::unique_ptr<int*>{ new int*[2]{nullptr, nullptr} };

	int ptr_int = *int_ptr;
	int ptr_arr_int = *int_arr_ptr;	// No problem again
	int* ptr_int_arr_arr = *int_arr_arr_ptr;	

	int second_element = better_int_arr_ptr[1];	// Ok! But how is this implemented?
	// auto ptr = *better_int_arr_ptr; Error! No getting back the pointer like this!
	int* ptr = better_int_arr_ptr.get(); // The underlying array however is an int pointer, as expected!	
}




