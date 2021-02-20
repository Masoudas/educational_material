/*
* With constant references, the initialization need not to be an l-value. It can be a literal,
* or even a type that requires conversion. 
* 
* In such a case:
* 
* 1-	Any necessary conversion to type T takes place in memory.
* 2-	The result is placed in temporary location in memory (which will be removed after reference
*	goes out of scope).
* 3-	That address is assigned to our reference.
* 
* NOTE: Now we can see another advantage of using const T& as the argument for a function. That way, not only
* can we supply a type T to the function, but we can also supply a literal, or another type that can
* be converted. 
*/

void assigning_non_l_value_to_const_lvalue_ref() {
	const int& ref = 12.0;	
}

/*
* We don't use the above method (i.e, creating a temporary) for normal variables, because
* if we introduced a temporary and then assigned to it, it would have been removed after a 
* while. Hence, we directly work with the object.
*/