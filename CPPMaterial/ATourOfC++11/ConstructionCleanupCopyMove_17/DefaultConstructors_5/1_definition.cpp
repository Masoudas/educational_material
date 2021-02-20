/*
* As we already said, a default constructor is one without arguments. However, we should distinguish
* between one defined by the user, and one assigned by C++ in case of no constructors.
* 
* The default constructor is used if:
* 1-	No arguments are specified (Vector c1)
* 2-	Empty initializer list is provided (Vector c2{}).
* 
* Note that a default argument can make a constructor with single argument into default constructor (
* another reason why C++ supplied constructor cannot be mixed with user defined constructor).
*/
struct MyStruct{
	MyStruct(int j = 10){}	// Both a default and non-default constructor.
};

