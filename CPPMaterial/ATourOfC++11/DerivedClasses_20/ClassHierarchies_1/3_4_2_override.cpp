/**
* If we were to be explicit about our desire to override, specifiying override would result in seeing the mistakes 
* made in the example in 3_4_1.
* 
* In a large or complicated class hierarchy with many virtual functions, it is best to use virtual only to introduce
* a new virtual function and to use override on all functions intended as overriders. Using override is a bit  
* verbose but clarifies the programmer’s intent. Override comes last in the declaration of a function.
* 
* A method can be both virtual and override (of course if it's not defined in the parent class). The big guy yells
* berating us 'And yes, it’s illogical that virtual is a prefix and override is a suffix. This is part of the price 
* we pay for compatibility and stability over decades.'
* 
* An override specifier is not part of the type of a function and cannot be repeated in an out-of class definition.
* 
* Curiously, override is not a keyword; it is what is called a contextual keyword. That is, override has a special 
* meaning in a few contexts but can be used as an identifier elsewhere. The only reason that override is a 
* contextual keyword, rather than an ordinary keyword, is that there exists a significant amount of code that has 
* used override as an ordinary identifier for decades. The other contextual keyword is final.
*/

struct B0 {
	void f(int) const;
	virtual void g(double);
};

struct B1 : B0 { /* ... */ };
struct B2 : B1 { /* ... */ };
struct B3 : B2 { /* ... */ };
struct B4 : B3 { /* ... */ };
struct B5 : B4 { /* ... */ };

struct D : B5 {
	// void f(int) const override; // error : B0::f() is not virtual
	// void g(int) override; // error : B0::f() takes a double argument
	// virtual int h() override; // error : no function h() to override

};