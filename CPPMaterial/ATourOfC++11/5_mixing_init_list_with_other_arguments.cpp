/**
* This all from me:
* 
* The only case where initializer_list constructors would take precedence over other constructors are in 
* constructors as the standard declares (See C++ Weekly episode on C++'s most vexing parsing problem). 
* Otherwise, if we put them together with other types, then init list params have to be supplied with braces 
* to avoid ambiguity. Let me put it this way. It's only in a CONSTRUCTOR and only if THERE'S A SINGLE init_list
* and only if WE USE BRACKET INITIALIZATION that init_list takes precedence. In all other cases, particularly
* if we use brackets, it's assumed that we're passing arguments. 
* 
* Because of the above statement, note that with functions, we can never pass have this ambiguity.
*/
#include <initializer_list>
#include <iostream>

struct s {
	s(std::initializer_list<int>, const char*) { std::cout << "Inside init list constructor"; };
	s(int, int, const char*) { std::cout << "Inside argumentative constructor\n"; }
};

void initialization_cases() {
	s s1{ 5, 5, "uses argument constructor!" };
	s s2{ { 5, 10, 3 }, "uses init list constructor constructor!" };	

	// s s2{  5, 10, 3 , "Error! Passing four arguments. No overload was found." };
	// s s2{  5 , "Error! Passing one arguments. No overload was found." };

};

