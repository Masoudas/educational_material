/**
* Let's investigate the detach case. Here, we first halt the exection of the new thread to see that after
* the created thread is detached, the main thread continues its thing and finishes. Then, while main is
* finished, we execute the created thread! This is essentially a zombie like thing, or apparently as they
* call it "A daemon thread."
*/

#include <thread>
#include <iostream>
#include <chrono>

void print() {
	std::this_thread::sleep_for(std::chrono::seconds(3));
	std::cout << "Message from the created thread\n";
}

//int main() {
//	std::thread t1{ print };
//
//	t1.detach();	// Continue execution of this thread, but don't destroy the other one.
//	std::cout << "Printing a message from the main thread\n";
//	std::this_thread::sleep_for(std::chrono::seconds(4));
//
//}