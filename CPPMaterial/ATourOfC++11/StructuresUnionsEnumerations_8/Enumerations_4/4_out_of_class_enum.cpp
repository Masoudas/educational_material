/**
* We are only allowed to define a plain enum outside the class, if the underlying type is specified.
* Otherwise, the enum has to be fully defined inside the class
* This does not seem to be a good approach though. Because first, we have to add the class before the enum 
* defintion outside the class. And when we do so, it will turn into an enum class instead of a plain enum, 
* which in turn implies that we can't use it without scoping.
* 
* But then again, it's weird that VS allows us to do so, and does not complain!
*/

class class_with_enum {
	// enum E1; Wrong. No type is specified
	// enum E2 : char; It was supposed to be defined this way!
	enum E2 : char {e1, e2}; // But apparently it's fine this way

	enum class C1; // Fine.
	void f(E2 x);
};

enum class class_with_enum::C1 { c1, c2 };
// enum class class_with_enum::E2 : char { e1, e2 }; It was supposed to be define this way!