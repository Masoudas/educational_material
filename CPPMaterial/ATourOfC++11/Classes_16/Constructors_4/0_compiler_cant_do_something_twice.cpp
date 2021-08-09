/**
* Here's something to remember as a general rule. The C++ compiler can't detect, or perform, two layers of logic. For example,
* with operators, we can't define a custom +++ operator, because the compiler can't decide whether we're saying ++(+) or
* +++.
* 
* Considering this, note the following rule: A compiler cannot implicity convert one type to another, then to another type.
* What does this mean? Imagine the following class, where S has an string view constructor and the constructor is implicit.
* So, if I try to construct this class implicity using a C-String, here's what has to happen:
* 1- The constructor has to convert C-String to string_view
* 2- Then compiler has to convert the string_view to class S implicitly.
* 
* This is what the compiler can't do, because it involves two layers of logic deduction. Hence, the following implicit
* construction is a compile time error.
* 
* How do we remedy this? One great suggestion is to use a templated constructor, to let the compiler detect the type of the
* class. What we do essentially with templated construction is that we take the first type deduction out of question, that
* is converting from C-String to string_view. Of course, the cost of this method is that now the class can be constructed with
* virtually any type, and there's a code bloat problem as well.
* 
* Of course, note that the most natural solution here would be to use C-String as a constructor argument for the class, which
* implies several overloads unfortunately. Note however this does not cause overload error with string view because overload
* resolution would prefer const char*.
* 
* There's an interesting argument regarding the usage of optional arguments alongside these, for which I refer you to the C++
* con talk "CppCon 2018: Nicolai Josuttis �The Nightmare of Initialization in C++".
*/

#include <string_view>
using namespace std;

struct S {
	S(string_view s) {
	}
};

struct S1 {
	string_view s;
	template<typename T>
	S1(T t) {
		s = t;
	}
};

struct S_natural {
	string_view s;

	S_natural(string_view v) : s{ v } {
	}

	S_natural(const char* p) : s{ p } {
	}
};

void doubly_implicit_construction() {
	// S s = "Hey hey"; Not possible!
	S s = { "Hey hey" };	// Ok!
}


void avoiding_doubly_implicit_construction() {
	S1 s1 = "Hey hey";

	S_natural s_n = "Hey hey";	// Uses const char* constructor.
}