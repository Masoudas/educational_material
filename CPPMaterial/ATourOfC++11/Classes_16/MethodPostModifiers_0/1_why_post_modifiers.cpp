/*
* Post modifiers of methods are very important, as they allow access based on the reference type. A particular
* one that we see all the time is const, but there's cv + ref qualifiers combinations as well.
*/
#include <iostream>
using std::cout;
struct m {
	/*void f() const {
		cout << "Inisde const method\n";
	}*/

	void f()& {
		cout << "Inisde lvalue method\n";
	}

	void f() const& {
		cout << "Inisde const value ref method\n";
	}

	void f()&& {
		cout << "Inisde rvalue ref method\n";
	}

	void f() volatile & {
		cout << "Inisde volatile lvalue method\n";
	}
};

void accessing_different_postfix_methods() {
	m m1{};

	m& m2 = m1;
	cout << "\nAccessing lvalue method:\n";
	m2.f();

	const m& m3 = m2;
	cout << "\nAccessing const lvalue method:\n";
	m3.f();

	cout << "\nAccessing rvalue method:\n";
	m{}.f();
}