/**
* We can alias function pointers with using. Note that we can actually eliminate the (*) part 
* when defining an alias!
*/
namespace function_pointer {
	using fp_1 = int(*)(int, int*);
	using fp_2 = int(*)(int, int(*)(int, int*));	// Uses a function pointer as argument
	//using fp_3 = int(*)(int, fp_3);		// As always, you can't use another alias when defining an alias.
	using fp_4 = int(int, int);
}