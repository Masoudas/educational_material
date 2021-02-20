#define f(x) x > 5 ? true : false;

#include <iostream>
using namespace std;

/**
 * There's another form of function definition where the function name comes between paranthesis:
 */
bool(function)(){
    return false;
}

/**
 * The reason why we do this is that we don't  function definition to be confused with macros.
 * So the presence of paranthesis means function, absence means macro.
 */


bool(f)(){
    return f(6);
}

//int main(){
//    cout << (f)();    
//}