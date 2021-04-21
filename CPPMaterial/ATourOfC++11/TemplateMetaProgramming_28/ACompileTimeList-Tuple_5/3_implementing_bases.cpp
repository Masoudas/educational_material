/**
* Me: Had there been no constructor, then we would have had a recursion of template classes. Therefore, tuple
* of three would have had the last template as Nil, tuple of two last two as Nil, etc. The problem however is
* that manipulation of such class would have been difficult. Plus, the constructor we have here must be supplied
* with four classes. We could make the constructor parameters optional, but that would be stupid. As a
* consequence, the big guy is going to specialize all base classes, including the zero template.
* 
* We shall specialize the lower numbered templates as follows:

template<>
struct Tuple<> { Tuple() {} }; // 0-tuple

template<typename T1>
struct Tuple<T1> : Tuple<> { // 1-tuple
	T1 x;
	using Base = Tuple<>;
	
	Base* base() { return static_cast<Base*>(this); }
	const Base* base() const { return static_cast<const Base*>(this); }
	Tuple(const T1& t1) :Base{}, x{t1} { }
};

template<typename T1, typename T2>
struct Tuple<T1, T2> : Tuple<T2> { // 2-tuple, lay out: T2 before T1
	T1 x;
	using Base = Tuple<T2>;
	Base* base() { return static_cast<Base*>(this); }
	const Base* base() const { return static_cast<const Base*>(this); }
	Tuple(const T1& t1, const T2& t2) :Base{t2}, x{t1} { }
}

template<typename T1, typename T2, typename T3>
struct Tuple<T1, T2, T3> : Tuple<T2, T3> { // 3-tuple, lay out: {T2,T3} before T1
	T1 x;

	using Base = Tuple<T2, T3>;
	Base* base() { return static_cast<Base*>(this); }
	const Base* base() const { return static_cast<const Base*>(this); }
	Tuple(const T1& t1, const T2& t2, const T3& t3) :Base{t2, t3}, x{t1} { }
};

* The above implementation has the property that T1 would always have the lowest address (will come first in
* memory.) Hence, for a structure like Tuple<int, char, string, float> we have in memory:
* int <-> char <-> string <-> float
* 
* This opens some interesting optimization possibilities. Consider:

class FO { // function object with no data members // };

typedef Tuple<int*, int*> T0;
typedef Tuple<int*, FO> T1;
typedef Tuple<int*, FO, FO> T2;

* On my implementation, I got sizeof(T0)==8, sizeof(T1)==4, and sizeof(T2)==4 as the compiler optimizes away 
* the empty base classes. This is called the empty-base optimization and is guaranteed by the language.
* Me: I don't get the point of where optimization has occured. I generally don't get the memory map of classes
* either! For example a Functor has 1 byte. But a functor that has a functor as a member also is one byte.
* There could be some interesting optimization going on there.
* 
*/

