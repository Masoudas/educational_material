/**
* In the following code lies a subtle error, and we see that xyz throws an error saying no constructor was
* found. Why is it the case? 
* 
* Well, the very obvious error is that we're trying to assign an lvalue to an rvalue. But more importantly,
* note that forwarding here is erroneous. This is because a class template is fully resolved, and not deduced,
* hence, forwarding here might indeed use lvalue rather than rvalue, which is not the intention in this case!
*/
#include <memory>

template <typename T>
class my_wrapper {
    T val;

public:
    my_wrapper(T&& val_)
        : val{ std::forward<T>(val_) } {}
};


struct my_struct {
    int x;
};

// Wrong version.
//auto xyz() {
//    my_struct ms{ 3 };
//    return my_wrapper<my_struct>(ms);
//}

// Half correct version!
auto xyz() {
     //my_struct ms{ 3 };
     return my_wrapper<my_struct>({ 3 });
}