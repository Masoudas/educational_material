/**
* First off, note that we can assign a derived class pointer to a base class pointer, which is natural and
* necessary when it comes to for example factories. Note of course slicing is possible with a simple assignment
* in this case.
* 
* When it comes to arrays, however, we can't assign an array of a derived class to base, due to slicing (among
* other things) and fortunately smart pointers help us avoid this problem. To further understand why this is the
* case, read chapter 20, section 5.
* 
* As a reminder, to create an array of base pointers, it's best to use a vector together with a smart pointer.
* See chapter 20, section 5 for the reason.
* 
*/
#include <memory>

class Shape {
	// ...
};

class Circle : public Shape {
	// ...
};

void ok_to_assign_derived_class_pointer_to_base_pointer() {
	std::unique_ptr<Shape> base{ new Circle{} };

	std::unique_ptr<Shape> base1 = std::unique_ptr<Circle>{ new Circle{} }; // Fine! Templated move ctor!

	Circle derived = Circle{};
	*base = derived;
}

void no_assignment_of_derived_array_to_base_array() {
	//std::unique_ptr<Shape[]> pa{ new Circle[] {Circle{}, Circle{}}; // error

	Shape* b = new Circle[]{ Circle{}, Circle{} }; // This is fine though!

}

//int main() {
//	no_assignment_of_derived_array_to_base_array();
//}