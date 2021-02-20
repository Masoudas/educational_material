/**
* Like a member, a base class can be declared private, protected, or public. The different access specifiers serve 
* different design needs:
* 
* -	public derivation makes the derived class a subtype of its base. For example, X is a kind of B. This is the 
*	most common form of derivation.
* - private bases are most useful when defining a class by restricting the interface to a base so that stronger 
*	guarantees can be provided. For example, B is an implementation detail of Z. The Vector of pointers template 
*	that adds type checking to its Vector<void*> base is a good example
* - protected bases are useful in class hierarchies in which further derivation is the norm. Like private 
*	derivation, protected derivation is used to represent implementation details. 
* 
* (Me: Simply put, when declaring inheritance public, private or protected, the most liberal of access controls
* become the inheritance form. So with private, every base class method is a private part of the derived class, and
* with protected every member is protected. When it comes to accessing by reference, only in the case of public
* inheritance can we implicitly convert derived to base class pointer or reference. In the other cases, such 
* conversion can only take place in the class.)
* 
* The access specifier for a base class can be left out. In that case, the base defaults to a private base for a 
* class and a public base for a struct. 
* 
* The access specifier for a base class controls the access to members of the base class and the conversion of 
* pointers and references from the derived class type to the base class type. Consider a class D derived from a 
* base class B:
* - If B is a private base, its public and protected members can be used only by member functions and friends of D. 
*	Only friends and members of D can convert a D* to a B*.
* - If B is a protected base, its public and protected members can be used only by member functions and friends of 
*	D and by member functions and friends of classes derived from D. Only friends and members of D and friends and 
*	members of classes derived from D can convert a D* to a B*.
* - If B is a public base, its public members can be used by any function. In addition, its protected members can 
*	be used by members and friends of D and members and friends of classes derived from D. Any function can convert 
*	a D* to a B*.
*/
