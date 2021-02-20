/**
* A class generated from a template is a perfectly ordinary class. Thus, use of a template does
* not imply any run-time mechanisms beyond what is used for an equivalent ‘‘handwritten’’ class.
* (Me: perhaps this should be interpreted as follows: When we declare a template, run-time instantiation
* causes (the linker?) to only generate a version of class or method with that parameter. This class
* or method, like any other class we may define, is independent for each instantiation. Consider the
* example below, which is mine:)
* 
* Bjarne says: Using template may cause decrease in amount of code, because if a template is not used,
* its templated version is not generated (as opposed to the case where we might define everything by hand).
*/
template <typename T>
struct templated { T t; };

/**
templated<int> d1{};	
templated<char> d2{};

This is equivalent to writing the following class by hand. I add the type name to class name to embolden
what happens.

templated_int{int t;};

templated_char{char t;};

Now, we can deduce conclusions.
1- Code bloating happens when we instantiate everytime with a different template.
2- Each class has its own private definition. Hence, we can't access the templated version of class with 
a different template. For example, a with with the following signature in the class can't access the private
parameters of int instantiation:

template<typename T>
templated<T>::f(templated<int> c){
	c.t; // Not possible! We can't access private member of another instantiation!
}

*/