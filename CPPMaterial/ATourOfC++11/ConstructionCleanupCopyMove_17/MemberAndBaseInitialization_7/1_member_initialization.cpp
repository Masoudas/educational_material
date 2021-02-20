/*
* As we already know, objects are initialized by first calling their base constructors, then member constructors
* and finaly executing the body of the current constructor. The reverse happens during destruction (
* including calling the destructor of members).
* 
* Member constructors are placed after a constructor with a colon, and then comma for each member.
* They are called in the order they're defined in THE CLASS, not in the order of their declaration.
* A good compiler shows a warning if the order differes when invoking member constructors. VS does not
* do it.
* 
* **** Always DISTINGUISH BUILT_IN TYPES FROM USER DEFINED TYPES *********
* 
* The point to remember here is that any constructor (especially the default) will invoke member
* constructors for USER DEFINED types. So:
* 
* 1-	If a member constructor requires no arguments, it needn't be called here. It will be constructed 
* automatically.
* 2-	If a member has non-default constructor, it has to be explicitly called!
* 
* As we may recall, for built-in types, constructors are not called implicitly!
* 
* Note: Obviously, a class cannot initializer the members of a base class' base.
*/
#include <iostream>
using namespace std;

struct member {
	int i;
	member(): i(0) { cout << "Constructing member" << endl; } 
};

struct member_non_empty_construct {
	member_non_empty_construct(int n){ cout << "Constructing member with non-empty construct" << endl; }
};

struct MyStruct
{
	int i;
	char* p;
	member m1;
	member_non_empty_construct m2;

	// MyStruct(): {}	// Error! m2 has non-default constructors only. It should be explicitly called here.
	MyStruct() : m1(), i(), p(), m2(10) {}	// Ok, but in wrong order! a warning should be shown.
	MyStruct(int m2) : m2(m2) {}	// Ok. Other variables are initialized with default constructor.

};

void initializing_members() {
	MyStruct s1{ 10 };

	cout << "i is random because built-in type: " << s1.i << '\t' << "and p is random too " << int(s1.p) 
		<< "\nbut m1 is built with default constructor: " << s1.m1.i << endl;
}


//int main() {
//	initializing_members();
//}