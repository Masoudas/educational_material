/**
 * Sometimes we want the new operator not to throw any exception, so that we can handle it ourselves.
 * 
 * In this situation, we can use a version of new that does not throw an exception.
 * In this version, if the resource cannot be acquired, the pointer would be null.
 * 
 * There's an equivalent delete version for completenes, however we don't use it. Because delete by default
 * does not throw any exceptions. (Me: it does though, if memory is already deleted. However, I get his 
 * point that a nullptr does not throw.)
 * 
 */
#include <new>          // std::nothrow
#include <iostream>
void no_throw_new_example(){
    int* ptr = new (std::nothrow) int[5];

    if (!ptr){
        // Do something here.
    }else{
        std::cout << "No exception was thrown " << "Yay";
    }

    // delete(std::nothrow) ptr; No such thing.
    delete ptr;
}