/**
* When it comes to implementation, dependency among modules may result in long and distracting names
* when using other namespaces. My boy Bjarne gives these rules for deciding on explicit qualification,
* using declarations, and using directives:
* [1]	If some qualification is really common for several names, use a using-directive for that namespace.
* [2]	If some qualification is common for a particular name from a namespace, 
	use a using-declaration for that name.
* [3]	If a qualification for a name is uncommon, use explicit qualification to make it clear from
	where the name comes.
* [4]	Don’t use explicit qualification for names in the same namespace as the user (i.e, in the 
*	namespace that you're typing your code, don't use scopes to refer to the members of that scope.
*	But someone needs to say why not? Given the rediculous argument look-up rules)/
*/