/**
* Note that a function can have its own templates. Later, we'll see that even the constructor
* can be overloaded with its own template parameters.
*/

template<typename T>
struct X {
	void mf1() { /* ... */ } // defined in-class
	void mf2();
};

template<typename T>
void X<T>::mf2() { /* ... */ } // defined out of class