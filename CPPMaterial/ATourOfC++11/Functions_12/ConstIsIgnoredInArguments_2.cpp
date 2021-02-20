/**
 * When declaring a function, due to compatibility with C, const is ignnored in function defintion.
 * Hence, these two are the same, and we get all sorts of errors, telling us that the function has already
 * been declared.
 * 
 * THIS HOWEVER IS NOT THE CASE FOR CONSTANT REFERENCES, because they imply something fundamentally different
 * from references.
 */

#include <iostream>
using namespace std;

void const_is_ignored(const int x){
    std::cout << "Inside const function." << endl;
}

//void f(int x){
//    std::cout << "Inside non-const.";
//}

void const_is_not_ignored_with_references(int& ref) {
    std::cout << "Inside ref function." << endl;
}

void const_is_not_ignored_with_references(const int& ref) {
    std::cout << "Inside const ref function." << endl; 
}

void checking_const_ignore() {
    const int x = 1;
    const_is_ignored(1);
    const_is_ignored(x);

    int y = 10;
    const_is_not_ignored_with_references(x);
    const_is_not_ignored_with_references(y);

}

//int main() {
//    checking_const_ignore();
//}
