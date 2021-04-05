/** This is me:
* Here's a question for you. Can two threads just read a vector, and not write to it? What about a file.
* 
* The vector experiment: There doesn't seem to be an issue. We can read the two vectors, but note that while printing
* them on the command line, strange things happen. That is, one thread prints some of its data, then has to wait for
* the other thread, then has to print a bit, then wait, etc. Hence, trying to access the same resource manifests 
* itself as such, that is one thread gets hold of the console, but before its task is finished, it has to let go for
* the other thread.
* 
* The same story would happen for a file too, that is, one thread would try to access the file, it reads a little 
* bit of it, but then has to make room for the other thread. Hence, in such a situation, perhaps, we breakdown the
* lines in a file. Consequently, we must NOT access a resource by two threads, even for reading them.
*/

#include <vector>
#include <algorithm>
#include <thread>
#include <iostream>


std::vector v{ 1, 2, 3, 4, 5, 6, 7, 8 };	// Without remembering here, I used std template deduction rules for
											// classes!

void print_vector() {
	std::for_each(v.cbegin(), v.cend(), [](const auto& v) {
		std::cout << "\nprinting inside thread " << std::this_thread::get_id() << " value is: " << v;
		});
}

//int main() {
//	std::thread t1{ print_vector };
//	std::thread t2{ print_vector };
//
//	t1.detach();
//	t2.detach();
//
//	std::this_thread::sleep_for(std::chrono::seconds(3));
//}
