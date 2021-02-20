/**
* delete works for explicitly removing a function. The most obvious application is to remove default
* operations of a class.
* 
* There are more interesting cases however. For example, we can declare deletion of a specialization of
* a template. We need to delete the specialization after declaring the function.
* 
* We can also use it to remove an undesired conversion.
* 
* Finally, we know that we can use delete to ensure that a class is not allocated on stack for example, by removing
* its destructor.
* 
* Note the difference between deleted and undefined methods. For example, a conversion to int might take place between
* if int method has not been deleted in the example below.
*/

template<class T>
T* cloner(T* p) // return copy of *p
{
	return new T{ *p };
};

struct Foo{};

Foo* cloner(Foo*) = delete; // don’t try to clone a Foo

struct Z {
	// ...
	Z(double); // can initialize with a double
	Z(int) = delete; // but not with an integer
};

//Z z{1}; Cannot convert from int to double.