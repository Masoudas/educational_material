/**
* The notion of a namespace is provided to directly represent the notion of a set of facilities that
* directly belong together, for example, the code of a library
* 
* The members of a namespace are in the same scope and can refer to each other without special notation, 
* whereas access from outside the namespace requires explicit notation.
* 
* The exception to this is the globall namespace (Me: Because there's no using directive saying 
* "using 'global namespace'" for example, we can assume that it's always being used. Though perhaps,
* using the scope operator before it provides for some clarity.)
* 
* Two namespaces can have members of the same name. The local name look-up of one scope
* is not affected by that of other scopes, including global scope. (Me: In case of repetitive names with
* the global scope, the local scope name is given priority, i.e, local names hide the global names).
* 
* Note also that as a consequence of the above rule, the local namespace HIDES the global scope members
* if redefined.
* 
* Finally, note that classes are themselves namespaces.
*/

int ii = 10;
void global_method(){}
class my_class {};

int f();

namespace MY_NS {
	void scope_method() {
		ii++;
		global_method();
	}

	class my_class{};

	int f = 0;	// Hides the global name!
	// f();	 Error! f is an int this scope.
}