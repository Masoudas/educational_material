/**
 * If for example we supply a function with initializer_list, it allows us to
 * directly put a list initializer (i.e, {1,2,3}) into the function. 
 * 
 * This function is called when we initialize an array, like int a[] = {1,2,3}
 * 
 * Its implementation is given below. As we can see, it doesn't have an index[] 
 * operator. Hence, if we want to iterate, we should get the first pointer, and add
 * to add, until we get to the last pointer.
 * 
 * Check out the abstraction below
 */

#include <Initializer_list>

void f(_initializer_lists<int> init){
    // Note that the end returns the pointer to space after last element!
    for (int* element = init.begin(); element != init.end(); element++) 
    {
        int val = *element;
    }

    for(int i=0; i<lst.size(); ++i)cout << lst[i] << '\n';//error. No [] operator

    // Note also that it can also be used in a range-for loop. 
    for (auto x : init)
    {
        /* code */
    }
    
    
}

template<typename T>class initializer_list {//§iso.18.9
    public:
        using value_type = T;
        using reference = const T&; //note const: initializer_list elements are immutable
        using const_reference = const T&;
        using size_type = size_t;
        using iterator = const T∗;
        using const_iterator = const T∗;
        initializer_list() noexcept;
        size_t size() const noexcept; //number of elements
        const T∗begin() const noexcept;   //first element
        const T∗end() const noexcept; //one-past-last element
};
template<typename T> const T∗ begin(initializer_list<T> lst) noexcept { return lst.begin(); }
template<typename T> const T∗ end(initializer_list<T> lst) noexcept { return lst.end(); }