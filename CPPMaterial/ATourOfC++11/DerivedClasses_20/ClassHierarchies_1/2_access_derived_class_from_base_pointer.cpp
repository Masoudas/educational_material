/**
* A question that arises here is that how can we determine which derived class is being pointed to by a base class 
* pointer?
* 
* There are four fundamental solutions:
* [1] Ensure that only objects of a single type are pointed to
* [2] Place a type field in the base class for the functions to inspect
* [3] Use dynamic_cast
* [4] Use virtual functions
* 
* Regarding the first solution, even though there are situtation that we use it (like in containers), we generally 
* must not try and out smart the type check system.
* 
* Note in fact that solution [3] is a language implemented version of solution [2]. Solution [4] is a typesafe 
* variation of solution [2]. Note that [2] indicates a field, because a method that is not virtual would return 
* base class name!
* 
* Combinations of solutions [1] and [4] are particularly interesting and powerful; in almost all situations, they 
* yield cleaner code than do solutions [2] and [3].
* 
* Solution [2] usually causes problems. For example, in the following code, we see that we constantly need to 
* check what's happening with the type enumeration, and if we add new types of emplyee in the future, all 
* conditionals using this check must be found throughout the code.
* 
* In general, using [2] is not a very good idea, and we should mostly consider solutions [1] and [4].
* 
* The big guy also says:
* 'It also seems that any common data accessible from every derived class, such as a type field, tempts people 
* to add more such data. The common base thus becomes the repository of all kinds of "useful information."  
* This, in turn, gets the implementation of the base and derived classes intertwined in ways that are most 
* undesirable'.
* In a large class hierarchy, accessible (not private) data in a common base class becomes the "global variables"
* of the hierarchy. For clean design and simpler maintenance, we want to keep separate issues separate and avoid 
* mutual dependencies.
*/

#include <list>
#include <string>
#include <iostream>

using namespace std;

struct Employee {
	enum Empl_type { man, empl };
	Empl_type type;
	Employee() : type{ empl } { }
	string first_name, family_name;
};

struct Manager : public Employee {
	Manager() { type = man; }
	list<Employee*> group; 
	char level;
};

void print_employee(const Employee* e)
{
	switch (e->type) {
	case Employee::empl:
		cout << e->family_name << '\n';
		break;
	case Employee::man:
	{ 
		cout << e->family_name << '\n';
		const Manager* p = static_cast<const Manager*>(e);
		cout << " level " << p ->level << '\n';
		break;
	}
	}
}