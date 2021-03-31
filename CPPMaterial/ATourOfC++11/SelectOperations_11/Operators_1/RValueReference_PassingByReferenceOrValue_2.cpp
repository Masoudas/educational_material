/**
 * The other use is that there may be cases where we have pass by reference, but we want pass
 * by value. So the function is not working. For example, with void f(int& a), we can't simply
 * pass f(5). Hence, we want to pass both by l value and by rvalue. To do so, we use the rvalue
 * reference. The std::forward<T> function of the standard library then takes care of whether we have an rvalue
 * or lvalue. This is used mostly for cases when we don't want to overload a function once with
 * value and once with reference.
 */
#include <memory>

template <typename T, typename A1>
std::unique_ptr<T> factory(A1& a1)   // If passed by value like factory(A1), this retuns an error.
{
    return std::unique_ptr<T>(new T(a1));
}

// This version does not have the previous problem.
template <typename T, typename A1>
std::unique_ptr<T> factory(A1&& a1)
{
    return std::unique_ptr<T>(new T(std::forward<A1>(a1)));
}