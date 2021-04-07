/**
* The standard formulates what we unofficially discussed before as follows:
* 
* template < parameter-list > class-key class-head-name < argument-list > declaration	(1)		(me: what we discussed)
* template < parameter-list > decl-specifier-seq declarator < argument-list > initializer(optional) (2) since C++14
* 
* where class-head-name identifies the name of a previously declared class template and declarator identifies the name of 
* a previously declared variable template (since C++14). This declaration must be in the same namespace or, for member 
* templates, class scope as the primary template definition which it specializes. 
* 
* For example:

template<class T1, class T2, int I>
class A {};            // primary template
 
template<class T, int I>
class A<T, T*, I> {};  // #1: partial specialization where T2 is a pointer to T1
 
template<class T, class T2, int I>
class A<T*, T2, I> {}; // #2: partial specialization where T1 is a pointer

* Examples of partial specializations in the standard library include std::unique_ptr, which has a partial specialization 
* for array types.
* 
* The following restrictions apply to the argument-list of a partial template specialization:
*	(1)		The argument list cannot be identical to the non-specialized argument list (it must specialize something)
*	(2)		Default arguments cannot appear in the argument list 
*	(3)		If any argument is a pack expansion, it must be the last argument in the list
*	(4)		Non-type argument expressions can use template parameters as long as the parameter appears at least once 
*			outside a non-deduced context (note that only clang supports this feature currently)

template <int I, int J> struct A {};
template <int I> struct A<I+5, I*2> {}; // error, I is not deducible
 
template <int I, int J, int K> struct B {};
template <int I> struct B<I, I*2, 2> {};  // OK: first parameter is deducible

*	(5)		Non-type template argument cannot specialize a template parameter whose type depends on a parameter of the 
*           specialization:

template <class T, T t> struct C {};    // primary template
template <class T> struct C<T, 1>;      // error: type of the argument 1 is T, which depends on the parameter T
 
template< int X, int (*array_ptr)[X] > class B {}; // primary template
int array[5];
template< int X > class B<X,&array> { }; // error: type of the argument &array
                             // is int(*)[X], which depends on the parameter X

* Name lookup: I didn't continue from here on.
*/