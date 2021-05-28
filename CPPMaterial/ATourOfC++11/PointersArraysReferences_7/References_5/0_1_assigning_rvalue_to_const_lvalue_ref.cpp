/**
* We're all aware that an rvalue object can be assigned to a const lvalue ref. So for example, we could say:
* const string& s = string{};
* 
* In the same manner, if we get an rvalue reference from an object, we can assign it to such an lvalue.
* string s1 = {};
* const string& s = std::move(s1);
* 
* Why is this possible? This is possible because const lvalue ref is more restrictive than a normal lvalue
* reference, and it does not allow us to change the temporary object.
* 
* When is this useful? Particularly consider many std::algorithms such as reduce, accumulate and like, where
* we have an initial value which is constantly passed to a function (to be summed with the elements of our
* container.) Now, there, a possible implementation is as follows:

template<class InputIt, class T, class BinaryOperation>
constexpr // since C++20
T accumulate(InputIt first, InputIt last, T init,
             BinaryOperation op)
{
    for (; first != last; ++first) {
        init = op(std::move(init), *first); // std::move since C++20
    }
    return init;
}

* Now, we see that an rvalue is passed to the function. Now, if we can define the signature of the op as either
* of the following:
* 
*   -   Either T op(const T&, const T1&)
*   -   Or T op(T&&, const T1&)
*   -   not op(T&, const T1&)
* 
* What is the difference between the two? Say T has an operator+. Then the first signature generates a new
* object for each addition (most likely,) which is then moved outside, and then possibly move assigned to init
* (because the compiler probably understands that the return value is temporary.) However, With the rvalue
* reference, we can do a clever move such as

T op(T&& t, const T1&){
    return std::move(t) + T1;
}

* We see that here, move possibly invokes the 'operator+()&&' of the object, allowing us to add to this temp
* object, instead of creating a new one, and then return. So that way, we can save one copy here too. This is
* highly technical, but worth paying attention to!
*/