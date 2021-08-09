/**
* (The follwing is not Bjarne)
*
 * Question is, when is the copy constructor called? And when is the assignment operator called?
 *
 * Answer: When we create a new object, the copy constructor is called (or move, depending).
 * The normal class x = y is an example.
 * Moreover, when we pass a class into a function, the constructor is called, because after all
 * we're creating a new copy. When we return an object from a function, the (copy)
 * constructor is called. Why? Because otherwise the value would be an auto variable
 * destroyed by the memory. (However, if we accept reference and return a reference, the content is
 * not copied, because we're returning and accepting the object as it is in the memory. In this case,
 * we should be careful as to make something on the heap).
 *
 * And assignment operator is a bitwise operation. For this to occur, the object being
 * assigned to must have already been initialized. Hence, x = y is possible only if x
 * has already been initialized using a constructor.
 *
 * With =, both objects share the same memory. With copy constructor, they have different
 * memory locations (we're talking about a shallow copy).
 *
 */
#include <iostream>
class Example
{
private:

public:
    Example() = default;  // Default constructor is not supplied by default!

    Example(const Example& t) {
        std::cout << "Inside Copy Constructor" << std::endl;
    }

    /**
     * Interpretation? We might imagine something like this t2 = t1; t2.operator=(t1).
     * In other words, we could have simply said void operator=(const Example& e). But the advantage
     * of overriding it this way is that it allows us to write t1 = t2 = t3; Simple chaining!
     */
    Example& operator=(const Example& e) {
        return *this;
    }
};

void no_reference_call(Example e) {

}

void reference_call(const Example& e) {

}

Example no_reference_returner(Example e) {
    return e;
}

void copy_or_assignment() {
    Example e1{};
    Example e2 = e1;    // Calling the copy constructor.
    no_reference_call(e1); // Calling the copy constructor, because a new copy is being created.
    reference_call(e1); // The copy constructor is not called here, because we're getting the reference to the object.
            // How about the assignment operator? I think so, because the alias refers to the same memory location.
    Example e3 = no_reference_returner(e1); // The copy constructor is called three times. Once when passing the function, once when
                        // returning inside the function, and once when assigning to e3!

}
