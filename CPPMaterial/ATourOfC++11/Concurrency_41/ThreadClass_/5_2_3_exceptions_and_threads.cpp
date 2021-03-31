/**
* This is me:
* 
* The standard says "Any return value from the function is ignored. If the function throws an exception, 
* std::terminate is called. In order to pass return values or exceptions back to the calling thread, 
* std::promise or std::async may be used."
* 
* Consequently, an exception that's thrown is equivalent to termination of code with thread with an error!
* Therefore, we should be cautious not to use thread with exception throwing sensitive functions!
*/

#include <thread>
#include <iostream>

void method() {
	throw "I'm just a douche of a method!";
}

void catching_exceptions_in_main_thread() {

	try {
		std::thread t{ method };
		t.join();
	}
	catch (const char* v) {
		std::cout << "Caught the exception. Who's going to terminate the thread now?";
	}
}

//int main() {
//	catching_exceptions_in_main_thread();
//}
