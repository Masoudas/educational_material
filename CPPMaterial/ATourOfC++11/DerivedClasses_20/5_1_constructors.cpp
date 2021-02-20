/**
* Question: Why do we need to call the base class constructor at all? Can't we just instantiate the base part
* of the class in the dervied class? The answer is no. Because construction is not just a matter of initialization,
* it's also dealing with the memory, and setting the functions of the class in a memory location. Hence, the need
* to construct the derived class does not just end with initialization of invariants.
* 
* In summary, classes are constructed from base to derived, and destructed the other way around. The big guy 
* points to these following points:
* 
* - Objects are constructed from the bottom up (base before member and member before derived) and destroyed  
*	top-down (derived before member and member before base)
* -	Each class can initialize its members and bases (but not directly members or bases of its bases);
* - Typically, destructors in a hierarchy need to be virtual
* - Copy constructors of classes in a hierarchy should be used with care (if at all) to avoid slicing
* - The resolution of a virtual function call, a dynamic_cast, or a typeid() in a constructor or destructor  
*	reflects the stage of construction and destruction (rather than the type of the yet-to be-completed object)
*
* To investigate the last point a bit further, we might ask what happens if a constructor calls a method and a
* virtual method of a class? With a normal method, we know that the method will be called, even if the object
* hasn't been properly constructed yet. With the virtual method, wouldn't it be the same? Because we know that
* a virtual call is resolved only if we call the method from the derived class? Well, it's said that calling such
* a method is dangerous and should be avoided. The problem is that if we call a virtual method in the base class
* constructor, it will not resolve to the last override, because the derived classes have not been constructed.
* 
* Hence for example in the following, when we instantiate the derived class, during the construction of the base
* class, m from the base class is called (even though it's virtual), which is to be expected, because the derived
* class is not constructed yet!
* 
* Note that even if the method hides a name from based class (like g for example), we still call the right method
* in the base and derived class. So no worries there too.
* 
* The problem seems to be that until the class construction is complete, the virtual function table is not complete
* for some reason. So, call to virtual functions seem to be the only problem.
* 
*/
#include <iostream>

class m_base {
public:
	m_base() {
		m();
		g();
	};
	m_base(const m_base&) = delete;
	void operator=(const m_base&) = delete;

public:
	virtual void m() {
		std::cout << "inside base virtual method" << '\n';
	}

	void g() {
		std::cout << "inside base non-virtual method" << '\n';
	}
};

class m_derived : public m_base {
public:
	m_derived() {
		f();
		m();
		g();
	};

	m_derived(int) {}

	void m() override {
		std::cout << "inside derived virtual method" << '\n';
	}

	void f() {
		std::cout << "inside unique method of derived" << '\n';
	}

	void g() {
		std::cout << "inside derived non-virtual method" << '\n';
	}
};

//int main() {
//	std::cout << "Making derived class with virtual constructor method\n";
//	m_derived d{};
//
//	// m_base b = m_derived{}; Not possible, thankfully with removing copy constructor
//	std::cout << "\nMaking base class pointer\n";
//	m_base* b = new m_derived{};	// Still Ok! Base class is constructed and address is assigned to b.
//}