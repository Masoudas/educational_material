/**
* Using a constructor taking a single argument to specify type conversion is convenient but has implications that can be 
* undesirable. Also, a constructor cannot specify:
* [1]: an implicit conversion from a user-defined type to a built-in type (because the built-in types are not classes), or
* [2] a conversion from a new class to a previously defined class (without modifying the declaration for the old class).
* 
* These problems can be handled by defining a conversion operator for the source type. The notion 'X::operator T()' can
* be used for such conversions. The notions vary, but they all indicate the same thing:
* 
* operator B()	// convert this type to type B.
* operator B&()	// convert this type to type reference of type B (and not pointer).
* operator B*()	// convert this type to to pointer of type B.
* template<typename T>
  operator T*() { return 0;}	// Convertion to function template.
* operator U1 T2::*()	// Convert a pointer of type T2 to U1
*/

struct B{};

struct A {
	operator B*() {
		return new B{};
	}

};

void conversion_examples() {
	A a{};
	B* ptr = a;
}