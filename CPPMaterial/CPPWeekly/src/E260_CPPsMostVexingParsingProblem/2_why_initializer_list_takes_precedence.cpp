/**
* The standard says " When objects of non-aggregate class type T are list-initialized (8.5.4), overload 
* resolution selects the constructor in two phases:
*	-	Initially, the candidate functions are the initializer-list constructors (8.5.4) of the class T and 
*		the argument list consists of the initializer list as a single argument.
*	-	If no viable initializer-list constructor is found, overload resolution is performed again, where the 
*		candidate functions are all the constructors of the class T and the argument list consists of the 
*		elements of the initializer list.
*	-	If the initializer list has no elements and T has a default constructor, the first phase is omitted. 
*		In copy-list-initialization, if an explicit constructor is chosen, the initialization is ill-formed."
* 
* Essentially, this part of the standard argues that initializer lists always take precedence (regardless of
* whether we like it or not.) The most interesting case is the last one, which actually does make sense. If
* for type X, we write X{}, we expect it to be a default initialization, not an initializer list. Just take
* a look at this line of code:
* 
* X x{};	
* 
* When did we ever say that this line means use an empty initializer list?!! Note, however, that if there were
* no default constructors, this would be construed as empty initializer list!
*/ 

/**
* Now, why give precedence to initializer list over argument constructors? This would help us in many typical
* cases. First, note that initializer list was introduced so that we can write:
* 
* vector<int> v{1,2,3}
* 
* So this is one crucial reason why it takes precedence. Moreover, consider f(vector<int>). Now, f({1,5})
* gives precedence to {1,2} rather than {1,1,1,1,1}, where probably the former was the intention.
* 
* There's a large discussion on the reason why we have this, but I think I'm convinced for now. Also, take
* a look at the following examples. Recall that vector(int) is an explicit constructor that allocates an int
* number of memory locations.
*/
#include <vector>
// ...
struct X { X(int); /* ... */ };
void f(X) {};
void f(const std::vector<double>&) {};

// ...
void overloading_with_init_list(){
	f(1);     // call f(X); vector’s constructor is explicit
	//f({ 1 });   // potentially ambiguous: X or vector?
	f({ 1,2 }); // potentially ambiguous: 1 or 2 elements of vector (Looks fine to me though! init-list is
				// being called here)
}
