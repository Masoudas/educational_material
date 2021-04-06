/**
* me: As already mentioned, a race condition happens when two sources are trying to write to the same shared data.
* 
* Let's consider the following example of how this condition might happen in practice. We will create a classic example 
* of a "check then act" race condition. We will create a thread, which performs the division of two numbers. We will 
* pass these numbers by reference. After a check, if a dividend is equal to 0, we will set a small timeout. At this 
* time in the main thread, we will set the dividend to 0. When the child thread wakes up, it will perform a division to 
* 0. That will lead to an application crash. We will also add some logs to see the execution flow.
* 
* Note: Recall that to pass a variable by reference to threads, we can use the reference_wrapper class, which can be
* invoked using the std::ref function.
* 
* To cause race in the following program, set CAUSE_RACE to one.
*/

#define CAUSE_RACE 1

#include <iostream>
#include <thread>

using namespace std::chrono_literals;

void divide(float& divisor, float& dividend) {
	std::this_thread::sleep_for(1s);
	if (std::abs(dividend - 0) > 1e-4) {	// Always check properly for floats. Don't just type == 0.
		std::cout << "\ndivision result: " << divisor / dividend << '\n';
	}
	else {
		std::cout << "\nError and program crash \n";
	}
}

int main() {
	float divisor = 10; float dividend = 5;

	std::thread t{ divide, std::ref(divisor), std::ref(dividend) };
	t.detach();

#if CAUSE_RACE == 1
	dividend = 0;
#endif // CAUSE_RACE

	std::this_thread::sleep_for(2s);
}