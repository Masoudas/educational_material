/**
* The standard finally says that:
* 
* "If P is an rvalue reference to a cv-unqualified template parameter (so-called forwarding reference), and 
* the corresponding function call argument is an lvalue, the type lvalue reference to A is used in place of A 
* for deduction (Note: this is the basis for the action of std::forward Note: in class template argument 
* deduction, template parameter of a class template is never a forwarding reference (since C++17)):"

template<class T>
int f(T&&);       // P is an rvalue reference to cv-unqualified T (forwarding reference)
template<class T>
int g(const T&&); // P is an rvalue reference to cv-qualified T (not special)

int main()
{
    int i;          (me: i becomes an lvalue object)
    int n1 = f(i); // argument is lvalue: calls f<int&>(int&) (special case)
    int n2 = f(0); // argument is not lvalue: calls f<int>(int&&)

//  int n3 = g(i); // error: deduces to g<int>(const int&&), which
                   // cannot bind an rvalue reference to an lvalue

    const int x = 5;
    f(x);   // const is not removed, because we have reference in P. P=const int&, because the rule still applies
            // and we deduce l-value for T&&, but we have const too.
}

*/

template<typename T>
void f(T&&);

