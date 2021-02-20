/* This is me:
* From what I've seen, default class operations do what their definition does to every member of their classes:
* 
* 1-	Default constructor initializes every class member with {}.
* 2-	Copy constructor copies every class member (initializes with copy)
* 3-	Move constructor initializes every class member with move semantics (even pointers. The problem
*	however is that it will not move the resource associated with the pointer).
* 4-	Copy assignment sets the members of other class with the copy assignment of each memeber.
* 5-    Move assignment moves members with move assignment of each member.
* 6-	Destructor calls the destructor on every member of the class.
* 
* So, we should use defaults, and avoid rewriting stuff of our own, unless when absolutely necessary.
* 
* As a sidenote, don't forget that these are not the only default operations of a class. For example, there's a new
* as well, as well as a delete operation.
*/
#include <string>
#include <iostream>

using namespace std;

struct my_default{
	string s = "Default val";
};

void default_move_operation_moves_string_from_class() {
	my_default d1{};
	my_default d2 = move(d1);

	cout << "The content of d1 string is now empty: " << d1.s;
}

//int main() {
//	default_move_operation_moves_string_from_class();
//}