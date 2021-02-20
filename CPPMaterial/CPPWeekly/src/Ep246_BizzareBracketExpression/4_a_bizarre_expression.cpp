/**
* Based on the previous discussions, we have the following bizarre expression!
* The internal [](){} is a lambda, and the plus sign turns it into a function pointer. Now, we use this type to
* pass void, using the right hand side paranthesis. The left hand side paranthesis are not required I think,
* and they're like saying (f)(), where f is a function pointer.
* 
* Then again, it's odd to me that this does not work. I think VS does not allow conversion from closure to
* function pointer.
*/

void a_bizarre_expression() {
	//(+[]() {})(); Does not work.
	
}