/*
* Question: If for class X, I say X x = X{}, would I be using copy constructor or move constructor to
* set x to X{}?
* 
* Answer: Obviously move. But why? Because the argument of the copy constructor is const X&, so it can accept
* X{}. However, in such a case, we'd be doing an unnecessary copy. The compiler would NEVER do this for a temp
* object, that's about to get destroyed. Hence, it uses move constructor.
*/

struct cp_or_mv {

};

void f_using_cp_or_mv(cp_or_mv s1) {
	cp_or_mv s = cp_or_mv{};	// Ok! creates using default constructor and then moves.

	f_using_cp_or_mv(cp_or_mv{});	// Again, first creates the object, then moves! This is the reason why
									// it's preferable to initiate the object using just {}, so that only
									// construction takes place.

	f_using_cp_or_mv({});
}