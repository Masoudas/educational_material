/**
* Data members can be of the template or not. They're initialized like ordinary member types. static 
* members types belong to that particular type (hence a type with string and a type with int have to
* independent versions of static natuarally).
* 
* Non-static data members can be const, but unfortunately not constexpr.
*/

#include <iostream>
#include <string>

using namespace std;

template<typename T>
struct X {
	int m1 = 7;
	T m2;
	static T t;
	X(const T& x) :m2{ x } { }
};

int X<int>::t = 5;
string X<string>::t = "abc";

//int main() {
//	cout << X<int>::t << endl;
//	cout << X<string>::t << endl;	
//}