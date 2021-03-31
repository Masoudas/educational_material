/**
 * By qualified initializer list, we mean a list where type is written before the list (T{}).
 * 
 * The basic idea of using initializer list, is to initialize an object using a list expression,
 * either with or without new. The rules constructing an object using a qualified list are
 * those of direct initialization
 * 
 * int t = int{7};
 * Struct s = new Struct{4,5};    // Initialize Struct with the given values.
 * 
 * As we already one, one other way of looking at the qualifed initilizer list is a convertor from
 * one type to another.
 */ 

/**
 * By an unqualified initializer list, we mean an initializer that does not have a type attached to it.
 * We can use this format when there's no ambiguity.
 * 
 * We can use it as:
 * 1- Function argument.
 * 2- Return value
 * 3- Right hand side of an assignemnt operator like +=, -=, *=
 * 4- A subscript!
 */
struct Matrix{};
int f(double d, Matrix& m)
{
    int v {7}; // initializer (direct initialization)
    int v2 = {7}; // initializer (copy initialization)
   // int v3 = m[{2,3}]; // assume m takes value pairs as subscripts. Cool!
    v ={8}; //right-hand operand of assignment
    //v += {88}; //right-hand operand of assignment
    // {v} = 9; // error : not left-hand operand of assignment
    //v = 7+{10}; // error : not an operand of a non-assignment operator
   // f({10.0}); // function argument
    return {11}; // return value
}

/**
 * Most importantly, the initializer_list is used to handle variable argument functions.
 */
#include <initializer_list>
void using_init_list(std::initializer_list<int> v){
    if (v.size() == 0){
        return;
    }
    using_init_list({1, 2, 3});
    using_init_list({1, 2, 3, 4});
}

/**
 * As we already said, when we put a bracket in front of an auto, a list initializer is used. And as we said,
 * all variables should have the same type:
 * 
 * auto a = {}; // Error. No element type.
 * auto b = {1};    // List of int.
 * auto c = {1, 2.0}; // Error. Ambiguous type!
 */

/**
 * Unfortunately with templates, we cannot use unqualified lists, which is a restriction by the language.
 */
template<typename T>
void f(T){
    //f({1});     // Not acceptable
}

/**
 * Even if the template is used as the type of another aggregate, unqualified bracket is not recognized.
 */
#include <vector>
template<typename T>
void g(const std::vector<T> t){
    //g({1, 2}); // Error, type of template cannot be deduced. 

    int a[2] = {1,2};
    // g(a); Even such a qualification does not work!
}

