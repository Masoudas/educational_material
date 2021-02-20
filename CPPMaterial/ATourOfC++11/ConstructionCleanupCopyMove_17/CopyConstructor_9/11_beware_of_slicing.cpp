/**
* Slicing is the situation where a class is partially copied, because we're changing reference
* from derived class to base class.
* 
* The situation can be obscure as shown below! It only happens when we try to create an object of
* base type from a derived type. This happens, because constructors cannot be virtual.
* 
* If we never invoke a copy, that is always use the pointer, this problem cannot occur.
* However, to explicitly avoid this situation:
* 1-	Delete base class copy constructor. That way, we cannot do the assignment base ptr_2 = *ptr.
* 2-	Inherit the class private or protected, to fully prohibit reassignment to base reference.
* 
* A more sophisticated case of slicing is discussed in Chapter 20, 0_2_pointer_vs_no_pointer_base_access
*/

struct base {
	int base_i = 1;
};


struct derived : base {
	int derived_i = 2;
};

void accepting_pointer_to_base(base *ptr) {
	base ptr_2 = *ptr;	// Here, only the copy constructor of base is invoked. objects are very naive in C++.
}

void slicing_by_assigning_to_base() {
	derived d1{};

	base b1 = d1;	// This would once again slice.
}

void accepting_reference_to_base(base& ref) { // This is no problem, because no copy is called here!

}


