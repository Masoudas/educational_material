/**
* To initialize the base portion of a class, we can explicity call the base class, like we do any
* other parameter, as follows.
* 
* The bracket notation is called universal initialization, because it can be used everywhere for
* every type. Bjarne says whenever we say T{v},  the same value of type T(T{v}) is created (me: which means
* copy, then move). This is not the case for = or () initialization. For example, below we can't say:
* 
* %%  derived(int i, int j) : base{i}, j = j{}
* 
* A famous example of () not working is "derived var()". This would in fact define a function
* returning derived called var!
* 
* Finally, never forget {} does not allow narrowing. For example, we can't say int x{1.1}.
*/
struct base {
	base(int i){}
};

struct derived : base {
	int j;

	derived(int i, int j) : base{i}, j(j){}	// Initializing base portion of the class.
};