/**
* Example 3: Maintaining invariants
* 
* Consider the following handle class. Handle keeps the pointer, and deletes it when going out of scope.
* The absence of a default constructor saves from deleting a non-existing pointer. 
* 
* Based on C++ standard, Handle defines a destructor. Hence, move and copy operations are removed, which is a 
* good move. Because a copy would cause double deletion of resource (something which is not the case in 
* VS unfortunately).
* 
* This example clearly illustrates the chaining between destructor and move and copy constructors.
* 
* In general, if a class has a pointer member, the default copy and move operations should be considered suspicious.
* If that pointer member represents ownership, memberwise copy is wrong. If that pointer member does not 
* represent ownership and memberwise copy is appropriate, explicit =default and a comment are most likely a 
* good idea.
* 
* Note that an appropriate copy constructor here is something like:
* Handle(const Handle& ref) : p(new T{*ref.p}){}	// Only copies the first element if an array!
* 
*/

template<class T> 
class Handle {
	T* p;
public:
	Handle(T* pp) :p{ pp } { }
	Handle(const Handle& ref) : p( new T{*ref.p} ) {}
	T& operator*() { return *p; }
	~Handle() { delete p; }
};

void using_handle() {
	Handle<int> h1{ new int[2] };
	Handle<int> h2{ h1 };	// Too bad!!!
}

//int main() {
//	using_handle();
//}