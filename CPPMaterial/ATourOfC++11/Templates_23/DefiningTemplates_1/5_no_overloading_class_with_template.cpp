/**
* We can't overload a class with and without template, (Me: even though we can do it with functions, as long
* as there's no ambiguity!. Essentially, I should consider template as part of function signature!)
* 
* 
*/
template<typename T>
struct MyStruct{};

// struct MyStruct{}; Impossible!

template<typename T>
void f_with(T t) {

}

void f_with(int t) {

}

void using_f_and_resolving_conflict() {
	
	f_with(2);	// Not ambiguous
	f_with<char>('c');	// Not ambiguous
	f_with<int>(2);	// Not ambiguous

}