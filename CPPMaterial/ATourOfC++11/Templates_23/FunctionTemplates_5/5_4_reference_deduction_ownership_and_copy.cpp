/** Back to what the big guy talks about.
* It can be useful to have different actions taken for lvalues and rvalues. Consider a class for holding an 
* {integer,pointer} pair like below.
* 
* Now consider the following three instantiations:
* string x {"There and back again"};
* Xref<string> r1 {7,"Here"}; // r1 owns a copy of str ing{"Here"}
* Xref<string> r2 {9,x}; // r2 just refers to x
* Xref<string> r3 {3,new string{"There"}}; // r3 owns the string{"There"}
* 
* Note that we're dealing with a class, and template type is not deduced here. Hence we get a string&&, string& and
* string* constructor. Now, the first instantiation consists of an rvalue, so the corresponding ctor is called. 
* The second one is an lvalue, and the third one is an string. So for each case, a corresponding one is called.
* 
* The big guys says, and this is fundamental: "Lvalues and rvalues are distinguished by template argument deduction: 
* an lvalue of type X is deduced as an X& and an rvalue as X.", (me: and we already said that a variable name is 
* considered an lvalue reference too.)
* 
*/

template<typename T>
class Xref {
public:
	Xref(int i, T* p) // store a pointer: Xref is the owner
		:index{ i }, elem{ p }, owned{ true } { }
	Xref(int i, T& r) // store a pointer to r, owned by someone else
		:index{ i }, elem{ &r }, owned{ false } { }
	Xref(int i, T&& r) // move r into Xref, Xref is the owner
		:index{ i }, elem{ new T{move(r)} }, owned{ true } { }
	~Xref() { if (owned) delete elem; }

private:
	int index; T* elem; bool owned;
};

