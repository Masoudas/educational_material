/**
* First, note that the return value of a function that does not return an lvalue or an rvalue is an lvalue (or
* a temporary). Why? Because it has no name! simple as that! If we leave it dangling in the code, we can't point
* to it with a name. Hence, it's an rvalue. Note that the return value of a function that returns by reference 
* is not an rvalue, because we can refer to the name of that object, using the function name!
* 
* Note that essentially we can't extend the lifetime of a temporary by returning an rvalue reference. Now that
* we know this, it does actually make sense, because for example we can't return an auto variable with reference,
* right? So essentially, we get a dangling rvalue reference!
* 
* So, Why would a function need to return an rvalue reference then? 
* 
* Well, we can think of several reasons:
* 1- If a function returns an rvalue reference, we can assign to that return value, whereas with a normal 
* function we can't do that.
* 2- Some functions (like std::move) actually make it their business to create an rvalue reference.
* 3- Optimization. For example, if a function accepts rvalues instead of values for an operation, we can return
* rvalue reference. See this for the min function below. If we returned an int from this function, a copy would 
* take place, and if we returned a reference, in addition to losing the semantics by changing rvalue to lvalue,
* (I'm not sure, but probably would lose performance because an lvalue reference points to an object that's going
* to remain in memory, thus more tracking of memory location is probably required for it!).
* 3- rvalue reference post-fix methods: So imagine a method has rvalue post fix (like in rval_class below). We 
* can see that returning an lvalue is more desirable, because like 3, returning an object requires a copy, and
* returning an lvalue reference misses the point.
*/
#include <utility>

int&& returning_a_reference_to_a_temporary_is_wrong() {
	return 1;	// This temporary object will still be destroyed, and returning a reference to it is wrong.
}

int&& min(int&& lhs, int&& rhs) {
	return std::move(lhs > rhs ? rhs : lhs);
}

struct rval_class {
	int x = 10;
	int&& m() && {
		return std::move(x);
	}
};
