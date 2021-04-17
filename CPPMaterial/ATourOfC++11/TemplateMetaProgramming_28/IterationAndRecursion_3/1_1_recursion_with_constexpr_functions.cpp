/**
* A famous computation is the factorial calculation, which can be implemented at compile time using recursion.
* 
* In general, if we want to iterate over a set of values at compile time, we use recursion.
* 
* Note the absence of a condition: there is no N==1 or N<2 test. Instead, the recursion is terminated when the call of 
* fac() selects the specialization for N==1. In template metaprogramming (as in functional programming), the idiomatic way 
* of working your way through a sequence of values is to recurse until you reach a terminating specialization.
* 
* me: I wonder if actually writing the contexpr if is slowing the computation. Perhaps not, because after all, the compiler
* has to choose the 1 case. Perhaps the big guy argues this because 'if constexpr' hadn't been invented yet in C++11.
*/

template<unsigned N>
constexpr unsigned fact() {
	if constexpr (N == 0){
		return 1;
	}

	return N * fact<N - 1>();
}

/**
* Notice the implementation before if constexpr required a specialization:

template<int N>
constexpr int fac()
{
	return N * fac<N−1>();
}

template<>
constexpr int fac<1>()
{
	return 1;
}

*/