/**
* The Tuple class (of four class templates) will be derived from that of a three template base. Such type of
* implementation is apparently very common. Notice the aliasing to base, which is not the same as dragging
* the base constructors (using Tuple<T2, T3, T4>::). Also, notice the two methods to get the base pointer.
* Why are they necessary? Because we can simply convert to base? It's just a convenience method, as that we
* can avoid repeated static casts.

template<typename T1=Nil, typename T2=Nil, typename T3=Nil, typename T4=Nil>
struct Tuple : Tuple<T2, T3, T4> { // layout: {T2,T3,T4} before T1
	T1 x;
	using Base = Tuple<T2, T3, T4>;
	
	Base* base() { return static_cast<Base*>(this); }
	const Base* base() const { return static_cast<const Base*>(this); }
	Tuple(const T1& t1, const T2& t2, const T3& t3, const T4& t4) :Base{t2,t3,t4}, x{t1} { }
};

* So, a Tuple of four elements (often referred to as a 4-tuple) is a Tuple of three elements (a 3-tuple)
* followed by a fourth element. 
* We construct a Tuple of four elements with a constructor that takes four values (potentially of
* four different types). It uses its last three elements (its tail) to initialize its base 3-tuple and the 
* first (its head) to initialize its member x.
* 
* Me: Why do we need this recursive implementation? Well, we obviously want some sort of get method, that much
* is clear. Moreover, we don't want to use some kind of a container to keep the elements (naturlich.) Hence,
* we're left with the idea of recursion between base and derived classes. Obviously, we could have just simply
* used T1 to T4 as four parameters, but the point of this example is to prepare us for the unlimited case
* using variadic arguments.
*/

