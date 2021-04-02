/**
* This is me, using an example of the standard:
* 
* The question that may naturally arise here is that "can we somehow pass a resource to class by reference?"
* 
* Recall that as we discussed, the antiode to decay_t is reference_wrapper, as discussed in chapter 35, 
* type functions. Hence, we need to wrap the resources in a reference wrapper. For this end, we use the 'ref'
* function.
* 
* I also bring your attention to the fact that std::invoke throws an error if the type passed to it does not
* match the function argument. Hence, when trying to pass n (which is not a reference) to the method (which
* accepts a reference) an error is thrown!
*/
#include <type_traits>
#include <thread>
#include <iostream>


void passing_to_thread_by_reference() {
	auto m = [](int& c) {c++; };

	int n = 0;

	//std::thread t{ m, n1 };	// Error! Not passing reference to a method that requires a reference in invoke.
	//t.join();
	//std::cout << "The value of n has not changed in the other thread: " << n;

	std::thread t1{ m, std::ref(n) };	// Passed by reference
	t1.join();
	std::cout << "The value of n has now changed in the other thread: " << n;

}

