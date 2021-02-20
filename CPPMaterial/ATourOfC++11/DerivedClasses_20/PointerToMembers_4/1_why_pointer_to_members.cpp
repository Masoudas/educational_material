/**
* Just like we can point to objects and functions, and define pointers to them, we can define pointer to members
* of a class.
* 
* Suppose we have such pointers, ->* and .* operators allow us to dereference that pointer, where in expression
* x.*y, x is an instance of the class and y is the pointer to to member.
* 
* Why do we need pointer to members? The same reason we need pointer to functions or ordinary objects. Say for 
* example a class like in below has members like resume() or stop(). We don't usually want to tell a user of this
* class which action to use by sending an string message or an integer for that matter. Instead what we do is to
* send a pointer to member, and the user can take advantage of that together with its instance of the class to
* create an object.
* 
* As we can see, we can't be specific about which exact member of the function we want to point to (all of start,
* stop, resume, suspend, ... satisfy the same signature as Ptr_f). But this is to be expected, and it's like when
* defining a pointer to function, we declare a generic signature (like void (*)()) and then any function can be
* assigned to it! Note however the pointer is in one way specific, and it's that it's defined using the class name.
* So, a method of the same signature from another class can't be used here. This is to be expected, because a
* pointer to member defines an offset to the location of the member from the class memory beginning.
* 
* Also notice how we define the pointer to member. It's not done by the reference operator to an instance, but 
* rather to the definition. This is because the offset is always the same, regardless of the instance of the 
* class.
* 
* Finally, notice how we can define a pointer instance directly without aliasing. The name of the instance goes
* inside the paranthesis. So it's not like int* p. 
* 
* A note on usage: As you can see, we have to wrap the expression 'x.*y' in paranthesis, otherwise (at least)
* MSVC throws an error. For example, in the book the big guy does not do the same!
*/

class Std_interface {
public:
	char* p;

	virtual void start() = 0;
	virtual void suspend() = 0;
	virtual void resume() = 0;
	virtual void quit() = 0;
	virtual void full_size() = 0;
	virtual void small() = 0;
	virtual ~Std_interface() {}
};

using Ptr_f = void (Std_interface::*)();	// Pointer to a member of Std_interface that returns a void and accepts to
						  				    // no arguments.
using Ptr_cp = char* (Std_interface::*);	// Pointer to a char pointer member of the class
 
/// <summary>
/// A client receives the object instance and a pointer to a member of it, which it can enact.
/// </summary>
/// <param name="obj">is the object instance of the client</param>
/// <param name="obj_ptr">is a hypothetical pointer to object</param>
/// <param name="ptr">is the function the client has to enact</param>
void client_of_pointer_to_member(Std_interface& obj, Std_interface* obj_ptr, Ptr_f ptr_f, Ptr_cp ptr_cp) {
	(obj.*ptr_f)();

	(obj_ptr->*ptr_f)();	// With pointer to object, the ->* has to be used.
	obj_ptr->suspend();	// Compare it to a direct call.

	(obj.*ptr_cp)[0] = 'c';	 // Dereferencing the pointer to member, and then the char pointer.
}


void passing_pointers_to_client(Std_interface& obj, Std_interface* obj_ptr) {
	Ptr_f ptr_f = &Std_interface::resume;
	Ptr_cp ptr_cp = &Std_interface::p;

	char* (Std_interface:: * ptr_cp1) = &Std_interface::p;	// Name of pointer goes inside paranthesis!
	void (Std_interface:: * ptr_f1)() = &Std_interface::resume;		// Like above!
}
