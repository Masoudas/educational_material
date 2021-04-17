/**
* Looking at something like conditional_t<(std::is_polymorphic<T>::value),X,Y> z for the first time, it is not uncommon for 
* people to think, "Why don't we just write a normal if?" Consider having to choose between two alternatives, Square and 
* Cube below. We might try the familiar if-statement to choose between types, as illustraded below in the 
* choose_between_types function.
* 
* A declaration cannot be the only statement of a branch of an if-statement, so this will not work even though 
* My_cond<T>() is computed at compile time. Thus, an ordinary if-statement is useful for ordinary expressions, but not 
* for type selection.
* 
* me: Recall that an alias is local to the scope. That is, we can't see it outside the scope we defined it, unless we
* have access to the name of that scope. Now consider the example below. Note that each branch of if creates a new scope,
* both of which are nested inside the function scope. Now, if I define an alias inside each of these, they're only seen 
* there (like an alias inside an struct is not seen directly in the namespace scope that structure is defined in, or
* we'd be screwed with the conflict of aliases!) Hence, I can't access the alises outside the scope of if loops, chiefly
* because I don't have access to the name of the if scopes. On the other hand, once outside the if loops, the function
* scope has its own alias, and it's not changed by the if scope aliases (like the aliases of a namespace are not affected
* by the aliases inside a class.) Hence, I'm free to use them.
* 
* The big guy continues: Using "conventional control structures," one would be tempted to write:

((My_cond<T>())?Square:Cube){}(99);

* But then again, this is not valid, because ? must yield values, and not types. Moreover, the following does not work:

(My_cond<T>()?Square{}:Cube{})(99);

* because as we may recall, we should return a compatible type from ternary if (Square and Cube don't have a common 
* parent.) Finally, this works (me: but is calculated at run-time):

My_cond<T>()?Square{}(99):Cube{}(99);

*/

struct Square {
	constexpr int operator()(int i) { return i*i; }
};

struct Cube {
	constexpr int operator()(int i) { return i*i*i; }
};

template<typename T>
constexpr bool My_cond() {
	return false;
}

template<typename T>
void choose_between_types() {
	if (My_cond<T>())
		using Type = Square; // error : declaration as if-statement branch
	else
		using Type = Cube; // error : declaration as if-statement branch

	//Type x; // error : Type is not in scope
}

// Alias defined in the function scope is unaffected by inside scopes.
template<typename T>
void choose_between_types_alternative() {
	using Type = Square;

	if constexpr (My_cond<T>()) {
		int i;
		using Type = Square; // error : declaration as if-statement branch
	}
	else {
		int i;
		using Type = Cube; // error : declaration as if-statement branch
	}
	
	Type x; // error : Type is not in scope
}
