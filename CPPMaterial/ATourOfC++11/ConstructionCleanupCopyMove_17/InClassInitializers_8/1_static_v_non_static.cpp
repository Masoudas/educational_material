/*
* As we already know, any non-static member of a class can be initialized when declared in the class.
* 
* static members however need to be initialized inside the scope of the class (and not in the class).
* (Exceptions being a const of an integral or enumeration type, or a constexpr of a literal type, 
*  a constant-expression).
* 
* Don't forget that we need to write the type before initializing the static!
*/
namespace inclass_initializer_static_v_non_static {
	struct inclass_initializer {
		static int i;	// This musn't be initialized here.
		int j{ 7 };
	};

	int inclass_initializer::i = 12;
}