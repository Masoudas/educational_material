/**
* This is where a few tasks can be executed simultaneously without blocking any thread execution. Usually, 
* the main thread initiates an asynchronous operation and continues execution. After execution is finished, 
* the results are sent to the main thread. Often, performing an asynchronous operation is not related to 
* creating a separate thread for it. The task can be performed by someone else, such as another computing 
* device, a remote web server, or an external device. Let's go back to the philosophers' dinner example.
* 
* In the case of asynchronous execution, all of the philosophers will have their own chopsticks and will 
* eat independently from each other. When the sushi is ready and the waiter serves it, they all start to 
* eat and can finish in their own time.
*
* Note: In asynchronous execution, as all the tasks work independently of each other, it's not important 
* to know the finish time of each task.
* 
* A real-world example of asynchronous execution can be an internet browser wherein you can open multiple 
* tabs. When a new tab is opened, the application starts a new thread and detaches them. Although the 
* threads work independently, they can share some resources, such as a file handler, to write logs or do 
* something else.
* 
* Note finally that from the moment of execution, the threads become daemon threads.
*/
#include <iostream>
#include <thread>
#include <chrono>

void asynch_task() {
	std::this_thread::sleep_for(std::chrono::seconds(1));
	std::cout << "Hello from thread " << std::this_thread::get_id() << '\n';
}
//int main() {
//	std::thread t1{ asynch_task };
//	t1.detach();
//
//	std::thread t2{ asynch_task };
//	t2.detach();
//
//	std::thread t3{ asynch_task };
//	t3.detach();
//	
//	std::thread t4{ asynch_task };
//	t4.detach();
//
//	std::this_thread::sleep_for(std::chrono::seconds(6));
//}