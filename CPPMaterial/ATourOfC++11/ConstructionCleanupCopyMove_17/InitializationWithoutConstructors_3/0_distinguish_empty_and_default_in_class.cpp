/** 
* When it comes to classes, we must distinguish empty and default constructors.
* 
* An empty (argument) constructor when written overrides the default constructor. Now, if we write {}, 
* the empty constructor that we wrote is called. This is completely different from the empty constructor.
* At least one difference is that with default constructor, when writing {}, all parameters are initialized
* with their corresponding default constructors (see 1_).
* 
* The same notion goes for assignment operator and other constructors and operators, so don't confuse them.
* 
* Note that overwriting the constructors that are not copy or move ctors does not override the rule of five. Only overwriting
* the default ctor keeps the rule of five methods.
*/

#include <type_traits>

struct S {
	S() {}

	// The rule of five methods are kept.
	static void checking_rule_of_five() {
		using namespace std;
		S s{}; 

		S s1{ s };	// Copy ctor
		S s2{ move(s1) };	// Move ctor
	}
};