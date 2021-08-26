/**
* Bracketless initialization is possible when there are no constructors, or just an empty
* constructor. By bracketless we mean something like "T v;". 
* 
* Me: Note that no matter what happens, user-defined types are initialized with (default) constructors. Our only 
* fight is with built-in types and built-in arrays! A user-defined type CANNOT Be constructed without calling some 
* form of ctor. This includes the bracketless initialization 'T t'
*
* Me: Note that an empty ctor initializes everything with empty ctor, both for built-in and custom types. So,
* here, we're talking about situations where the default ctor has been overridden.
* Recall that heap built-in and user defined types are always built with constructors. Hence:
*	- An object built on heap, is built with member ctors (even built-in types declared with no ctors)
*	- Stack objects are created randomly (memory allocated but content is random) if there's no default ctor for
*	  the class. Otherwise, built with default ctor.
* So, just think about whether memory is allocated on heap or stack! Of course, static objects are always built
* cleanly.
* 
* We consider two situations:
* 1-	There's an empty constructor (not the default one I mean): static objects initialize built-in and user
*	types to {}. For auto and heap objects, the values are random.
* 
* 2-	Default constructor: If initialization is static, then the built in types are initialized
*	with defualt constructors, as well as other types. Otherwise, if automatic variable, built-in types have
*	random values, but user types are built with default constructor. With heap objects, again
*	everything will be initialized with default constructor.
* 
* Note that the above is true if there are no private invariants. If there's one, memberwise initialization
* is impossible.
* 
* Note that even with an array, when initialization does occur, all elements are set to default 
* (for example, buf elements are set to '\0')
* 
* If object is built on heap, using bracket or not, the values would be random unless explicitly initialized.
* 
* (Me: Essentially, globals are very clean, and everything built there should be generated cleanly.
* Stack and heap are not very clean, and whatever built there takes what is already in memory).
*/
#include <iostream>
#define INITIALIZE_STATICS 
using namespace std;

struct only_empty_constructor {
	int i;
	char buf[10];
	
	only_empty_constructor() { 
	};

	void print(){
		cout << "\nEmpty constructor" << endl;
		cout << "Value of i is " << i << endl; 
		cout << "buf elements are initialized to " << buf[0] << endl;
	}
};

struct has_default_constructor {
	int i;
	char buf[10];

	void print() {
		cout << "\nHas default constructor" << endl;
		cout << "Value of i is " << i << endl;
		cout << "buf elements are initialized to " << buf[0] << endl;
	}
};

struct has_non_default_constructor {
	int i;

	has_non_default_constructor(int i): i(i) {

	};
};


#ifdef INITIALIZE_STATICS
	only_empty_constructor c1;// evrything is initialized with empty constructor.
	has_default_constructor d1;
#endif
void bracket_less_initialization() {
	only_empty_constructor c2;	// Worst kind! Everything to random, because no default ctor
	only_empty_constructor* c4 = new only_empty_constructor;	// random values (me: but not in gcc for
																// example!).
	
	// has_non_default_constructor c4;	This is not possible! Jesus. Imagine having to check for exception
	// when opening a file or something!

	has_default_constructor d2;	// Everything is default initialized (default ctor)
	has_default_constructor* d4 = new has_default_constructor;	// Default construction of all elements.
	
#ifdef INITIALIZE_STATICS
	c1.print();
	d1.print();
#endif
	c2.print();
	c4->print();

	d2.print();
	d4->print();
}

//int main() {
//	bracket_less_initialization();
//}