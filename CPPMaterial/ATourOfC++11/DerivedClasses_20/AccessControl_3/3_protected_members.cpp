/**
* Protected members are used for providing actions for derived classes that are prohibited for the external users
* of the class, such as unchecked access to an array.
* 
* A derived class can access a base class’s protected members only for objects of its own type. (Me: This does make 
* sense, because a derived class is not supposed to manipulate the base class.) 
* 
* The big guy says: "In particular, declaring data members protected is usually a design error."
*/

class base {
protected:
	char a[128];


};

class derived : public base {
	void accessing_base_protected(base* b) {
		a[0] = 'a';		// Fine, accessing its own protected member.
		// b->a[0] = 'a'; Error! Can't access the protected member of another instance!

	}
};