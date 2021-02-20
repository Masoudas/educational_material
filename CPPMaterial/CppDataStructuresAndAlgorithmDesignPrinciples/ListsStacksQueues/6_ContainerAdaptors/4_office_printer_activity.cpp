/**
* So imagine for fun, that in the office the manager has a higher priority than engineer, and that engineers have
* a higher priority than secretaries, and those have greater priority than librarians.
* 
* So if we wanted to simulate the shared office printer, we need to consider such priorities as well, which is why
* we prefer to use priority queue for this situation. More specifically, we want to use a stable priority queue 
* so that whomever came first is served first, which is impossible I guess, because a pq is not a stable data
* structure.
* 
* Also interesting to note, if we decide to have a situation where we add jobs and print at the same time, we need
* to have a multi-threaded scenario. Therefore, the underlying data structure has to be synchronized.
*/
#include <string_view>
#include <queue>
#include <iostream>
#include <utility>

class Job {
public:
	enum class Emp { MANAGER, ENGINEER, SECRETARY, LIBRARIAN };
private:
	Emp emp;
	int id;
	int pages;
	std::string_view user_name;

public:
	Job(Emp emp, const std::string_view& user_name, int id, int pages) : emp{ emp }, user_name{ user_name }, 
		id{ id }, pages{ pages } {}

	int get_id() { return id; }
	int get_pages() { return pages; }
	const std::string_view& uname() { return user_name; }

	friend bool operator<(const Job& lhs, const Job& rhs) {
		return !(lhs > rhs);
	}

	friend bool operator>(const Job& lhs, const Job& rhs) {
		switch (lhs.emp)
		{
		case Emp::MANAGER:
			if (rhs.emp == Emp::MANAGER) {
				return false;
			}
			return true;
		case Emp::ENGINEER:
			if (rhs.emp == Emp::MANAGER || rhs.emp == Emp::ENGINEER) {
				return false;
			}
			return true;
		case Emp::SECRETARY:
			if (rhs.emp == Emp::MANAGER || rhs.emp == Emp::ENGINEER || rhs.emp == Emp::SECRETARY) {
				return false;
			}
			return true;
		case Emp::LIBRARIAN:
			if (rhs.emp == Emp::MANAGER || rhs.emp == Emp::ENGINEER || rhs.emp == Emp::SECRETARY || 
				rhs.emp == Emp::LIBRARIAN) {
				return false;
			}
			return true;
		}
	}
};


class Shared_Printer {
	std::priority_queue<Job> pq{};

public:
	Shared_Printer(){}

	template<typename...Args>
	void define_job(Args&&...arg) {
		pq.emplace(std::forward<Args>(arg)...);	// Notice how we unpack the parameters! Three dots go after forward!
	}

	void print() {
		Job j = pq.top();	// Copy constructor.
		pq.pop();

		std::cout << "Current user is \'" << j.uname() << "\' and is printing " << j.get_pages() << " pages";
	}
};

//int main() {
//	Shared_Printer printer{};
//
//	printer.define_job(Job::Emp::MANAGER, "Masoud", 1, 4);
//	printer.define_job(Job::Emp::SECRETARY, "Gwendoline", 2, 1);
//
//	printer.print();
//}


