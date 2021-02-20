/**
* One thing that we should not forget is that a using declarative brings the element from the other namespace
* into current namespace, making it accessible to the users of the current scope. This is a luxury, as well
* as a curse.
* 
* A locally declared name (declared either by an ordinary declaration or by a using-declaration) hides
* nonlocal declarations of the same name, and any illegal overloading of the name is detected at the
* point of declaration (So this is not just for global name space, or for base and derived class). This
* does not depend on which one is declared first.
* 
* Note the ambiguity error for k++ in f1(). Global names are not given preference over names
* from namespaces made accessible in the global scope. This provides significant protection against
* accidental name clashes, and – importantly – ensures that there are no advantages to be gained from
* polluting the global namespace.
* 
* When libraries declaring many names are made accessible through using-directives, it is a significant 
* advantage that clashes of unused names are not considered errors
*/

namespace X {
	int i, j, k;
}

int k;
void using_X_namespace_in_function_namespace()
{
	int i = 0;
	using namespace X; // make names from X accessible
	i++; // local i
	j++; // X::j
	//k++; // error : X’s k or the global k?
	::k++; // the global k
	X::k++; // X’s k
}

void another_using_X_namespace_in_function_namespace() {
	int i = 0;
	//using X::i; // error : i declared twice in f2()
	using X::j;
	using X::k; // hides global k. Akh!
	i++;
	j++; // X::j
	k++; // X::k
}