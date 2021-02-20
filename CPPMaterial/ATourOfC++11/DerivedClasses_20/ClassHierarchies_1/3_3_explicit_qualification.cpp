/**
* Calling a function using the scope resolution operator, ::, as is done in Manager::print() ensures that
* the virtual mechanism is not used. (Me: And perversely enough, another idea is to slice the class!).
* 
* The use of a qualified name has another desirable effect. That is, if a virtual function is also inline (as is 
* not uncommon), then inline substitution can be used for calls specified using ::. This provides the programmer 
* with an efficient way to handle some important special cases in which one virtual function calls another for 
* the same object. The Manager::print() function is an example of this. Because the type of the object is 
* determined in the call of Manager::print(), it need not be dynamically determined again for the resulting call 
* of Employee::print(). 
*/
#include <string>
using namespace std;

class employee {
	string first_name, family_name;
	short department;
public:
	employee(const string& name, int dept) {}
	void virtual print() const {
	}
};

class manager : public employee {
public:
	void print() const override {
		employee::print();	// Ok! calling the base class method first!
	}
};

class cfo : public manager {
	void print() const override {
		employee::print();	// Ok! calling the employee in third level of hierarchy!
	}
};