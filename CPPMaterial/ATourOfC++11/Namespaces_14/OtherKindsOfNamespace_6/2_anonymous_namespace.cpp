/**
* We don't assign a name to the namespace, so that it won't be accessible by anyone else. Kind of 
* a private namespace. Anonymous namespaces have an implied using declarative that follows them.
* 
* In particular, imagine the name designated by the compiler was $$$, then there's a 'using $$$'
* right after it.
*/

namespace {
	int a;
	void f() { /* ... */ }
	void g() { /* ... */ }
}
// It's like the name of the namespace is $$$ and then there's a using $$$ right here.

void using_anonymous_ns() {
	f();	// This now belongs to a namespace.
}