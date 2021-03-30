/**
* Just like we can pass there ways of comparison to a queue, there are three ways to pass a main method of
* execution to a thread constructor:
*
*	-	Pass a function pointer together with arguments.
*	-	Pass a lambda together with arguments
*	-	Pass a class that has an operator() defined.
*
* The good thing is that unlike a queue, we needn't specify the templates for the method, as thread is not a
* templated class. The constructor is, which allow us to use function template deduction rules:
*
* template< class Function, class... Args >
* explicit thread( Function&& f, Args&&... args );
*/

#include <iostream>
#include <thread>

void creating_thread_with_operator() {
	struct exec_method {
		void operator()() {
			std::cout << "Executed from a new thread\n";
		}
	};

	std::thread t{ exec_method{} };
}

void creating_thread_with_lambda() {
	auto exec_lambda = []() {std::cout << "Executed from a new thread\n"; };

	std::thread t{ exec_lambda };
}

void exec_function() {
	std::cout << "Executed from a new thread\n";
}

void creating_thread_with_function_ptr() {
	std::thread t{ exec_function };
}

