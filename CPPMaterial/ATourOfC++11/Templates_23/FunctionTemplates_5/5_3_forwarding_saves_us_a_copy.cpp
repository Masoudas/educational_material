/**
* Consider the following make_unique function. As we can see, we forward the templated type inside the constructor
* of Xref. This scheme has the great advantage, particularly for the case where we pass a variable name. In this
* case, a copy of the string is not made, and the created object would not be the owner of the string (neither when
* passing the argument, nor when creating the object). 
* 
* This is quite good, although the problem is that because we pass the variable and not its copy, if it's an auto,
* it will be destroyed while the unique ptr is still working. Although if this werent' case, we'd be fine, and Xref
* would always point to existing object.
*/
#include <memory>
#include <string>

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

template<typename TT, typename A>
std::unique_ptr<TT> make_unique(int i, A&& a) // simple variant of make_shared (§34.3.2)
{
	return std::unique_ptr<TT>{new TT{ i, std::forward<A>(a) }};
}

void making_unique_objects() {
	std::string x{};
	auto p1 = make_unique<Xref<std::string>>(7, "Here"); // Passes an rvalue ref to new.

	auto p2 = make_unique<Xref<std::string>>(9, x);	// Passes an lvalue ref.
}