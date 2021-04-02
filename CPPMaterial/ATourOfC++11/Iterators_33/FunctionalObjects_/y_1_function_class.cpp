/**
* Me: As we know, lambdas don't have a uniform type, and in fact we can't assign to different lambdas to each other. The
* funcional class (among other things) is created to provide us with a uniform wrapper for lambdas. Hence, lambdas would
* be interchangeable using this class.
* 
* The standard says:
* template< class >
*	class function; // undefined 
* template< class R, class... Args >
*	class function<R(Args...)>;
* 
* Class template std::function is a general-purpose polymorphic function wrapper. Instances of std::function can store, 
* copy, and invoke any CopyConstructible Callable target -- functions, lambda expressions, bind expressions, or other 
* function objects, as well as pointers to member functions and pointers to data members.
* 
* The stored callable object is called the target of std::function. If a std::function contains no target, it is called 
* empty. Invoking the target of an empty std::function results in std::bad_function_call exception being thrown.
* std::function satisfies the requirements of CopyConstructible and CopyAssignable.
* 
* The most important member functions are:
*	-	operator():	invokes the target (public member function)
*	-	operator=:	Assigns new target.
*	-	operator bool:	checks if a valid target is contained (me: A cast operation).
*	-	target:	obtains a pointer to the stored target
* 
* Notes: 
* Care should be taken when a std::function whose result type is a reference is initialized from a lambda expression 
* without a trailing-return-type. Due to the way auto deduction works, such lambda expression will always return a 
* prvalue. Hence, the resulting reference will usually bind to a temporary whose lifetime ends when 
* std::function::operator() returns.
* 
* std::function<const int&()> F([]{ return 42; });
* int x = F(); // Undefined behavior: the result of F() is a dangling reference
* 
* Note from me: Note that the template type of the function has to be the function pointer for the lambda we're passing
* in. Hence for example, if we're passing a void(*)(), then the template has to be void(). If it's int(*)(), it has to
* be int(int).
* 
* Question: Why is it not void(*)()? Check Specialization, section 1, 1_1_where_is_pointer_to_function.
* 
* The following example is from the standard. Pay speciall attention to the one with bind and placeholder
*/

#include <functional>
#include <iostream>
 
struct Foo {
    Foo(int num) : num_(num) {}
    void print_add(int i) const { std::cout << num_+i << '\n'; }
    int num_;
};
 
void print_number(int i)
{
    std::cout << i << '\n';
}
 
struct PrintNum {
    void operator()(int i) const
    {
        std::cout << i << '\n';
    }
};


 
void calling_function_objects()
{
    
    // store a free function
    std::function<void(int)> f_display = print_number;
    f_display(-9);
 
    // store a lambda
    std::function<void()> f_display_42 = []() { print_number(42); };
    f_display_42();
 
    // store the result of a call to std::bind
    std::function<void()> f_display_31337 = std::bind(print_number, 31337);
    f_display_31337();
 
    // store a call to a member function
    std::function<void(const Foo&, int)> f_add_display = &Foo::print_add;
    const Foo foo(314159);
    f_add_display(foo, 1);
    f_add_display(314159, 1);
 
    // store a call to a data member accessor
    std::function<int(Foo const&)> f_num = &Foo::num_;
    std::cout << "num_: " << f_num(foo) << '\n';
 
    // store a call to a member function and object
    using std::placeholders::_1;
    std::function<void(int)> f_add_display2 = std::bind( &Foo::print_add, foo, _1 );
    f_add_display2(2);
 
    // store a call to a member function and object ptr
    std::function<void(int)> f_add_display3 = std::bind( &Foo::print_add, &foo, _1 );
    f_add_display3(3);
 
    // store a call to a function object
    std::function<void(int)> f_display_obj = PrintNum();
    f_display_obj(18);
}