/** This is from the internet
* An interesting situation is shown below, where if we define a using at the end of the class, we can't use it in for 
* example a return statement of a function, or as argument to the function, which makes us wonder why?
* 
* The answer is this has to do with the complete-class context. When you are in the body of a member function, the class 
* is considered complete and can use anything defined in the class, no matter where in the class it is declared.
* 
* The return type of a member function is not part of the complete-class context so you can only use names that are known 
* about at that point in the code.
*/

struct correct_aliasing {
	using type = int;

	type f() {
		return 5;	// fine
	}
};

struct incorrect_aliasing {
	//type f() {
	//	return 5;
	//}

	using type = int;
};