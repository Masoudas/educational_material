/**
* Just like we can pass there ways of comparison to a queue, there are three ways to pass a main method of
* execution to a thread constructor:
*
*	-	Pass a function pointer together with arguments.
*	-	Pass a lambda together with arguments.
*	-	Pass a class that has an operator() defined (what they call a callable object.)
*	-	Pass a function object (class, from the functional header.)
* 
* Note that the latter is like a lambda, except that it has a function wrapper, meaning we can treat it as class.
*
* The good thing is that unlike a queue, we needn't specify the templates for the method, as thread is not a
* templated class. The constructor is, which allow us to use function template deduction rules:
*
* template< class Function, class... Args >
* explicit thread( Function&& f, Args&&... args );
*/

#include <iostream>
#include <thread>
#include <functional>

////////////// Passing a callable object /////////////////////
void creating_thread_with_operator() {
	struct exec_method {
		void operator()() {
			std::cout << "Executed from a new thread\n";
		}
	};

	std::thread t{ exec_method{} };
}

/////////////////// Passing a lambda ////////////////////////
void creating_thread_with_lambda() {
	auto exec_lambda = []() {std::cout << "Executed from a new thread\n"; };

	std::thread t{ exec_lambda };
}

////////////// Passing function pointer /////////////////////
void exec_function() {
	std::cout << "Executed from a new thread\n";
}

void creating_thread_with_function_ptr() {
	std::thread t{ exec_function };
}

////////////// Create a function object /////////////////////
void create_a_function_object() {
	std::function<void()> task = []() {		// Note that we should write void(), and not void, because template
													// has signature of lambda.
		std::cout << "Performing some task";
		return 6;
	};

	std::thread t{ task };
}

