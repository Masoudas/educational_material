/**
* Another very cool example of type deduction is the following. We pass a lambda together with parameters
* then decltype(auto) is used to determine the return type of the lambda!
* 
* Why did we use decltype(auto) and not auto? That's because we want to ensure that if the function returns
* by reference, we get a reference too! Otherwise, the type would have been the type of the return minus 
* possible reference!
* 
* decltype(auto) is a way of detecting both the type (auto) together with reference and constness of the return value in certain
* scenarios, one of which involves returning templated types, for which we may not know the exact return type. We shall see
* further examples next.
*/
#include <utility>
template<class F, class... Args>
decltype(auto) PerfectForward(F fun, Args&&... args)
{
    return fun(std::forward<Args>(args)...);
}