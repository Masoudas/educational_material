/**
* Let's say we define a class as follows, and instantiate it with two different templates. It's the job
* of the implementation (and not the programmer) to generate the suitable class definition.
* 
* Depending on the instantiation of the string in the following example, only code for default constructor,
* destructor and operator= are generated (and not for example for the explicit C* constructor, because we 
* didn't use it). Note that the code generated for each template is independent from the other one. 
* Hence, the discussion on code bloating and classes not being able to access each other's private parts!
*/

template<typename C>
class String {
public:
	String() {};
	explicit String(const C*) {};
	String(const String&) {};
	String operator=(const C*) { return {}; };
};


void using_String_class() {
	String<char> s;	// Default constructor and destructor are generated for char type
	String<unsigned char> s1;	// Default constructor and destructor are generated for unsigned char type

	s = "Now, we're generating the assignment operator for char type";

}