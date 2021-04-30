/**
* Imagine a data structure like Employee below. We provide a lock for each Employee, so that we can provide
* whatever operation we're performing on the fields of it. So, we use the lock of each particular emplyee to
* do so.
* 
* Here's the rub however. Two employees are interacting with each other here. That is, when one is assigned
* lunch partner to another, this action happens vice versa. As such, we need to lock the lunch_partner vector
* of each one of them when we assign to them, so that other threads don't mess with it. In other words,
* we need a scoped_lock to lock each Employee.
* 
* In the assign_lunch_partner function notice that an io_mutex is assigned to all calls of the function (
* because the mutex has not been called thread_local.) The function of this lock is to protect the logging
* function. Notice that it's locked using a simple lock_guard function.
* 
* 
*/

#include <mutex>
#include <thread>
#include <vector>
#include <iostream>

struct Employee {
	std::string id;
	std::vector<std::string> lunch_partners;
	std::mutex m;

	Employee(const std::string& id_) : id{id_}{}

	std::string output() const {
		std::string ret = "Employee " + id + " has lunch partners: ";
		for (const auto& partner : lunch_partners)
			ret += partner + " ";
		return ret;
	}
};

void send_email(Employee& e1) {
	// Simulating a very long task.
	std::this_thread::sleep_for(std::chrono::seconds{ 1 });
}

void assign_lunch_partner(Employee& e1, Employee& e2)
{
	// Logging portion
	static std::mutex io_mutex;
	{
		std::lock_guard<std::mutex> lk(io_mutex);
		std::cout << e1.id << " and " << e2.id << " are waiting for locks" << std::endl;
	}

	// Lunch partner assignment.
	{
		std::scoped_lock<std::mutex, std::mutex> lk{ e1.m, e2.m };	// Locking both, ensuring this portion	
						// is thread safe for each of them. i.e, we're about to do an operation on either,
						// and either may be accessed by other threads as well.

		// Logging and declaring the lock here.
		{
            std::lock_guard<std::mutex> lk(io_mutex);
            std::cout << e1.id << " and " << e2.id << " got locks" << std::endl;
        }
											
		e1.lunch_partners.push_back(e2.id);
		e2.lunch_partners.push_back(e1.id);

		// The locks are released here, and both e1 and e2 are free to be accessed by other threads.
	}

	send_email(e1);
	send_email(e2);
}

void defining_employees_and_assigning_lunch_partners() {
	Employee bob{ "Bob" }; Employee alice{ "Alice" }; Employee dave{ "Dave" }; Employee eli{ "Elizabeth" };

	std::vector<std::thread> ts{};

	ts.emplace_back(assign_lunch_partner, std::ref(bob), std::ref(alice));
	ts.emplace_back(assign_lunch_partner, std::ref(alice), std::ref(dave));
	ts.emplace_back(assign_lunch_partner, std::ref(dave), std::ref(bob));
	ts.emplace_back(assign_lunch_partner, std::ref(alice), std::ref(eli));

	for (auto& trd : ts) trd.join();

	std::cout << bob.output() << '\n' << alice.output() << '\n' << dave.output() 
		<< '\n' << eli.output() << '\n';

}

//int main() {
//	defining_employees_and_assigning_lunch_partners();
//}