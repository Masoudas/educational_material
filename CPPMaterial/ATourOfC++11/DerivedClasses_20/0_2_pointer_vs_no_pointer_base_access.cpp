/** This is me:
* Here's an important point. Suppose a base class a virtual method, and we have a derived class. What happens
* when we assign the dervied class to 1- Base class, 2- Base class reference, 3- Base class pointer, and then
* call the virtual method?
* 
* Starting from 3rd, the reference in memmory is to base class, so the overriden method is called. With the second,
* again, the base class reference still points to the memory of derived class, so we call the derived method. With
* the first one, however, when we create the base class reference, we're actually calling the copy constructor. 
* Therefore, when construction is complete, we have an object in memory that points to the BASE object, and not the
* derived (because after all it's a copy). Therefore, calling the virtual method prints the base class method.
* 
* Actually, this is what is most commonly known as object slicing!
* 
* Note finally that this is the reason why we prefer not to have a copy constructor in the base class of hierarchies
*/
#include <iostream>
using namespace std;

class instrument {
public:
	virtual void play() { cout << "no sound" << endl; }
};

class drum : public instrument {
public:
	void play() {
		cout << "dum, dum" << endl;
	}
};

//int main() {
//    instrument i;
//    drum d;
//
//    instrument pi = d;	// Here. the copy constructor is being called. The object made is of base type.
//    pi.play();  // Plays Nothing!
//
//	instrument &pi_ref = d;	// Here, the reference points to the memory belonging to a drum type.
//	pi_ref.play();  // Plays dum, dum
//
//	instrument* pi_ptr = &d;	// Again, pointing to a memory belonging to drum.
//	pi_ptr->play();  // Plays dum, dum
//
//}