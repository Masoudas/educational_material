/** This is from me and the internet:
* The remove_reference_t<T> in the definition of template implies that it does not allow type deduction. 
* Questions are, how is it not allowing that, and why is it not allowing that?
* In one word, if we had allowed it, then forwarding rvalue references without explicit declaration would have
* been impossible.
* 
*	-	How?
*	My speculation is that remove_reference is a struct, and we can't deduce template for it (I think.) Therefore,
*	forward does not allow deduction as such, and writing an expression like forward<int>(5) throws an error.
* 
*	There's also an assertion in the rvalue argument that states:
*	static_assert(!is_lvalue_reference_v<_Ty>, "bad forward call");
*	
*	This assertion comes to effect after we've stated the template. Suppose we write it as int&. Then, if we
*	pass 5, we'd get an lvalue reference for an unnamed rvalue object, which is why we've this assertion here.
*	
*	-	Why?
*	If we were to allow deduction by removing remove_reference_t, then as we discussed in chapter 25 for 
*   rvalue references, T would be deduced as lvalue for rvalue references (the passed rvalue becomes an lvalue
*   reference. Therefore, T&& deducec T as T& rather than T). This results in returning an lvalue reference to 
*   an rvalue object.
* 
* The following example perfectly illustrates this point. forward_with_deduction is a function that allows
* deduction rather than supress it. Now, we have a method called test with three overloaded references. The
* perfect_forwarder is responsible for forwarding its parameter to these methods using forward_with_deduction.
* But we see that the rvalue method is never called, as we discussed above.
*/
#include <utility>
#include <iostream>

template<typename T>
T&& forward_with_deduction(T&& obj)
{
	return static_cast<T&&>(obj);
}

void test(int&) { std::cout << "inside lvalue ref method\n"; }
void test(const int&) { std::cout << "inside const lvalue ref method\n"; }
void test(int&&) { std::cout << "inside rvalue ref method\n"; }

template<typename T>
void perfect_forwarder(T&& obj)
{
	test(forward_with_deduction(obj));
}

void how_forward_with_deduction_works()
{
    int x{};
    const int& y(x);
    int&& z = std::move(x);

    test(forward_with_deduction(7));    //  7 is an int&&, correctly calls test(int&&)
    test(forward_with_deduction(z));    //  z is treated as an int&, calls test(int&)

    //  All the below call test(int&) or test(const int&) because in perfect_forwarder 'obj' is treated as
    //  an int& or const int& (because it is named) so T in forward_with_deduction is deduced as int& 
    //  or const int&. The T&& in static_cast<T&&>(obj) then collapses to int& or const int& - which is not what 
    //  we want in the bottom two cases.
    std::cout << "\n\nFrom now on, only lvalue methods are called\n";
    perfect_forwarder(x);
    perfect_forwarder(y);
    perfect_forwarder(std::move(x));
    perfect_forwarder(std::move(y));
    perfect_forwarder(5);

}