/**
* As the standard indicates, "another name for RAII is "Scope-Bound Resource Management (SBRM)," after the 
* basic use case where the lifetime of an RAII object ends due to scope exit."
* 
* For example, a function may be given an object, and then throws an exception. In such a case, it would not
* be able to delete the resource. Using pointer management functions allow use to take care of the allocated
* resources, which is what RAII is intended to mean.
* 
* Hence, we see that the clean-up of the block safely removes the unique pointer (up) but the ptr is not 
* taken care of.
*/
#include <iostream>
#include <memory>

struct my_S {
	my_S() { }
	~my_S() { std::cout << "destructing my_S\n"; }
};

void accepting_resources(my_S* ptr, std::unique_ptr<my_S> up) {

	throw std::string{ "Exception occured here." };
	delete ptr;	// Oops, we didn't get to here. Resource remain in memory and is leaked
}

void method_not_implementing_rai() {
	my_S* ptr = new my_S{};
	auto up = std::make_unique<my_S>();

	try {
		accepting_resources(ptr, std::move(up));
	}
	catch (std::string& s) {

	}

	// Note that up now holds nullptr, and it can be deleted safely.
	// It DOES NOT contain my_s. It has been moved inside the object!

	// ptr is still a valid object here.
}

//int main() {
//	method_not_implementing_rai();
//}