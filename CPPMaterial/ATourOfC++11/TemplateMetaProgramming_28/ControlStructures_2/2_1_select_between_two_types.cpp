/**
* It is surprisingly simple to implement Conditional. The conditional template is part of the standard library (in 
* <type_traits>), so we don’t have to implement it, but it illustrates an important technique.
* 
* The primary template simply defines its type to be T (the first template parameter after the condition). If the 
* condition is not true, the specialization for false is chosen and type is defined to be F.
* 
* Obviously, the syntax leaves a bit to be desired, but the underlying logic is beautiful.
* 
* 
*/

template<bool C, typename T, typename F>
struct conditional {
	using type = T;	// True case
};

// Partial specialization (chapter 23)
template<typename T, typename F>
struct conditional<false, T, F> {
	using type = F;
};

template<bool C, typename T, typename F>
using conditional_t = typename conditional<C, T, F>::type;