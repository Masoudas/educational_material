/**
* Here's a simple example of the join method. In this schema, it's very clear that the execution of the
* main thread is halted in the function 'create_and_join' until the execution of the created thread is
* complete.
*/

#include <thread>
#include <iostream>
#include <chrono>

void message_in_join() {
	std::cout << "Message from the created thread\n";
}

void create_and_join() {
	std::thread t{ message_in_join };
	t.join();
	std::cout << "The created thread is joined\n";
}

//int main() {
//	std::cout << "Creating the new thread \n";
//	create_and_join();
//	std::cout << "Main thread now terminates \n";
//}