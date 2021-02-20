/** This is still me:
* We know that there's not much drama associated with passing a pointer to a function. The issue arises when we
* want to pass references, or create references to a template. 
* 
* Let's think about some fundamental cases. Can we instantiate a template directly? For example, can I say in a
* templated function T x = string{}? Well. Of course not. Because if I can deduce the type of something, it's not
* a template. Therefore, all we're talking about is when passing arguments to a function, or instantiating a class
* with a particular template.
* 
* Can we initialize a templated type with lvalue reference? Yes! So for example in the following method, we increment
* the templated type by one, and if we instantiate with an lvalue, the instance is increased by one on the outside,
* and by just type is not!
* 
* Consequently, we see that a templated type can be reference qualified. It can even be CV qualified, or it can be
* a pointer. In all such cases, a substitution takes place.
* 
* Note that in all cases, what is deduced from the argument should be equal to what we supply as template type.
* 
* There's one point however here. If I had a function like a_simple_int_function and I passed in 0, it would be
* normal and the function instantiates t with 0. The same story happens with a templated type. If I pass zero to
* a templated type, the type of the template is deduced as int. This is regardless of whether or not the template
* has cv qualifications (or even reference qualification as we discuss next). So the type is not deduced as rvalue
* refernece, because, world is not that complicated.
*/
#include <iostream>

template<typename T>
void templated_augmenter(T t) {
	t++;
}

void a_simple_int_function(int t) {
}

void using_templated_augmenter() {
	int i = 0;

	std::cout << "with int, type is copied, and no increment is seen outside:\n";
	templated_augmenter(i);	
	std::cout << "(int)i == " << i << "\n \n" ;

	std::cout << "with int&, type is passed by lvalue reference, and increment is seen outside:\n";
	templated_augmenter<int&>(i);
	std::cout << "(int&)i == " << i << "\n \n";

	std::cout << "with int&&, same story happens:\n";
	templated_augmenter<int&&>(std::move(i));
	std::cout << "(int&&)i == " << i << "\n \n";


	a_simple_int_function(0);	// We know that this is fine.
	templated_augmenter(0);	// Naturally, we expect this type to be deduced as int too!

	// templated_augmenter<const int*>(&i);

	// templated_augmenter<const int&>(i); This is semantically correct, however an error is thrown, because of
	// assigning to a const
}


//int main() {
//	using_templated_augmenter();
//}
