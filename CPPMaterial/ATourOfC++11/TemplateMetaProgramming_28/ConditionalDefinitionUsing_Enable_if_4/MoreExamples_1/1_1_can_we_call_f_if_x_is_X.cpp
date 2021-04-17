/**
* One question that we want to answer is "Can we call f(x) if x is of type X?", where X is a type?
* 
* Hint: Note that when substitution succeeds, the function f(x) will have a return type. Hence, we can use the
* decltype function to compute the return type, otherwise, we can't.
* 
* Solution from me: The challenge as we might have guessed is to convert a type to a boolean. Here's where 
* SFINAE comes in handy. Imagine, if we COULD define a function overload in which:
*	-	If decltype(f(x)) has a type, a true is returned.
*	-	Otherise, false is returned.
* but we can't. However, we can do something else, which is as close as we get. If the decltype fails, instead
* we return a custom class, which in our case we call substitution_failure. Hence, let's define another class
* that has the overloads we talked about as follows follows. Notice the beautiful use of auto here. Also notice
* the use declval to avoid accepting an instance of X. Next, we discuss why this is wrong however:
* 
struct substitution_failure{};

// Structure that checks whether or not f has result.
template<typename T>	// We pass X here.
struct get_f_result{
private:
	template<typename X>
	static constexpr auto check(const X& x) -> decltype(f(x)){};	// Returns f return type, otherwise SFINAE throws it
														// out.
	static constexpr substitution_failure check(const X& x){ substitution_failure{} }; // After SFINAE. 
public:
	using type = decltype(check(std::declval<T>());
}

* Now we see what happens. Note that:
*	[1]	The use of declval allows us to create a reference to T, without having to actually construct it!
*		This function is in the utility class. See chapter 35 on TypeGenerators on its definition.
*	[2]	If X does not work with function f, then the first function would be SFINAEd through the beautiful
*		use of declaration. In that case, the second function will be used.
*	[3]	Note that we're using decltype to determine the return type of the function check. As stated earlier,
*		we use declval to just on a reference to check. In particular, declval returns an rvalue reference,
*		but because we're not forwarding it, it turns into lvalue ref, but then again, the function asks for
*		for a const X&.
*	[4] Why did we use another template for the function? Note that writing T& directly matches the template,
*		and not overload resolution would ever take place. But in general, this piece of code seems to be
*		wrong, as I explain next.
*	[5] I added the constexpr for this function to be used at compile time.
*	[6] This, however, is wrong, as we discuss next.
* 
* Now, notice that the structure get_f_result returns either the substitution_failure type, or the return
* type of the function. It's thus easy to write a type_function that returns a boolean based on this
* return type.
* 
* We shall discuss a novel way to do this next.
*/