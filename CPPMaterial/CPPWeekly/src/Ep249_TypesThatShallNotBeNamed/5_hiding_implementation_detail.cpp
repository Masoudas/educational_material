/**
* As is the case, hiding the type can be useful when we want to hide the implementation detail. Consider the
* following example, where we return a base class object, but in reality, we're creating a derived class 
* object. (Note: Pay attention to the fact that unique_ptr template type is NOT a pointer, but rather, the
* type itself. Think of unique_ptr as the * around the type, and also making sure the ptr goes out of scope
* properly.)
* 
* Although this example suffers from slicing (which may cause memory leak if new fields are added), but because
* we have not added new data, this is going to be fine (Although I'm not one hundered percent sure about this, but 
* most probably, deletion of the base reference in this case deletes the entire trace of the derived class).
*/

#include <memory>

struct base {
	virtual int return_val() = 0;
};

std::unique_ptr<base> factory() {
	struct derived : base {
		int return_val() { return 42; }
	};

	derived* d = new derived{};
	return std::unique_ptr<base>(d);
}

//int main() {
//	std::unique_ptr<base> ptr = factory();
//	ptr->return_val();
//}
