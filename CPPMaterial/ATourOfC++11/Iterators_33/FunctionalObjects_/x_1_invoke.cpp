/**
* A method for calling a callable object together with arguments. From the onset, I bring your attention
* to the fact that this is a noexcept function, meaning that if the underlying function throws an exception,
* std::invoke does not return it! This is one reason why std::invoke is used inside threads.
* 
* See the comparison between std::bind and std::throw as well.
* 
* The standard says:

template< class F, class... Args>
constexpr std::invoke_result_t<F, Args...> invoke(F&& f, Args&&... args) noexcept

* Invoke the Callable object f with the parameters args. As by 
* INVOKE(std::forward<F>(f), std::forward<Args>(args)...), where INVOKE(f, t1, t2, ..., tN) is defined as 
* follows:
* 
*	-	If f is a pointer to member function of class T:
*		-	If std::is_base_of<T, std::decay_t<decltype(t1)>>::value is true, then INVOKE(f, t1, t2, ..., tN) 
*			is equivalent to (t1.*f)(t2, ..., tN)
*		-	If std::decay_t<decltype(t1)> is a specialization of std::reference_wrapper, then 
*			INVOKE(f, t1, t2, ..., tN) is equivalent to (t1.get().*f)(t2, ..., tN)
*		-	If t1 does not satisfy the previous items, then INVOKE(f, t1, t2, ..., tN) is equivalent to 
*			((*t1).*f)(t2, ..., tN).
* 
*	-	Otherwise, if N == 1 and f is a pointer to data member of class T:
*		-	If std::is_base_of<T, std::decay_t<decltype(t1)>>::value is true, then INVOKE(f, t1) is equivalent 
*			to t1.*f
*		-	If std::decay_t<decltype(t1)> is a specialization of std::reference_wrapper, then INVOKE(f, t1) is 
*			equivalent to t1.get().*f
*		-	If t1 does not satisfy the previous items, then INVOKE(f, t1) is equivalent to (*t1).*f
* 
*	-	Otherwise, INVOKE(f, t1, t2, ..., tN) is equivalent to f(t1, t2, ..., tN) (that is, f is a 
*		FunctionObject)
* 
* Explaination for simpletons: Essentially, if we pass a pointer to member function, then we must at the same
* pass an instance of the class itself to be used with the pointer to member. It should then be passed as 
* the first argument. After doing so, whether that passed instance is a pointer, reference_wrapper or an 
* actual instance, and then invokes the method accordingly. The case for N=1 is equivalent. If this is
* not the case, then it simply calls the method with the given arguments. Care should be taken that all
* parameters are passed by reference in case of lvalues.
* 
* Below, we have a nice demonstration of how this method works.
*/

#include <functional>
#include <iostream>
 
struct Foo {
    Foo(int num) : num_(num) {}
    void print_add(int i) const { std::cout << num_+i << '\n'; }
    int num_;
};
 
void print_num(int i)
{
    std::cout << i << '\n';
}
 
struct PrintNum {
    void operator()(int i) const
    {
        std::cout << i << '\n';
    }
};
 
void invoking_with_invoke()
{
    // invoke a free function
    std::invoke(print_num, -9);
 
    // invoke a lambda
    std::invoke([]() { print_num(42); });
 
    // invoke a member function
    const Foo foo(314159);
    std::invoke(&Foo::print_add, foo, 1);
 
    // invoke (access) a data member
    std::cout << "num_: " << std::invoke(&Foo::num_, foo) << '\n';
 
    // invoke a function object
    std::invoke(PrintNum(), 18);
}
