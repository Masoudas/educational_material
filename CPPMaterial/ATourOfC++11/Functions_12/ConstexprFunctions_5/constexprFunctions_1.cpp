/**
 * By declaring a function a constant expression, we say that we want to use it in constant expressions,
 * if given constant arguments. This can't be done with a function that is not declared constexpr
 */

constexpr int fac(int n)
{
    return (n>1) ? n * fac(n-1) : 1;
}
constexpr int f9 = fac(9); // must be evaluated at compile time

int fac_1(int n) {
    return 0;
}
// constexpr int f0 = fac_1(0);    // This is impossible

/** When used in an object definition, it means evaluate the initializer at compile time. For example: */
void examples_of_constexpr_evaluation(int n)
{
    int f5 = fac(5); // may be evaluated at compile time
    int fn = fac(n); // evaluated at run time (n is a var iable)
    constexpr int f6 = fac(6); // must be evaluated at compile time
    // constexpr int fnn = fac(n); // error : can’t guarantee compile-time evaluation (n is variable)
    char a[fac(4)]; // OK: array bounds must be constants and fac() is constexpr
    // char a2[fac(n)]; // error : array bounds must be constants and n is a var iable
    // ...
}

/**
 * constexpr can't have for loops or if expressions (Ternary ifs are ok apparently). Recursion is also allowed.
 * It must not have side effects as well (like changing a global variable).
 * We must not use with long methods, because compile time would be long.
 */
int glob;
constexpr void bad1(int a) // error : constexpr function cannot be void
{
     glob = a; // error : side effect in constexpr function
}

/**
 * We may use constexpr with constructors! That way, the object is created in ROM!
 * A constant expression constructor has no body, and is only allowed to initialize data.
 * 
 * Like a constexpr function, however, if the values that are used are not constant, the 
 * initilization would be dynamic
 */
struct complex
{
    //a constant expression constructor
    constexpr complex(double r, double i) : re(r), im(i) { }//empty body
    
    //constant expression functions
    constexpr double real() { return re;}
    constexpr double imag() { return im;}

private:
    double re;
    double im;
};

constexpr complex COMP{0.0, 1.0}; // creates a literal complex

void assigning_constexpr_constructor(){
    double val = 0.2;
    complex(val, val);  // This initialization is not constant expression

    double x = 1.0;
    
    // constexpr complex cx1(x, 0); // error: x isn’t a constant expression
    
    const complex cx2(x, 1); //OK, dynamic initialization
    // constexpr double xx = COMP.real(); // OK. But for some reason does not work with MSVC
    // constexpr double imaglval = COMP.imag(); //OK, static init. But for some reason does not work with MSVC
    complex cx3(2, 4.6); //dynamic initialization
}

/**
 * Note that a branch that is not evaluated at compile time can have run-time association, like throwing
 * an exception. For example:
 * 
 * Yeah, I don't know what that last line is, but Bjarne says: "You might imagine low and high to be configuration parameters
 * that are known at compile time, but not at design time, and that f(x,y,z) computes some implementation-dependent value."
 */
//constexpr int check(int i)
//{
//    return (low<=i && i<high) ? i : throw out_of_range();

//}


constexpr int low = 0;
constexpr int high = 99;
// ...
// constexpr int val = check(f(x,y,z));



