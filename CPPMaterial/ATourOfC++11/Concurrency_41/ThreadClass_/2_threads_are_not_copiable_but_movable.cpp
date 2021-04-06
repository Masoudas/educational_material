/** This is me:
* As we already discussed, threads are not copiable objects, which does make sense, because letting them be copied implies
* they'd be reexecuted! Therefore, thread objects are only movable.
* 
* The point is that once we receive a moved thread instance, it's always a good idea to check whether or not that thread
* is joinable (has join or detach method called on it or not)
*/

#include <iostream>
#include <thread>

using namespace std::chrono_literals;	// When using or aliasing namespaces, don't forget the namespace keyword :D

void my_thread_task() {
	std::cout << "Performing the thread task";
}

template <typename T>
std::thread thread_creator(T&& task) {
	auto thread = std::thread{ std::forward<T>(task) };
	thread.detach();
	return thread;
}

//int main() {
//	auto created_thread = thread_creator(my_thread_task);
//
//	if (!created_thread.joinable()) {
//		std::cout << "\nThread has already been joined\n";
//	}
//
//	std::this_thread::sleep_for(1s);	// The namespace being used allow me to write 1s!
//}
