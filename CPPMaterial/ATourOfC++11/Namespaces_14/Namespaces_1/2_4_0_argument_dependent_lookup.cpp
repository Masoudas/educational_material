/**
* The fourth method of referring to a namespace is through argument lookup.
* 
* Normally a function is defined in the namespace of its arguments. Here's however where things get interesting.
* If this is not the case, compiler will start looking for the function in the namespace of the arguments!!!
* 
* Why on Earth would it want to do this? Bjarne says:
* "This lookup rule (called argument-dependent lookup or simply ADL) saves the programmer a lot of 
* typing compared to using explicit qualification, yet it doesn’t pollute the namespace the way a 
* using-directive"
* 
* Note that this rules only if the function is not in the namespace it's being called. If it's in the namespace
* being called, we just use it, like always! In fact, if it's in the namespace and we give it the wrong arguments,
* hoping it would find the correct name space, we get an error. Note also that this rule does not apply to
* built-in types, because compiler can't perform a look up based on built-in types.
* 
* Note that the namespace itself needs to be in scope and the function must be declared before it 
* can be found and used.
*/
#include <string>

namespace Chrono1{
	class Date{};
	bool operator==(const Date&, const std::string&) { return false; }
	std::string format(const Date&) { return ""; };
}

void argument_look_up(Chrono1::Date d, int i) {
	std::string s = format(d); // Chrono::for mat(). Why? Because of ADL.
	// std::string t = format(i); // error : no format() in scope.
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
namespace b_ns {
	struct a_type {};

	void f(const a_type& t) {}

	void f(int) {}
}

namespace a_ns {
	struct Type{};
	
	void f(int) {}

	void f(const Type& t){ 
		f({});	// Using this f, no look up, naturally!
		
		using b_ns::a_type;
		f(a_type{});	// Using f of b_ns

		f(5);	// Definitely using this f. No argument look up based on built-in.
;	}


}


//int main(){}