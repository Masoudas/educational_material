/**
* There's a relaxation to the rule that the return type of a function must be the same as the return type of the
* function it overrides.
* 
* If the original return type was B*, then the return type of the overriding function may be D*, provided B is a 
* public base of D (me: This is because the expression B* b = f() could still be written). Similarly, a return 
* type of B& may be relaxed to D&. This is sometimes called the covariant return rule.
* 
* Note that this relaxation applies only to return types that are pointers or references, and not to "smart 
* pointers" such as unique_ptr. 
* 
* (Question: What if we returned the D rather than D*, assuming base class returns B instead of B*? First, note
* that we're slicing the object, so writing B b = f() may not work seemlessly, because the base may not have
* copy constructor, whereas with references and pointers this implicit conversion always works. Therefore, the
* answer is that the return type can only be relaxed if we're retruning a pointer).
* 
* Because functions such as new_expr() and clone() are virtual and they (indirectly) construct objects, they are 
* often called virtual constructors. Each simply uses a constructor to create a suitable object.
* 
* virtual constructors are very important, as they give us a change to create an object without knowing its type.
* To make an object, a constructor needs the exact type of the object it is to create. Consequently, a constructor 
* cannot be virtual. Furthermore, a constructor is not quite an ordinary function. In particular, it interacts with 
* memory management routines in ways ordinary member functions don’t. So, you cannot take a pointer to a constructor 
* and pass that to an object creation function
*/

class Expr {
public:
	Expr() {}; // default constructor
	Expr(const Expr&) {}; // copy constructor
	virtual Expr* new_expr() = 0;
	virtual Expr* clone() = 0;
};

class Cond : public Expr {
public:
	Cond() {};
	Cond(const Cond&) {};
	Cond* new_expr() override { return new Cond{}; }	// Relaxing the return type!
	Cond* clone() override { return new Cond{*this}; } // Relaxing the return type!
};