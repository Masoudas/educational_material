/**
* To handle const cases, we need only to add a const version of the getNth method to our classes:
* Note: Recall that the template deduction rule is that for cv qualified parameters, cv qualifier is removed
* (chapter 23, section 10, 3_3). However, when resolving overloads, priority is given to the const method, and
* we're done.

template<typename Ret, int N>
struct getNth { // getNth() remembers the type (Ret) of the Nth element
	template<typename T>
	static Ret& get(T& t) // get the value element N from t’s Base
	{
		return getNth<Ret,N−1>::get(*t.base());
	}
	template<typename T>
	static const Ret& get(const T& t) // get the value element N from t’s Base
	{
		return getNth<Ret,N−1>::get(*t.base());
	}
};

template<typename Ret>
struct getNth<Ret,0> {
	template<typename T> static Ret& get(T& t) { return t.x; }
	template<typename T> static const Ret& get(const T& t) { return t.x; }
}

template<int N, typename T1, typename T2, typename T3, typename T4>
Select<N, T1, T2, T3, T4>& get(Tuple<T1, T2, T3, T4>& t)
{
	return getNth<Select<N, T1, T2, T3, T4>,N>::get(t);
}

template<int N, typename T1, typename T2, typename T3>
const Select<N, T1, T2, T3>& get(const Tuple<T1, T2, T3>& t)
{
	return getNth<Select<N, T1, T2, T3>,N>::get(t);
}

*/