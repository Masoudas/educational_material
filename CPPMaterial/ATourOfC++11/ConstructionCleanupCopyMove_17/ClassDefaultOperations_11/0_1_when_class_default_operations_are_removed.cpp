/** This is all me:
* The following are observed in VS. However, these are not the general rules of C++.
* As a rule of thumb, I better use the default operation for the class, an not override it, unless there's a
* good reason to do so.
* 
* Defining ANY constructor explicitly removes the default constructor. For example, defining move 
* constructor removes default constructor.
* 
* Defining either the move or copy constructor removes the other one (and of course the default). This is the C++
* general rule as well. 
* 
* By inspection, I've seen that overriding the default assignment operations does not remove the constructors.
* Moreover, it does not remove the other assignment operator as well.
* 
* By inspection, I've seen that if we override move constructor, all assignment operators are removed as well.
*
* By inspection, I've seen that if we override copy constructor, the copy assignment remain in tact.
* 
* The destructor however always seem to remain intact regardless, which again does make sense, because we need
* a destructor, always. Even overriding the destructor does not remove the other default methods.
* 
*/
#include <iostream>
struct removing_default_move_constructor {
	removing_default_move_constructor() {}
	removing_default_move_constructor(removing_default_move_constructor&& ref) noexcept {}
};

struct removing_default_copy_constructor {
	removing_default_copy_constructor() {}
	removing_default_copy_constructor(removing_default_copy_constructor& ref) noexcept {}
};

struct movee{

	void operator==(movee& red) { std::cout << "here"; }
};




void checking_if_removed() {
	removing_default_move_constructor d1{};
	removing_default_move_constructor d2 = removing_default_move_constructor(std::move(d1));	// only move remains


	removing_default_copy_constructor c1{};
	removing_default_copy_constructor c2{};

	c2 = c1;
	movee e1{};
	movee e2{};

	e2 = std::move(e1);	// This would not call the copy assignment, but rather the move assignment.
}


