/**
* Another motivation is that sometimes I'm tempted to overload some functions of std. This is fine, so long as
* those functions have something in their argumets that's not related to std. For example, if I try to overload
* the output stream operator for vector<int>, then there's an overload in std, and I get an error (there exists
* an overload for the full type vector<int>.) However, I can do it for vector<S>.
*/
#include <vector>
#include <iostream>

struct S {
	int x;
};

std::ostream& operator<<(std::ostream& o, const std::vector<S>& v) {
	o << v[0].x;
	return o;
}

/* Don't do it! It will cause ambiguity due to ADL.
std::ostream& operator<<(std::ostream& o, const std::vector<int>& v) {
	o << v;
	return o;
}*/


void using_operator_overload(std::vector<S> v, const std::vector<int>& t) {
	std::cout << v;
}