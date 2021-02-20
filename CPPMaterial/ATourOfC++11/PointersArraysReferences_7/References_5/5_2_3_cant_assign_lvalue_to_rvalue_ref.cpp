/** This is me: 
* As is the case, we can't assign lvalue references to rvalue references. Why? An obvious reason is that they are 
* not the same type, and a conversion between them is undefined. Technically, an lvalue refers to an address 
* in memory, whereas rvalue referes to a modifiable address in memory. Had we done this implicity, we would
* have emptied up the memory. (There are however cases where I see that this is possible, like in the example
* below).
* 
* Can we assign an rvalue reference to an lvalue? Yes. Because an rvalue reference is after all an lvalue
* reference. (Me: This is one of the reasons why we need forwarding semantics by the way. When we convert to
* an rvalue to an lvalue, we lost the rvalueness of the reference. So if we want it back, we must use the
* forwarding notion)
* 
* T&& ref1;
* T& ref = ref1;	// Wrong.
* 
* Why is this important? Imagine a function only has T&&, and no T& for example. Then, we can't directly pass
* the lvalue reference (and we need to use move). Looking the other way, if we pass T or T& to overloaded functions,
* then those that accept lvalue reference are used. If such a version does not exist, then we get a compile time
* error.
* 
* 
*/

struct MyStruct{};

void assigning_lvalue_ref_to_rvalue_ref() {
	MyStruct m{};

	MyStruct&& r = static_cast<MyStruct&&>(m);
	MyStruct& l = m;

	l = r;
	r = l;

}

void built_in_with_rvalue(int&& ref){
	int x = 10;

	// built_in_with_rvalue(x); Error! Assigning object to temporary reference without explicitly casting.
}

void user_defined_type_with_rvalue(MyStruct&& ref) {
	MyStruct s1{};

	// user_defined_type_with_rvalue(s1); Error! Can't assign user defined lvalue to rvalue.
}

template <typename T>
void passing_rvalue(T&& ref) {
	T t{};
	passing_rvalue(t);	// Holy Moly! This can be done with templates.
}
