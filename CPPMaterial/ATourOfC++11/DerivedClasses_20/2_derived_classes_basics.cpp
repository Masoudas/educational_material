/**
* The famous example of a derived class is the manager-employee class. As we already know, a manager is a kind 
* of employee, and by failing to specify this construct to the compiler, we're missing something. In particular, 
* a Manager* is not an Employee*, so one cannot simply use one where the other is required.
* 
* Now, if manager is derived from employee, we could write employee* = manager* or employee& = manager (and we 
* shall never write employee = manager, for it slices the base class. Note that conversion from dervied to base
* class is implicit for this case).
* 
* In such terminology, we can for example create a list of employees that include the manager. 
* 
* In general, if a class Derived has a public base class Base, then a Derived* can be assigned to a variable of  
* type Base* without the use of explicit type conversion.
*/
#include <list>
#include <string>

using namespace std;

struct Employee 
{
	string first_name, family_name;
	char middle_initial;
	string hiring_date;
	short department;
	// ...
};

/* Does not take advantage of hierarchy.
struct Manager {
	Employee emp; // manager’s employee record
	list<Employee*> group; // people managed
	short level;
	// ...
};
*/

struct Manager : Employee 
{
	list<Employee*> group; // people managed
	short level;
	// ...
};

void create_employees_from_manager_and_emplyee(Employee& e, Manager& m) 
{
	list<Employee*> l{ &e, &m };
}

void manipulating_references(Manager mm, Employee ee)
{
	Employee* pe = &mm; // OK: every Manager is an Employee
	// Manager* pm = &ee; // error : not every Employee is a Manager
	// pm -> level = 2; // disaster : ee doesn’t have a level
	Manager* pm = static_cast<Manager*>(pe); // brute force: works because pe points to the Manager mm
	pm -> level = 2; // fine: pm points to the Manager mm that has a level
}