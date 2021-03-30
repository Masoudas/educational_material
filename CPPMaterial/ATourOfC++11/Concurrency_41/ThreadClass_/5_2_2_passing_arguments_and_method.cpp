/**
* This is all me:
* 
* In what follows, we shall demonstrate that depending on how the execution method and the params are passed
* to the thread class, they are copied.
* 
* Particularly, note that the thread class copies the execution method, because it doesn't know whether it's
* a lambda, a class with operator or whether it's a function pointer. It also copies the arguments. All of 
* this happens to ensure that the a thread does not accidentally cause racing or other issues with the data.
* The copy operation is a guard against accessing a resource by two threads.
* 
* In particular, this is accomplished using the decay_copy function in the constructor of the thread.
*/

#include <iostream>
#include <thread>

struct arg {
	arg() = default;
	arg(const arg&){ std::cout << "Inside copy ctor of arg\n"; }
};

struct thread_method {
	thread_method() = default;

	thread_method(const thread_method&) {
		std::cout << "Inside copy ctor of method\n";
	}

	void operator()(const arg&) {
		std::cout << "Executed from a new thread\n";
	}
};

//int main() {
//	thread_method method{};
//	arg ar{};
//
//	std::thread t{ method,  ar };
//
//	t.join();
//}