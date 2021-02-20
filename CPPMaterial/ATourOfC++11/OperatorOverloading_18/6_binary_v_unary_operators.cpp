/**
* Some operators are unary, in that they don't accept arguments and we should just overload them
* on class. Their form is like aa.operator@() or operator@(aa) (like ~, !, *, &(pointer operator), ...).
* Some unary operators can be postfix, and in fact for any such unary operator, operator@(int) is the 
* postfix version (like ++, --, etc). Note the definition of unary - operator. Free function unary ops 
* always require at least one argument of the type. Hence for example operator++(X) is pre and 
* operator++(X, int) is post increment.
* 
* The rest of operators are binary and require an argument, and their form is aa.operator@(bb) or 
* operator@(aa, bb). If both are defined (second is a free function), overload resolution determines
* which to use (and if it fails, there'd be an error!).
* 
* The following example is particulary important. Note that we're allowed to write 1 + a, because operator
* is overloaded for +(X,X). Hence, an implicit conversion takes place! 
* 
* Note that both unary and binary operators HAVE to be non-static (which makes sense, because we want the
* operators to work on a class instance, not be a generic function).
* 
* An operator can be declared only for the syntax defined for it in the grammar (§iso.A) (me: meaning random
* definition of operators with arbitrary arguments is not allowed).
*/

class X {
public:
	void operator+(int) {};
	X(int) {};
};

void operator+(X, X) {};
void operator+(X, double) {};

// void operator+(X, int) {}; Adding this causes error for a + 1.
void f(X a)
{
	a + 1; // a.operator+(1)
	1 + a; // ::operator+(X(1),a)
	a + 1.0; // ::operator+(a,1.0)
}

class UnaryOps {
public: // members (with implicit this pointer):
	UnaryOps* operator&() { return nullptr; }; // prefix unary & (address of)
	UnaryOps operator&(X) { return {}; }; // binary & (and)
	UnaryOps operator++(int) { return {}; }; // postfix increment
	// X operator&(X, X); // error : ternary
	//X operator/(); // error : unary /
};

UnaryOps operator-(UnaryOps) { return {}; };