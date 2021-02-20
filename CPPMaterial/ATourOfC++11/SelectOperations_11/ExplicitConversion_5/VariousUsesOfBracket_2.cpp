/**
 * The constructor notation T{} is used to express the default value of T. For the value
 * types, it will be the default value. Hence int{} is zero. For enumeration types, the default
 * value is ZERO!!!!See _8_4_1.

 * More generally, T{e} would indicate construction of type T from type e.
 * auto d1 = double{2}; // d1==2.0. This one constructs a double (from an integer literal? Yes. We can initialize a double 
from an integer literal that can be exactly represented.)
 * double d2 {double{2}/4}; // d1==0.5 
 */

/* Part of the use of the {} notation is that it performs well-behaved conversions. Apparently, even int to double
is not considered well behaved here, which is reasonable, because we don't know if double actually represents a greater
range than int!!! Beware of this. We should for such circumstances use the narrow cast, as discussed in _1 of here. */

void f(int);
void f(double);
void g(int i, double d)
{
f(i); //call f(int)
f(double{i}); //error : {} doesn’t do int to floating conversion
f(d); //call f(double)
f(int{d}); //error : {} doesn’t truncate
f(static_cast<int>(d)); // call f(int) with a truncated value
f(round(d)); //call f(double) with a rounded value
f(static_cast<int>(lround(d))); // call f(int) with a rounded value
// if the d is overflows the int, this still truncates
}

// It does not allow bad-behaved pointer assignments as well.
void g2(char* p)
{
int x = int{p}; // error : no char* to int conversion
using Pint = int*;
int* p2 = Pint{p}; // error : no char* to int* conversion
// ...
}

For T{v}, ‘‘reasonably well behaved’’ is defined as having a ‘‘non-narrowing’’ (§10.5) conversion
from v to T or having an appropriate constructor for T.
*/


/* 
 * If a class has constructor that requires no parameters (either because it takes no 
 * parameters or because they're optional), the bracket notion uses that constructor to 
 * construct the class.
 * 
 * Explicitly constructed unnamed objects are temporary objects, 
 * and (unless bound to a reference) their  lifetime  is  limited  to  the  full  expression  in  which  they are  used  
 * In  this,  they differ from unnamed objects created using new (which need to be deleted, but can't, because there's
 * no reference to them.)
 * Again, as a reminded, for a user-defined type T, T{} is defined by the default constructor
 */
class Date{
public:
    Date(){}
    Date(int n){}


};

enum A{a=1};

void f(Date& date){}

void g(){
    f(Date{});   // Default constructor of A, one with no parameter.
    f({});   // Default constructor of A, one with no parameter.

    Date d = Date{};    // One again, default date. What if there's no default value?

    Date d{};   // This I'm hoping mean default constructor!!!

    int a{};     // Default integer value.
    int b = int{};  // Default integer value.

    A a{};  // Default constructor of A, one with no parameter
    A a = A{};  // Again, the  default value.

}