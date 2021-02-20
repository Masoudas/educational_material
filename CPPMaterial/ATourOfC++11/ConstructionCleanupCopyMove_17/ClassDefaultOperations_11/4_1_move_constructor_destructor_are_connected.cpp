/**
* Example 1: Default constructor:
* 
* In the following case, had the compiler generated a default by default, it would have violated the user's
* need for having an integer to construct the class. Hence, the compiler does not generate the default constructor
* if any constructor is defined by the user.
*/
struct X {
	X(int); // require an int to initialize an X
};
