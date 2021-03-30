/**
* Just to stress that it's the life of the thread that has to be extended, and not the scope, consider the
* following example. The point is that we detach in the function that creates the thread, but we don't put
* it to sleep right there. We rather put the thread in the main function to sleep. Now, even in doing so, 
* the message is printed, because IT'S THE THREAD that musn't die out. In fact, note that we call all of 
* this in a thread created by the thread created by main. So, as long as the threads are sent to OS and the 
* main thread continues execution, everything will take place.
* 
* I also bring to attention the fact that the first created thread is never put to sleep. This thread is 
* just there, and its sole responsibility is to start another thread. Once that happens, it goes out of
* existence. It does not wait for a response from that thread or anything, or that because it creates it 
* now stays. What I'm trying to say here is that a thread is not a function, and once there's no more
* tasks associated with it, it goes out of existence. The life time of a thread ONLY depends on the tasks
* it has to perform.
*/
#include <iostream>
#include <thread>
#include <chrono>

void message() {
	std::this_thread::sleep_for(std::chrono::seconds(2));
	std::cout << "From created thread " << std::hex << std::this_thread::get_id() << "\n";
}

void create_thread_in_created_thread() {
	std::thread t{ message };
	t.detach();
}

void create_thread_in_main_thread() {
	std::thread t{ create_thread_in_created_thread };
	t.detach();
}

//int main() {
//	create_thread_in_main_thread();
//	std::this_thread::sleep_for(std::chrono::seconds(4));
//}