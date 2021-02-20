/**
* Naturlich, when people create smart pointers, they think of creating -- and ++ operators that go alongside them as well.
* A smart pointer with such operators looks something like this:
* 
* Note that the big guy himself checks for the fact that -- and ++ point to proper positions, by adding some ifs and checks.
* We should also ask ourselves, how should a pointer behave correctly with respect to inheritance. This shall be discussed 
* later.
*/

template<typename T>
class Ptr {
	T* ptr;
	T* array;
	int sz;
public:
	template<int N>
	Ptr(T* p, T(&a)[N]) {}; // bind to array a, sz==N, initial value p
	Ptr(T* p, T* a, int s) {}; // bind to array a of size s, initial value p
	Ptr(T* p) {}; // bind to single object, sz==0, initial value p
	Ptr& operator++() { *this; }; // prefix
	Ptr operator++(int) { *this; }; // postfix
	Ptr& operator--() { *this; }; // prefix
	Ptr operator--(int) { *this; }; // postfix
	T& operator*() { *this; }; // prefix
};