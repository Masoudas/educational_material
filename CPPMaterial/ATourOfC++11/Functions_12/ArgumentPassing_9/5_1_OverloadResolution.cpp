/**
* An initializer list takes precedence over other possible forms of a method accepting bracket
* arguments.
* 
* (mw: Though it appears that this not working!)
*/
#include <initializer_list>
using namespace std;

template<class T>
void overloading_with_init_list(initializer_list<T> t) {};

struct S {
	int a;
	char* s;
	S(int a, char* s) {}
};

void overloading_with_init_list(S s) {};

template<class T, int N>
void overloading_with_init_list(T(&r)[N]) {};

void overloading_with_init_list(int a) {};

void using_overloading_with_init_list()
{
//	overloading_with_init_list({ 1,2,3,4 }); // T is int and the initializer_list has size() 4. 
	// Compiler says this is wrong!!! and it should be. Where is the const?
	// overloading_with_init_list({ 1,"MKS" }); // calls f(S)
	// Compiler returns an error for this one as well! Confuses with initializer list, and can't resolve type.
	overloading_with_init_list({ 1 }); // T is int and the initializer_list has size(). The reference version
	// is not called here!
}