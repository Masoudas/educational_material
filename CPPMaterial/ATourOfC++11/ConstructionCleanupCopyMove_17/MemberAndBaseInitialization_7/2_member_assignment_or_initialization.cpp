/*
* As we already know, for references and consts, initialization must be done memberwise.
* 
* For other members however, we have a choice of using assignment (=) or initialization. Assignment
* is what we do in most other languages (like Java for example).
* 
* (Me: Say we have a user defined type as member. When we initialize a class, it will call a constructor 
	of that member, which is the default one. So if I try to assign to it, like I do in Java, then I've
	done a construction and an assignment. This is not efficent, which is why we must avoid assignments
	and use initialization).

* When initializaing, we tend to avoid assignment and use initialization, even though both are acceptable.
*/
struct member {

};

struct my_struct {
	int i;
	member m1;
	my_struct(): i(10){}	// member initialization.
	my_struct(int j) { i = 20; m1 = {}; }	// Assignment initialization. Reassigning to m1, which is already
										// constructed.

};