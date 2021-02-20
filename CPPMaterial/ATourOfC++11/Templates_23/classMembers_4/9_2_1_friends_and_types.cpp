/**
* Forgetting about operators, templated types can have friends (they're human too :D). They can also have
* templated friends. But as is the case of non-templated cases, friendship is not inherited, nor is it 
* transitive (if a is friends b, and b is friends with c, then a is not friends with c), and naturally
* not reflective.
*/

class C;
using C2 = C;

template<typename T>
class My_class {
	friend C; // OK: C is a class
	friend C2; // OK: C2 is an alias for a class
	// friend C3; // error : no class C3 in scope
	friend class C4; // OK: introduces a new class C4
};

template<typename T>
class my_other_class {
	friend T; // my argument is my friend!
	friend My_class<T>; // My_class with the corresponding argument is my friend
	// friend class T; // error : redundant ‘‘class’’
};

