/**
* As we already learned in the select problem in the previous section, inheritance is the way to implement recursion at
* compile time.
* 
* Iteration involving more complicated state or more elaborate parameterization can be handled using classes. For example, 
* the factorial program becomes:
*/

template<unsigned N>
struct fact  {
	const static unsigned value = N * fact<N - 1>::value;
};

template<>
struct fact<0> {
	const static unsigned value = 1;
};

constexpr int x7 = fact<7>::value;