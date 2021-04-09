/**
* The big guy argues: "The technique we used in the previous example is a most useful and powerful technique, but:
*	- It is verbose.
*	- It often bundles otherwise weakly related type functions.
*	- It exposes implementation details to users.
* 
* Also, people sometimes throw in type aliases "just in case," leading to unneccesary complexity. Consequently, I prefer 
* to use simple type functions:

template<typename T>
	using Value_type = typename std::iterator_trait<T>::value_type;

template<typename T>
	using Difference_type = typename std::iterator_trait<T>::difference_type;

template<typename T>
	using Iterator_category= typename std::iterator_trait<T>::iterator_category;

* The example cleans up nicely:

template<typename Iter>
Iter search(Iter p, iter q, Value_type<Iter> val)
{
	Difference_type<Iter> m = q−p;
	// ...
}"

* He continues "I suspect that traits are currently overused. Consider how to write the previous example without any 
* mention of traits or other type functions:

template<typename Iter, typename Val>
Iter search(Iter p, iter q, Val val)
{
	auto x = ∗p; // if we don’t need to name *p’s type
	auto m = q−p; // if we don’t need to name q-p’s type
	
	using value_type = decltype(∗p); // if we want to name *p’s type
	using difference_type = decltype(q−p); // if we want to name q-p’s type
	// ...
}"

* Of course, decltype() is a type function, so all I did was to eliminate user-defined and standard library type functions. 
* Also, auto and decltype are new in C++11, so older code could not have been written this way."
* 
* Me: I think that's what MSVC for example strives to do. Check for example the definition of the distance function, where
* they use as little of metaprogramming as possible to do the calculations.
* 
* He finally concludes that "We need a trait (or equivalent, such as decltype()) to associate a type with another type, 
* such as a value_type with a T∗. For that, a trait (or an equivalent) is indispensable for non-intrusively adding type 
* names needed for generic programming or metaprogramming. When a trait is used simply to provide a name for something 
* that already has a perfectly good name, such as pointer for value_type∗ and reference for value_type&, the utility is 
* less clear and the potential for confusion greater. Don’t blindly define traits for everything "just in case."
* 
* Me: On that last, I argue that unfortunately sometimes this is out of my hand. For example, with custom iterators as
* I show in Chapter 35, WritingAnIteratorWrapper_0, I need to the such aliases to allow my iterator to be used together
* with std functions.
*/
