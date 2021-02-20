/*
* The basic idea of having different kind of references is to support DIFFERENT USES of the object (the 'use' 
* is key here):
* -	non const lvalue: Refers to an object to which we can write.
* -	const lvalue: Refers to temp objects in the memory (or const objects), which the user can't modify.
* -	r-value reference: refers to a temporary object, which the user can (and typically will) modify, assuming
*	the object will never be used again (By modify we mostly mean empty-up).
* 
* Before we continue, we should remember to distinguish between an rvalue and rvalue reference. The former is a
* value that is (almost) not an lvalue, and it goes to the right of an assignment operation, whereas the latter
* is like an implicit pointer to that. Hence for example, a constructed object in brackets is an rvalue, or the
* return value of a function is an rvalue (because we can't assign to it). 
*/
#include <iostream>
#include <string>
using namespace std;

/**
* rvalue references are used to extend the life of temporary object. Essentially, they act like a reference,
* but for temporaries rather than normal objects. In other words, rvalue ref could be considered a pointer
* that points to a temporary location in memory, and not a permanent location like a normal pointer. Hence,
* an rvalue reference will act like an lvalue reference after it's definition, allowing for changing the object
* through reference, because now the object has indeed a location in memory.
*
* Again, notice that when we define an rvalue reference to an lvalue (with a cast of course), we're essentially
* doing the same thing. We're declaring that (to the compiler and user) the lvalue object is now considered temp,
* and shall be nulled (again, only intent, and no action), and we can do so because the rvalue reference is now
* an lvalue reference.
*
* Also once again, note the contrast between an rvalue and a const lvalue. Even though we can assign a temp to
* both, only the former allows for changing the object with the reference.
*/
void using_rvalues_for_temporaries() {
	string s1{ "my string 1" };
	string s2{ "my string 2" };

	// string&& s3 = s1; Error! Assigning lvalue to rvalue (or assigning non-temporary object to temporary ref).
	string&& s3 = s1 + s2;	// Cool! The return value of a function is a temporary, so long as it's not assigned
							// a location in memory!
	s3[0] = 'a';	// Playing with my temprary, because I have an lvalue reference to it now!

	string s4 = s3;	// Don't be deceived, this is a copy construction!!!
	string s5 = std::move(s3);	// Now this is a move assignment! s3 is now nulled!
}

/**
* NOTE THAT WE ARE EXPRESSING INTENT, not actually defining an action with rvalue ref. We're just declaring the
* object that is passed by this reference is (probably) never going to be used again.
* This is why when an rvalue is passed to constructors they steal resources (so to speak).
* The user has declared they don't want to use this object again. Having an rvalue
* reference in and of iteself does nothing. For example, we can check that for value types, the following code
* leaves x unchanged:
* string&& x = 'my string;
* // Some other operations
* ....
* x is never emptied up, because it wasn't assigned to another object.
*
* As Bjarne says: "We want to know if a reference refers to a temporary. because if it does, we can sometimes
* turn an expensive copy operation into a cheap move operation"
* This is what an r-value ref and a const lvalue ref have in common. Both of them refer to temporary object.
* However, with const lvalue, the compiler knows it's temp. With rvalue, we express it in terms of code that
* the object at hand is temporary, so if you give it to us, our code, you will not give it back (probably),
* because you and we agree that the object is temporary (intent).
*
* Hence for example, "An object (such as a string or a list) that is represented by a small descriptor
* pointing to a potentially huge amount of information can be simply and cheaply moved if we know that
* the source isn’t going to be used again". And that source usually is just a pointer, which we assign
* to the new object in the move constructor.
*
*/
int assiging_to_r_value_ref() {
	int&& ref_to_literal = 120;
	int&& ref_to_function_return = assiging_to_r_value_ref();

	int val = 10;
	// int&& not_allowed{ val };
	const int& val1{ 10 };	// Ok. Binding temporary to constant ref.

	return 0;
}

/**
* Even though we can, we don't say const T&&. This is because we want to take advantage of the 
* move operations associated with r-value references. In fact:
* 
* 1-	const T&: Are used for binding temporary, types with conversion and constants to a ref.
* 2-	const T&&: Are used for a destructive read of a temporary, which is an optimization, for something that
*	otherwise would require a copy.
* 
* Now, we can see this with the swap example. 
* We now see that the old swap method uses the copy constructor to create a temp copy.
* But we indeed didn't need temp. What we needed was to move the content of a to temp (making a void
* of anything). Then move b to a, them move temp to a. All of this can be achieved using the 
* r-value reference.
* 
* rvalue ref copy does not steal reference from value types (should it)?
*/

template<typename T>
void swap_using_reference(T& a, T& b) {
	T temp = a;	// Here, a copy constructor is used to initialize temp.
	a = b;
	b = temp;
}

template<typename T>
void swap_using_rvalue_reference(T& a, T& b) { // Perfect swap (almost). We take lvalue ref to be able to assign 
												// objects.
	T temp = static_cast<T&&>(a);	// Now, a is moved to temp, instead of copied (Move constructor).
	cout << a << ": a is empty now!";
	a = static_cast<T&&>(b);	// b is moved to a, instead of copied. (Me: This would be move assignment)
	cout << b << ": b is empty now!";
	b = static_cast<T&&>(temp);	// temp is moved to a, instead of copied. (Me: This would be move assignment)
}


void checking_on_calling_by_reference() {
	string s1{ "This is a" };
	string s2{ "This is b" };
	swap_using_rvalue_reference(s1, s2);	
}

/**
* One thing to note regarding rvalue templates is that in the same way a const T& uses implicit conversion,
* T&& also uses implicit converstion to extend the life of the temporary.
*/

void r_value_references_use_implicit_conversion() {
	std::string&& temp = "const char* is implicitly converted to string";
}