/**
 * Some bitwise operators are at the left of the variable. Hence, for overloading them we write
 * functions that don't require input. Again, note that we may return a reference or not from
 * the overloaded function, depending on whether we want to use the result in an expression.
 * 
 * Also, note that bitwise operators (or any operator for that matter), could be thought of as var.operator!()
 * and so on.
 * 
 * Note that bitwise and is not confused with reference operator, as the reference operator takes no argument.
 */
#include <iostream>
using namespace std;

class BitwiseOL{
public:
    bool b = true;

    BitwiseOL(bool b) : b(b){

    }

public:
    BitwiseOL& operator~(){
        b = !b;

        return *this;  
    }

    BitwiseOL& operator&(const BitwiseOL& other){
        b &= other.b;

        return *this;
    }

    // Overloading reference operator for comparison with and operator.
    BitwiseOL& operator&(){
        BitwiseOL* ptr = new BitwiseOL{false};
        return *ptr;
    }


    BitwiseOL& operator|(const BitwiseOL& other){
        b |= other.b;

        return *this;
    }

    BitwiseOL& operator^(const BitwiseOL& other){
        b ^= other.b;

        return *this;
    }


};

int main(){
    BitwiseOL o1{true};
    BitwiseOL o2{true};

    ~o1;
    cout << o1.b;

    o2 = o1 ^ o2;
    cout << o2.b;

    BitwiseOL o3 = &o2;

    cout << (bool)(o3.b);
}