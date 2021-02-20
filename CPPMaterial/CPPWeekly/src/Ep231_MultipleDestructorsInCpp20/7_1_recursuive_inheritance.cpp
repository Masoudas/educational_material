/**
* As we may recall in Java, we had recursive inheritance. Hence, for a T, we could say Comparable<T> means
* the type is comparable, and we defined it as class W<T implements Comparable<T>>.
* 
* Does this situation occur in C++ too? The following example shows that this is indeed possible. Now, the
* question is, is Comparable a super type, or subtype of S1? Well, because we can't assign a reference of 
* Comparable to S1 is no.
* 
* You may read chapter 27.4 of Bjarne's book. This is called the the "Curiously Recurring Template Pattern" or 
* CRTP.
* 
* The most important point here is that we can access the members of the derived class through the base class.
* Hence, as it stands, we can call it's destructors, methods, or even destruct particular elements of the derived
* class from the base! Note that particularly with destructors, this is not possible with a simple inheritance.
* 
* Notice how for accessing the derived class element, we cast the base class pointer to the template type!
* 
* What I don't understand is how come in this example, s destructor is called twice?
*/ 
#include <iostream>

using namespace std;

struct S {
	int i = 1;
	~S() {
		cout << "destructing template x" << i << '\n';
	}
};

template<typename T>
struct Comparable {
	virtual int compare(T t1, T t2) = 0;

	~Comparable() {
		cout << "Calling the base destructor" << '\n';
		static_cast<T*>(this)->s.i = 2;
		static_cast<T*>(this)->s.~S();	
	}
};

struct S1 : Comparable<S1> {
	S s{};

	int compare(S1 t1, S1 t2) override {
		return 0;

	}

	~S1() {
		cout << "Calling the derived destructor" << '\n';
	}
};

void using_interface() {
	S1 s{};

	Comparable<S1>& s2 = s;

	// S1* s1_ptr = &s2; Impossible!
}

//int main() {
//	using_interface();
//}

