/**
* A namespace is open, meaning you can add to it from several different places and files.
* 
* We of course tend to define the namespace in the header file.
* 
* Big Bjarne uses several small namespaces in his projects, and so should we!
* 
* 
*/

namespace ns_h {
	void f() {}
}

namespace ns_h {
	void g() {
		f();
	}
}