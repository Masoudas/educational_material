/** 
* Note that in C++, I can assign a pointer to a base member to derived class. This is called contravariance, and it
* guarantees that this pointer always has a value (note that this opposite to assigning a derived class pointer to
* a base class pointer). However, the pointer value itself points to the base class memory. Thus, the function that
* would be called is that of the base class.
* 
* In what follows, I examine three cases. The conclusion is that if we have a pointer to a virtual method, it's
* resolved to the correct override, regardless of whether the pointer comes from base or derived class. For non
* virtual methods however, the pointer acts literally. i.e, if the pointer points to the base class method, it
* calls the base class method, otherwise it calls the derived class method.
* 
* This is a very good reasonable behavior on the part of C++.
*/
#include <iostream>

class Std_base {
public:
	char* p;

	void start() { std::cout << "inside base start method\n"; };
	virtual void suspend() = 0;
	virtual void resume() = 0;
	virtual void quit() = 0;
	virtual void full_size() = 0;
	virtual void small() = 0;
	virtual ~Std_base() {}
};

class Std_derived : public Std_base {
public:
	void start() { std::cout << "inside derived start method\n"; };
	void suspend() override { std::cout << "inside derived suspend method\n"; };
	void full_size() {}
	void small() {}
	void quit() {}
	void resume() {}
};

void assigning_derived_member_to_base_pointer() {
	// void (Std_interface::* pmi)() = &Text::print; // Error. Assigning pointer of derived to base.
	void (Std_derived:: * pmt)() = &Std_base::start; // OK. Assing pointer of base to derived
}

/// <summary>
/// This is a natural case. Because we don't have a pointer to derived class member, we create a pointer to base,
/// and we pass it along with a derived object. Would it call the derived class method if:
/// - method is virtual? Naturally yes. We expect an overridden call to be resolved.
/// - method is not virtual? Then, because the pointer is literal, it calls the base method. Literally!
/// </summary>
void pointer_to_methods_of_base_with_base_reference_of_derived() {
	void (Std_base:: * pmt_virtual_base)() = &Std_base::suspend; // Getting pointer of base method.
	void (Std_base:: * pmt_non_virtual_base)() = &Std_base::start; // Getting pointer of base method.

	Std_derived t{};
	Std_base& b = t;
	(b.*pmt_virtual_base)();
	(b.*pmt_non_virtual_base)();
}

/// <summary>
/// Now, this time, we use the address to derived class methods. In other words, we try and call derived class
/// methods, using a reference to base class. But this is impossible! We can't call a derived class method 
/// from the base reference. Thank God! Else, this would have been like calling derived class methods from base
/// reference!
/// </summary>
void pointer_to_methods_of_derived_with_base_reference_of_derived() {
	void (Std_derived:: * pmt_virtual_base)() = &Std_derived::suspend; // Getting pointer of base method.
	void (Std_derived:: * pmt_non_virtual_base)() = &Std_derived::start; // Getting pointer of base method.

	Std_derived t{};
	Std_base& b = t;
	//(b.*pmt_virtual_base)(); Error! Calling derived class method from base reference!
	//(b.*pmt_non_virtual_base)();	Error! Same as above
}

/// <summary>
/// This is the last case worth investigating. What happens if we have pointers to base members, and an instance
/// of derived class (or reference for that matter). In this case:
/// - virtual method: It's solved like it should
/// - non-virtual method: We'd call base class method! which is very cool!
/// </summary>
void pointer_to_methods_of_base_with_derived_reference() {
	void (Std_base:: * pmt_virtual_base)() = &Std_base::suspend; // Getting pointer of base method.
	void (Std_base:: * pmt_non_virtual_base)() = &Std_base::start; // Getting pointer of base method.

	Std_derived t{};
	(t.*pmt_virtual_base)();
	(t.*pmt_non_virtual_base)();
}

//int main() {	
//	pointer_to_methods_of_base_with_derived_reference();
//}