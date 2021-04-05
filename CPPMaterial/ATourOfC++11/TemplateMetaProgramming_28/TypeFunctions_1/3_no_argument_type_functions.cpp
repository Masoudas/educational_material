/**
* me: Note that the argument of a type function. Hence, a type function that takes no type is considered a no argument type.
* However, such a function would take value templates.
* 
* Most type functions take at least one type argument, but there are useful ones that don’t. For example, here is a type 
* function that returns an integer type of the appropriate number of bytes:
* 
* me: 
*	1-	Recall that the big guy implemented this function in another form, using specialization for 1, 2, 4, etc.
*	2-	Naturlich, we need either a multilevel if statement here. We'll implement it as such, using nested 
*		std::conditional. Note that there's no function in std for such a selection, but we can use an interesting slight
*		of hand and implement this using specialization. This will be again discussed in this chapter.
* 
* We shall later on give a formal defintion of std::conditional, but for now, we shall only use it.
* 
*/

#include <type_traits>

// using multilevel conditional. Believe it or not, this does actually compile!!!
template<int N>
struct int_selector {
	using Error = void;
	using type = std::conditional_t<N==1, char, 
						std::conditional_t<N==2, short, 
							std::conditional_t<N==4, int,
								std::conditional_t<N==8, long, Error>>>>;
};



template <int N, typename T1, typename T2, typename T3, typename T4>
struct Select{
	using type = void;	// This would all non-specialized cases, for example N = 3 in above.
};

// Didn't know this one! Note that we omit the first type totally!
template <typename T1, typename T2, typename T3, typename T4>
struct Select<0, T1, T2, T3, T4> {
	using type = T1;
};

template <typename T1, typename T2, typename T3, typename T4>
struct Select<1, T1, T2, T3, T4> {
	using type = T2;
};

template <typename T1, typename T2, typename T3, typename T4>
struct Select<2, T1, T2, T3, T4> {
	using type = T2;
};

template <typename T1, typename T2, typename T3, typename T4>
struct Select<3, T1, T2, T3, T4> {
	using type = T3;
};

template<int N, typename T1, typename T2, typename T3, typename T4>
using Select_t = typename Select<N, T1, T2, T3, T4>::type;

template<int N>
struct int_selector_with_select {
	using Error = void;
	using type = Select_t<N, char, short, int, long>;
};
