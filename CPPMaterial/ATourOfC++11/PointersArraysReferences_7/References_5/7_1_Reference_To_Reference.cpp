/*
* 
* Reference to reference can happen only as a result of alias or template parameters, or auto (as we discuss next). 
* In other words, the  following is incorrect:
* int&& & a = 5;	// Incorrect
* int&&& b = 5;		// Incorrect.
* 
* However, we have the following:
* 
* using rr_i = int&&;
* using lr_i = int&;
* using rr_rr_i = rr_i&&;	// This is rvalue
* using lr_lr_i = lr_i&;	// This would be a reference, because we have a single &. lvalue ref always wins
* using rr_lr_i = l_ri&&;	// Again, lvalue ref wins!
* using lr_rr_i = rr_i&;	// One again, lvalue ref wins.
* 
* When we have an lvalue ref, we cannot change it rvalue ref. Note that for example that we can say int&& x = 10,
* and then int& y = x; Hence, x is still an object in memory, and it can have lvalue reference.
* 
* (Me: Again, I think not being able to change an lvalue to an rvalue is a way of telling the compiler not to
* worry about the reference I guess, rather than a matter of semantics).
*/