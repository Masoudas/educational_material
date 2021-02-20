/**
* The following example is an illustration of why we need references and enums. 
* Consider the following plain enum. So how can we iterator over all days, using a for loop?
* 
* Well, one answer is to create a vector of them. The other one however would be to override the
* operator+ for this enum. But how does one do that? Well, we need to pass the enum parameter as 
* reference and then add to it as integer.
* 
* But consider this. When we increment the value of enum, we don't set it back to first value again,
* but rather we let it go out of range! Why? Because it's in the for loop that we're supposed to check
* the enum range, not in the increment operator!!!! 
* See the example below.
* 
* Now, why not pass a pointer to the increment function instead of reference? Two reasons:
* 1-	C++ does not allow us to overload the pointer increment operator of any type!
* 2-	Even if it did, we'd say ++(&x) which looks wrong, and doesn't compile! 
* 
* In other words, to overload the increment operator of any kind, we need to pass it by reference.
*/

enum Days {
	Monday = 1, Tuesday, Wednesay, Thursday, Friday, Saturday, Sunday
};

Days& operator++(Days& m) {	// pre-increment operator
	m = static_cast<Days>(m + 1);
	return m;
}

Days operator++(Days& m, int x) {	// post-increment operator. Notice we don't return a reference here, to avoid
							// returning an stack object!
	Days temp = m;
	m = static_cast<Days>(m + 1);
	return temp; // Moved, allegedly!
}



void check_enum_increment() {
	Days d{};	// Initiates to zero, even though first is 1.
	for(; d < Sunday; ++d){}	// If we had said in the increment operator that if m = 8, then m = 1;
								// Then, this loop would have been infinite!
}