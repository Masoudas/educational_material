/**
* Naturally, trying to use the index operator as follows does not work:

template<typename T>
constexpr auto operator[](T t,int N)
{
	return get<N>(t);
}

* There are a couple of reasons:
*	- operator[]() must be a member, but we could handle that by defining it within Tuple. (See chapter 18,
*	  section 2).
*	- Inside operator[](), the argument N is not known to be a constant expression.
*	- I "forgot" that only lambdas can deduce their result type from their return-statement (they can however,
	  as of C++17 I guess), but that could be handled by adding a->decltype(g et<N>(t)).
*/