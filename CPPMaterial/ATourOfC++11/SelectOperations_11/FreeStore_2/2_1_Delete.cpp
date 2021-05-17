/**
 * An object created by new is in the memory until it's deleted, using the delete keyword.
 * The delete keyboard ONLY accepts a pointer.
 * 
 * delete can be applied to nullptr with no problem (phew!!). However, when applied to memory
 * that's already been deleted, throws an exception (Me: Question is, how does it know that the memory
 * does not belong to C++? Because C++ objects put header information on the memory. Hence for example,
 * if I have a pointer and try to delete ptr++, and exception is thrown, because that's not my memory)
 * 
 * Me: A reminder that I once tried to delete memory from in the middle of the array, and it wasn't possible!
 * Me: Note finally that we can't delete stack objects too, so this would be a fourth problem in memory
 * management.
 */
#include <iostream>

void examples(){
    int* ptr = nullptr;
    delete ptr;

    int x{};

    //delete x; This statement is incorrect!

    int* p1 = new int{99};
    int* p2 = p1; // potential trouble
    delete p1; // now p2 doesn’t point to a valid object
    p1 = nullptr; // gives a false sense of safety
    char* p3 = new char{'x'}; // p3 may now point to the memory pointed to by p2
    //*p2 = 999; // this may cause trouble

    std::cout << *p2 << '\n'; // Does not print 99, because its location is not in use.

    // Me: can't delete stack objects.
    int y{};
    delete &y;  // Ooops!
}

/**
 * We can summarize problems associated with memory in three bullet points:
 * 1- Leaked objects: One forgets to delete the objects.
 * 2- Premature delete: One deletes a pointer, however that memory is still being used.
 * 3- Double deletion: This one stops the operation of the code and throws an exception.
 */
void sloppy() // very bad code
{
    int* p = new int[1000]; // acquire memory {No initialization}
	// ... use *p ...
	delete[] p; // release memory
	// ... wait a while ...
	delete[] p; // but sloppy() does not own *p
}

/**
 * To overcome this issue, 
 *      1- prefer scoped variables over heap variables as much as possible. Moreover,
 *      2- Use memory handler objects such as shared_ptr, unique_ptr, weak_ptr;
 * Also, using move semantics can take care of this problem as well. Because if we're initializing a new 
 * reference, we want to just move the object, and steal the resources of the first one.
 * 
 * The latter is the RAII principle, better known as resource allocation is initialization.
 * 
 * Here's another interesting way to look at this. We can express with we intend to with resources as 
 * follows:
 * 
 *      -   Local objects. The C++ runtime as the owner automatically manages the lifetime of these 
 *          resources. The same holds for global objects or members of a class. The guidelines calls them 
 *          scoped objects.
 *      -   References: I'm not the owner. I only borrowed the resource that cannot be empty.
 *      -   Raw pointers: I'm not the owner. I only borrowed the resource that can be can be empty. 
 *          I must not delete the resource. 
 *      -   std::unique_ptr: I'm the exclusive owner of the resource. I may explicitly release the 
 *          resource.
 *      -   std::shared_ptr: I share the resource with other shared ptr. I may explicitly release my 
 *          shared ownership.
 *      -   std::weak_ptr: I'm not the owner of the resource but I may become temporary the shared owner 
 *          of the resource by using the method std::weak_ptr::lock.
 */ 


