/**
* std::thread has a member function called get_id() that returns the unique ID of the std::thread instance. If the 
* std::thread instance wasn't initialized or was joined or detached, get_id() returns a default std::thread::id object. 
* This means that no thread of execution is associated with the current std::thread instance.
* 
* Me: Note however that we don't need to explicitly check that the thread id. The method 'joinable' does it for us.
* Note once again that we're not talking about the thread being alive or dead, just the fact that it's joinable or not.
*/

#include <thread>
#include <iostream>

using namespace std;
void task(){
	std::this_thread::sleep_for(1s);	// Need to import std to be able to write this,
}

void checking_whether_thread_is_joinable() {
	thread t{ task };
	
	if (t.joinable()) {
		std::cout << "The thread hasn't been joined or detached, but has been initialized.";
		t.detach();	// Hence we detach the thread to make sure that no exceptions occur upon termination of program.
	}

	if (!t.joinable()) {
		std::cout << "\n\nBut now that it has been detached, the joinable method returns false\n\n";
	}
}

//int main() {
//	checking_whether_thread_is_joinable();
//}