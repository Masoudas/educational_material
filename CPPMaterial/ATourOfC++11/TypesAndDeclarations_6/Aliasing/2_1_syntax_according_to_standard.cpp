/**
* Alias syntax is either of the following, where the first one is called type alias and the second is alias template:
* 
* using identifier attr(optional) = type-id ;	
* 
* template < template-parameter-list >
* using identifier attr(optional) = type-id; (Me:: more accurately, 'using identifier = type_id<template-parameter-list'>
* 
* -- attributes: optional sequence of any number of attributes (For example, [[always_inline]], etc ...)
* -- the name that is introduced by this declaration, which becomes either a type name (1) or a template name (2)
* -- template parameter list, as in template declaration
* -- abstract declarator or any other valid type-id (which may introduce a new type, as noted in type-id). The type-id cannot 
*	 directly or indirectly refer to identifier. Note that the point of declaration of the identifier is at the semicolon 
*	 following type-id. (Me: when we say type-id, for example a function name is not a type-id, but a class, ptr to class,
*	 etc. are all type-ids).
* 
* The standard says: A type alias declaration introduces a name which can be used as a synonym for the type denoted by 
* type-id. It does not introduce a new type and it cannot change the meaning of an existing type name. There is no difference 
* between a type alias declaration and typedef declaration. This declaration may appear in block scope, class scope, or 
* namespace scope.
* 
* An alias template is a template which, when specialized, is equivalent to the result of substituting the template arguments 
* of the alias template for the template parameters in the type-id. (Me: The point of the templated alias is what I was always
* wondering about. Normally, I used to alias a specialization of a templated type. But with templated aliasing, I'm able to
* alias only the type id of a templated type).
* 
* Alias templates are never deduced by template argument deduction when deducing a template template parameter.
* It is not possible to partially or explicitly specialize an alias template.
* 
* Like any template declaration, an alias template can only be declared at class scope or namespace scope.
*/

template<typename T, typename U, typename V>
struct templated_with_long_name {
};

struct s {
	using specialization = templated_with_long_name<int, unsigned char, unsigned int>;

	template <typename T, typename U, typename V>
	using t_alias = templated_with_long_name<T, U, V>;

	void f() {
		t_alias<int, int, int> t{};
	}
	
};

//int main() {
//	s S{};
//	S.f();
//}