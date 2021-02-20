/**
 * Constant expressions can use outside variables, as long as there's no side effect (and I'm assuming
 * that value is not set at runtime, i.e, it's constant).
 * 
 */
constexpr int ftbl[] { 1, 2, 3, 5, 8, 13 };
constexpr int fib(int n)
{
    return (n < sizeof(ftbl) / sizeof(*ftbl)) ? ftbl[n] : fib(n);
}

/**
 * A constant expression function is allowed to take references. Of course, it cannot write through such references, 
 * but const reference parameters are as useful as ever. For example, in the standard library we have:
 * 
 * template<> class complex<float> {
    public:
    // ...
    explicit constexpr complex(const complex<double>&);
    // ...
    };

    Hence we can write:
    constexpr complex<float> w{2.0};   

    I don't understand. Is there an implicit conversion from 2.0 to a reference to constant complex? And then that thing is
    converted to a complex as constant expressions??!! I really don't understand how this works.

    Bjarne says "The temporary variable that is logically constructed to hold the const reference argument simply
        becomes a value internal to the compiler." 
*/

/**
 * A constexpr function is allowed to return a reference or a pointer, but this should be avoided, as the
 * following example shows. This is because we don't know whether the underlying value can be computed at compile time.
 */

constexpr const int* addr(const int& r) { return &r; } // OK

static const int x = 5;
constexpr const int* p1 = addr(x); // OK
constexpr int xx = *p1; //OK
static int y;
constexpr const int* p2 = addr(y); // OK
//constexpr int yy = *y; //error : attempt to read a var iable
//constexpr const int* tp = addr(5); // error : address of temporary
