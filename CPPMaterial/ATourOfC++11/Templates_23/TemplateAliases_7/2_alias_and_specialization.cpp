/**
* The equivalence of the alias and the original template implies that if you specialize the template, you 
* (correctly) get the specializations when you use the alias.
* 
* For example below, If specializations did not get used through the alias, we couldn’t claim that int_exact was 
* simply an alias for int_exact_traits<N>::type; they would behave differently. On the other hand, you cannot 
* define a specialization of an alias. If you had been able to, it would have been rather easy for a human reader 
* to get confused about what was specialized, so no syntax is provided for specializing an alias.
* 
*/

template<int>
struct int_exact_traits { // idea: int_exact_traits<N>::type is a type with exactly N bits
	using type = int;
};

template<>
struct int_exact_traits<8> {
	using type = char;
};

template<>
struct int_exact_traits<16> {
	using type = short;
};

template<int N>
using int_exact = typename int_exact_traits<N>::type; // define alias for convenient notation

int_exact<8> a = 7; // int_exact<8> is an int with 8 bits
