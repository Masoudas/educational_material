/**
 * Don't forget that tilde is the bitwise complement, whereas ! is the logical not.
 * (Exactly like any other language, ! is a logical not).
 * 
 * Note that ! has no effect on non-boolean, unless it's implicitly converted to bool (like
 * in an if statement).
 */
#include <iostream>

using namespace std;
int main(){
    int x{};
    cout << ~x << endl; // Complement, minus -1.
    cout << !x << endl; // Nothing here!

    
    if (!x){    // This would be true.
        cout << "We're here baby";
    }
}