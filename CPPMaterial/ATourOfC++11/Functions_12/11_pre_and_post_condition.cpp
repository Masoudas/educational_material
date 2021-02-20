/*
* preconditions and post conditions refer to a set of assumptions about the content of function arguments.
* Compiler can check if the type of the argument is correct, but it can't check if a value is logically 
* correct. For example, with the area function, we may give width and height that overflow.
* 
* We call logical criteria that are supposed to hold when a function is called preconditions, 
* and logical criteria that are supposed to hold when a function returns its postconditions.
* 
* What should we do about a call area(numeric_limits<int>::max(),2)? Is it the caller's responsibility
* to avoid it? Or the implementer to check for it?
* 
* If a function depends only on its arguments, its preconditions are on its arguments only. However, 
* we have to be careful about functions that depend on non-local values (e.g., a member function that 
* depends on the state of its object). In essence, we have to consider every nonlocal value
* read as an implicit argument to a function. Similarly, the postcondition of a function without side
* effects simply states that a value is correctly computed, but if a function writes to nonlocal objects,
* its effect must be considered and documented.
*/

/*
calculate the area of a rectangle
precondition: len and wid are positive
postcondition: the return value is positive
postcondition: the return value is the area of a rectange with sides len and wid
*/
int area_of_rectangle(int width, int height) {
	return width * height;
}