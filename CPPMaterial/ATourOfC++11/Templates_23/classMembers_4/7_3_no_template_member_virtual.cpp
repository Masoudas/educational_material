/**
* A templated member cannot be virtual. Don't forget that we're talking about a member that has
* templates of its own, not a templated class.
* 
* The reason why this is unacceptable is that everytime f1 were called, linker would have had to add
* a new implementation to the table of virtual functions of the same class. This was considered difficult in
* the language design, and was not considered.  In particular, handling dynamic linking would require 
* implementation techniques rather different from what is most commonly used.
*/
template <typename T>
struct X {
	virtual void f(T t) = 0;

	/*template<typename U>
	virtual void f1(U u) = 0;*/	// Impossible
};