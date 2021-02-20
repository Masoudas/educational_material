/**
* Another very cool example of type deduction is the following. We pass a lambda together with parameters
* then decltype(auto) is used to determine the return type of the lambda!
* 
* Why did we use decltype(auto) and not auto? That's because we want to ensure that if the function returns
* by reference, we get a reference too! Otherwise, the type would have been the type of the return minus 
* possible reference!
*/
#include <utility>
template<class F, class... Args>
decltype(auto) PerfectForward(F fun, Args&&... args)
{
    return fun(std::forward<Args>(args)...);
}