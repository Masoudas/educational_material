/** This is all me:
* We need to stress more the point that the point of view of user of a class and programmer differ in templated
* specialization. Consider the following

template<typename T>
struct ptr_specializtion{}

template<typename T>
struct ptr_specialization<T*>{
	using type = T;
}

* Now, consider the two point of views:
*	-	Programmer: He sees T inside the class the type, and not pointer to type. Hence, T is an int to him,
*		if he says ptr_specialization<T>, it would be with int, and not int*.
*	-	User: User instantiates with int*. Hence, ptr_specialization<int*> is still instantiated with int* and
*		not int. That is, he cannot assign an int instantiation to this, saying for example that
*		ptr_specialization<int> <:= ptr_specialization<int*>	
*	-	Both of them see type as int however in this example. The alias connects the two words in that sense.
*/
