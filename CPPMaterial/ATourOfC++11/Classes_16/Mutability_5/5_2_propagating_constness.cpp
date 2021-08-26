/**
* As of 2020 and because it has not been standardized, there's a facility in the experimental header called propagate_const,
* which would allow the propagation of constness to the memebrs of a class as well. This is thus far implemented only in gcc
* and Clang. It's not implemented in MSVC. Therefore, the code is commented for now.
* 
*/

/**
#include <experimental/propagate_const>
class Foo {
public:
    Foo(int* ptr) : ptr_{ ptr } {}
    auto set_ptr(int* p) const {
        ptr_ = p;  // Will not compile, as expected
    }
    auto set_val(int v) const {
        val_ = v;  // Will not compile, as expected
    }
    auto set_ptr_val(int v) const {
        *ptr_ = v; // Will not compile, const is propagated
    }

private:
    std::experimental::propagate_const<int*> ptr_ = nullptr;
    int val_{};
};
*/