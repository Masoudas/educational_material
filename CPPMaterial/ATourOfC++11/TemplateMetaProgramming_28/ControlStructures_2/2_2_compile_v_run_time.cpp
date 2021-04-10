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
* me: Note also that those condition would be scoped to local if. Hence, they can't be seen outside, meaning a using
* statement is valid only inside the scope. Hence, even if I define a using statement outside the if (justlike I do
* with a normal int for example and then change it inside the if) then that would not cut it, because the using statement
* inside is valid only for that scope and that's it. Note again that this has nothing do to with if constexpr, because 
* the aliasing IS ONLY VALID inside the scope, and not outside it. Hence, the outside using always overrides whatever is
* on the inside.
* 
* The big guy continues: Using "conventional control structures," one would be tempted to write:

((My_cond<T>())?Square:Cube){}(99);

* But then again, this is not valid, because ? must yield values, and not types. Moreover, the following does not work:

(My_cond<T>()?Square{}:Cube{})(99);

* because as we may recall, we should return a compatible type from ternary if (Square and Cube don't have a common 
* parent.) Finally, this works:

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
