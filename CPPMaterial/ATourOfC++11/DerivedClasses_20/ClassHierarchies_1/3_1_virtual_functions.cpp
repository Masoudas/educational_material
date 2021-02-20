/**
* Virtual functions overcome the problems with the type-field solution by allowing the programmer to declare 
* functions in a base class that can be redefined in each derived class. The compiler and linker will guarantee 
* the correct correspondence between objects and the functions applied to them.
* 
* So, working on the manager employee problem, we tend to define the print method virtual, and redefine it in
* the hierarchy.
* 
* To allow a virtual function declaration to act as an interface to functions defined in derived classes, the  
* argument types specified for a function in a derived class CANNOT differ from the argument types declared in 
* the base, and only very slight changes are allowed for the return type. (Me: note that even post specifiers
* cannot change from base to derived. For example, a const base class has to be const in derived as well.)
* 
* A virtual member function is sometimes called a method.
* 
* A virtual function must be defined for the class in which it is first declared (unless it is declared to be a 
* pure virtual function.)
* 
* A virtual function can be used even if no class is derived from its class, and a derived class that does not need 
* its own version of a virtual function need not provide one. When deriving a class, simply provide an appropriate 
* function if it is needed.
* 
* Getting "the right" behavior from Employee’s functions independently of exactly what kind of Employee is actually
* used is called polymorphism.
* 
* A type with virtual functions is called a polymorphic type or (more precisely) a run-time polymorphic type.
* To get runtime polymorphic behavior in C++, the member functions called must be virtual and objects must be 
* manipulated through pointers or references. When manipulating an object directly (rather than through a pointer 
* or reference), its exact type is known by the compiler so that run-time polymorphism is not needed (Me: again, 
* implying that slicing an object does not result in run-time polymorphism).
* 
* By default, a function that overrides a virtual function itself becomes virtual. We can, but do not have to, 
* repeat virtual in a derived class. The big guys doesn't recommend repeating virtual. He says 'If you want to be 
* explicit, use override.'
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
	}
};