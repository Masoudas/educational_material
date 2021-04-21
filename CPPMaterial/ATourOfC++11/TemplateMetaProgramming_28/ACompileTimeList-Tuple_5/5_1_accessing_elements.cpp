/**
* As defined, Tuple has a variable number of elements of potentially differing types. We would like to access 
* those elements efficiently and without the possibility of type system violations (i.e., without using casts). 
* We can imagine a variety of schemes, such as naming the elements, numbering the elements, and accessing 
* elements by recursing though the elements until we reach a desired element. The last alternative is what we 
* will use to implement the most common access strategy: index the elements. In particular, I want to 
* implement a way to subscript a tuple. Unfortunately, I am unable to implement an appropriate operator[], so 
* I use a function template get()

auto element = get<0>();

* The idea is to index the elements, starting from 0, in such a way that the element selection is done at 
* compile time and we preserve all type information. The get() function constructs an object of type 
* getNth<T,int>. The job of getNth<X,N> is to return a reference to the Nth element, which is assumed to have 
* type X. Given such a helper, we can define get():

template<int N, typename T1, typename T2, typename T3, typename T4>
Select<N, T1, T2, T3, T4>& get(Tuple<T1, T2, T3, T4>& t)
{
return getNth<Select<N, T1, T2, T3, T4>,N>::get(t);
}

* The definition of getNth is a variant of the usual recursion from N down to the specialization for 0:
* (Me: Notice the use of the template in function return. The template is auto deduced, because we know the
* type of T)

template<typename Ret, int N>
struct getNth { // getNth() remembers the type (Ret) of the Nth element
	template<typename T>
	static Ret& get(T& t) // get the value element N from t’s Base
	{
		return getNth<Ret, N−1>::get(*t.base());
	}
};

template<typename Ret>
struct getNth<Ret,0> {
	template<typename T>
	static Ret& get(T& t) { return t.x; }
};

* This is quite a bit of scaffolding to index into a Tuple, but at least the resulting code is type-safe and 
* efficient. By "efficient," I mean that given a reasonably good compiler (as is common), there is no run-time 
* overhead for accessing a Tuple member.
*/