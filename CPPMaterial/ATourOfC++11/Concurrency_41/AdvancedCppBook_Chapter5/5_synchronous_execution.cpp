/**
* The term synchronous execution means that each subtask will be performed sequentially, one by one. In 
* other words, this means that if we have a few tasks to execute, each of them can only start its work 
* after the previous one has finished its work. This term does not specify a way to perform tasks, or 
* whether they will be performed in a single or several threads. It only tells us about the execution 
* order. Let's go back to the philosophers' dinner example. In a single-threaded world, the philosophers 
* will eat one after the other.
* 
* The first philosopher takes two chopsticks and eats their sushi. Then, the second philosopher takes 
* two chopsticks and eats their sushi. They take turns until all of them have finished their sushi. Take 
* a look at the following diagram, which represents the synchronous execution of four tasks in a single
* thread. Here, each of the tasks waits for the previous task to finish. Tasks can also be performed 
* synchronously in multiple threads. This is illustrated in the example below.
* 
* Note that synchronous execution means that the finishing time of each task is synchronized. The order 
* of the execution of tasks is the main point here.
* 
* Note from me: This example is important in illustration of the difference between parallel execution
* and synchronous execution. The latter means tasks would be accomplished one after another, whereas the
* former means tasks would be accomplished simultaneously.
* 
* 
*/

#include <iostream>
#include <thread>

void task_one() {
	std::cout << "Executing task one\n";
}

void task_two() {
	std::cout << "Executing task two\n";
}

void synchronization_in_one_thread() {
	task_one();
	task_two();
}

void synchronization_using_multiple_threads() {
	std::thread t1{ task_one };
	t1.join();	// This must be joined to be sequential, and not detached.

	std::thread t2{ task_two };
	t2.join();
}