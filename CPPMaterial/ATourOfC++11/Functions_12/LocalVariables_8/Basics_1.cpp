/**
 * holly mother of God, we can use the static keyword in functions.
 * The static variable is initialized only once.
 */
#include <iostream>
using namespace std;

void f(int a){
    while (a--) {
        static int n = 0; // initialized once
        int x = 0; // initialized ’a’ times in each call of f()
        cout << "n == " << n++ << ", x == " << x++ << '\n';
    }
}

/**
 * The effect of defining a static local variable recursively is undefined:
 */
int fn(int n)
{
    static int n1 = n; // OK
    static int n2 = fn(n-1)+1; // undefined
    return n;
}