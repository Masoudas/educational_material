/**
* Here's a very interesting problem I encountered once.
* 
* Consider the following class, in which I define an alias for std::tuple. Now, I define an ostream operator for
* this alias as a friend function, but we see that we can't find the operator. Why is that?
* 
* First of all, note that the friend operator does not belong to S scope. It belongs to the global scope. This is
* because this definition is equivalent to saying that:
* 
* struct S{
*	friend std::ostream& operator<<(std::ostream& o, const my_tuple&);
* }
* std::ostream& operator<<(std::ostream& o, const my_tuple&){...}
* 
* So the definition is supposedly on the outside (the operator is a friend, not part of the class!). Now, why 
* can't the compiler find it?  
* 
* First of all, note that just because my_tuple is aliased inside S doesn't mean that the operator should be its
* friend. tuple is part of std, and the operator is not going to access the private parts of S!
* Second, Suppose we did indeed define the operator outside in the global namescope. Then, the compiler would not
* be able to find it, because S is the current scope, not global! So through ADL, we'll go to std namespace! I 
* don't understand why the solution with std does not work!
*/
#include <tuple>
#include <iostream>
struct S {
	using my_tuple = std::tuple<int, int, int>;

	//friend std::ostream& operator<<(std::ostream& o, const my_tuple&);
	void using_stream_operator(S& o1, S& o2) {
		// std::cout << m;
		o1 + o1;
	}
};

//namespace std {
//	std::ostream& operator<<(std::ostream& o, const std::tuple<int, int, int>&) { return o; };
//}

S& operator+(S& o1, S& o2) {
	return o1;
}


