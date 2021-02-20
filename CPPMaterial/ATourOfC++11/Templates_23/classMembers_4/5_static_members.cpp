/**
* As with a normal class, if a templated class has non-const static members, they should be defined
* outside the class. constexpr and const statics can be defined inside the class, and no need to define
* them outside the class (in the scope).
*
* Note that as we said already, a static parameter can have the template type, which will be defined
* for each template type.
* 
* Just as a heads-up, a static member need only be defined if used, otherwise it can be left undefined.
*/

struct Point {
	int x, y;
};

template<typename T>
struct X {
	static constexpr Point p{ 100,250 }; // Point must be a literal type (§10.4.3)
	static const int m1 = 7;
//	static int m2 = 8; // error : not const
	static int m3;
	static void f1() { /* ... */ }
	static void f2();
};
//template<typename T> int X<T>::m1 = 88; // error : two initializers
template<typename T> int X<T>::m3 = 99;
template<typename T> void X<T>::f2() { /* ... */ }


template<typename T>
struct X1 {
	static int a;
	static int b;
};
//int* p = &X1<int>::a; Error! a should be defined. b is ok.