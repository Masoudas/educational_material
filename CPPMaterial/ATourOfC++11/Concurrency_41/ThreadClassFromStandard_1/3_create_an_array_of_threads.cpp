/** Still me, based on the advanced c++ book by Khanji et al.
* 
* We know that to be able to create an array of a class, it has to be default con(de)structible. Otherwise, for example, 
* we can't create an array, or vector out of it. Moreover, classes need to be copy constructible for assignments to
* take place, hence essentially the type has to be regular.
* 
* Now, a thread is not regular, because even though it is default constructible (an empty or invalid thread class) it
* has no copy constructor. To solve this problem, we can think of two solutions:
* 
*	-	Create an array of pointer to threads
*	-	Create a normal array, yet move the threads rather than copy them.
* 
* The latter option does make sense, and it would be what we normally do when it comes to threads.
* 
* Two interesting phenomenon here:
*	-	Again notice that the output message of the threads is out of synch, because they're trying to access the 
*		console all together.
*	-	More interestingly, imagine in the signature of lambdas, we had tried to pass i with reference, saying 
*		[&i](){}. In that case, while the thread was being executed, the variable would have been destroyed by the
*		loop, causing the thread number to be jibberish! This was very interesting, and I should always pay attention
*		to how I pass variables to threads.
* 
*/ 
#include <vector>
#include <memory>
#include <thread>
#include <iostream>

using std::thread;

std::vector<std::unique_ptr<thread>> creater_thread_arr_ptr() {
	using thrd_ptr = std::unique_ptr<thread>;

	std::vector<thrd_ptr> threads{};
	for (int i = 0; i < 10; i++) {
		// Creating a ptr to thread, allowing it to be destroyed afterwards.
		thrd_ptr ptr{ new thread{ [i]() {std::cout << "\nPerforming task of pointer thread " << i; } } };

		threads.push_back(std::move(ptr));
	}

	return threads;
}

std::vector<thread> create_thread_arr_with_move() {
	std::vector<thread> threads{};

	for (int i = 0; i < 10; i++) {
		auto thrd = thread{ [i]() {std::cout << "\nPerforming task of moved thread " << i; } };
		threads.push_back(std::move(thrd));
		// Note that push_back(thrd) would have used copy constructor!
	}

	return threads;
}

//int main() {
//	using namespace std::chrono_literals;
//
//	auto ptr_thrds = creater_thread_arr_ptr();
//	for (auto& thrd_ptr : ptr_thrds) {
//		thrd_ptr->detach();
//	}
//
//	auto normal_thrds = create_thread_arr_with_move();
//	for (auto& thrd : normal_thrds) {	// Accessing by reference, hence no copy takes place here! There would have
//										// been a copy if we hadn't used &.
//		thrd.detach();
//	}
//
//	std::this_thread::sleep_for(3s);
//}
