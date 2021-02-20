/**
* Sometimes, we want to create a new namespace, that has certain elements of several namespace put together.
* We can do so, by just creating the new namespace, and dragging in the elements from other
* namespace.
* 
* The question is, how do we drag all the elements of the other namespace here? The answer is by using
* the syntax 'using namespace ...'. Note that there's no such thing as 'using namespace::' or 'using namespace::*'
* The using declarative needs to declare a particular element to brings in.
* 
* Note however that once an element is dragged into our new namespace, the user of the new space would
* not be aware of the fact a particular element belongs to another namespace.
* 
*/

namespace His_string {
	class String { /* ... */ };
	String operator+(const String&, const String&);
	String operator+(const String&, const char*);
	void fill(char);
	// ...
}

namespace Her_vector {
	template<class T>
	class Vector { /* ... */ };
	// ...
}

namespace My_lib {	// This is the composed namespace.
	using namespace His_string;	// Drag all elements of the other namespace.
	using namespace Her_vector;

	void my_fct(String&);
}

// Naturally, this is wrong. An element has to be defined in the namespace it's declared.
//void My_lib::fill(char c){} // error : no fill() declared in My_lib
