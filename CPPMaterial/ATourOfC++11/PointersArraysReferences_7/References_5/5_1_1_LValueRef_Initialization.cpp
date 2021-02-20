/*
* Initialization of an l-value ref with it's own type l-value is trivial.
* T& ref = T;
* 
* However, if there's any conversion involved when initializing with l-value, and error is
* returned. For example, we can't initialize a reference to an int with float r-value. This
* is to be expected. Why? Because we can think of a reference also as an address holder. Normally,
* we can't assign the address of a float to an int pointer. Hence, the case for reference.
* However, for class hierarchies, this conversion does not occur, hence this is allowed.
*/
class A{};
class B : public A{};

void cant_assign_reference_when_conversion_is_needed(float r) {
	// int& ref = r; This returns an error.
	B b{};
	A& a = b;	// This is fine! Referring the A part of B.
}