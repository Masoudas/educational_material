/**
* If the type of the template cannot be deduced correctly, it has to be declared explicity. (Me: This is 
* particularly important when we overload).
* 
* (Me: The compiler can only deduce the type from function arguments, and NOT its return type).
* 
* A particulary common case of specifying the template parameter is when the argument type and the return 
* type are different. This is the case that we use a lot in practice with ... wait for it ... TYPE CASTING!
* This point is shown with the type caster function below. Here's an interesting point. The second type has
* not been specified with the type caster. Hence, every type that can be deduced need not be specified.
* 
* Now, just to toy with you, we change the location of template T, U in the declaration. We see that we
* need to specify both the types now! We can't escape the first type using a simple comma for example.
*/

template<typename T>
T* factory() { return new T{}; };

void factory_user() {
	int* p = factory<int>(); // Needs specification of parameter.
	char* w = factory<char>();
}

template<typename T, typename U>
T type_caster(U u) { return T{}; };

template<typename T, typename U>
U reverse_type_caster(T u) { return T{}; };

void using_type_caster() {
	int w = type_caster<int>(5);

	int w1 = reverse_type_caster<int , int>(5);
}

