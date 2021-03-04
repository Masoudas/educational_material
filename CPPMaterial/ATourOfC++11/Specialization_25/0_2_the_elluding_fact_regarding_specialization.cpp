/**
* Something that elludes me regarding C++ templates is this: One cannot define a template to be a reference
* or a pointer. One can, however, pass both as template arguments.
* 
* What do I mean by this? It's very famous that in C++, we can't restrict a template to a particular type (or
* interface for that matter) and say, template<Interface T>, or template<typename Interface>, implying that 
* the type shall implement the interface. Similarly, we can't say template<typename T*> or template<typename T&>
* saying we want to pass a pointer or a reference. As we shall see later in this section, we can only define
* the templated type to be pointer in case of:
*	- Pointer to function
*	- Pointer to member
*	- Pointer to primitive type
* 
* That being said, it's perfectly legal, and natural in fact, to pass pointers as types. It's legal to pass 
* to pass references (r or l value references) as types, but this is not common. Hence, in template type
* deduction and forwarding for example, we deduce the template type as int for example, so that the forward
* function has int as template argument, but int& for arguments.
* 
* std::forward<int>(x);	// template is int. Returns int&&.
* std::forward<int&>(x); // template is int&. Returns int&.
* 
* We should from now on be aware of this distinction when dealing with templates.
*/