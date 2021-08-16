/**
* As a thought experiment, consider the following:

#include <iostream>
struct S {
	int x = 10;
	S() {}
	S(const S&) {}
	S(S&&){}
};

struct X {
	S s;
	X(S s1) : s{ s1 } {}
};

int main() {
	X x{ S{} };
}

* In this program, a good compiler would make one copy of s for s1 (whereas a bad one would make two!)
* and one move. Now, consider what happens if I change the constructor of S as follows:

X(S s1) : s{ s1 } { s1.x++;}

* This one still uses one copy and one move. However, if I do the following in main:

int main(){
	S s{};
	X x{s};
}
* Now, all of a sudden we use two copies. Hence, we should always be cautious. One solution here would be to
* use const S& in the constructor, or directly use lvalues.
*/