/**
 * For a type T, T[size] is an array of elements T with size. The elements are indexed
 * from zero to size-1.
 * 
 * Array size must be a constant expression (of course, because with arrays, we need to assign a
 * specific size in memory). For variable expressions, we need to use vectors.
 * 
 * (Me: for consistency with n dimensional arrays, it may be useful to think of T[size] like this:
 * T is a 1D array of pointers to integers. This way, we can see why int *p = a; 
 * This is because a is a pointer (at location zero). Hence, int *p = a + 1; 
 * Moreover, int (*p)[size] = &T, because T is an array of pointer to 5 ints. 
 
 * JUST DON'T FORGET THAT a[][][] is always an array of 1D pointers. That's the golden rule.)
 */ 
#include <vector>
using namespace std;
void use_vector_for_variable_length(int n){
   // int v1[n];//error : array size not a constant expression
    vector<int> v2(n);//OK: vector with n int elements
}

/** An array can be allocated statically, on the stack, and on the free store.  For example:*/
int a1[10];//10 ints in static storage
void allocate_static_or_dynamic(){
    int a2[20];  //20 ints on the stack. This array is initialized to zero, because
    int* p = new int[40]; //40 ints on the free store//...
}

/**
 * Bjarne says arrays should not be passed as function parameters, because that is the source of
 * many problems. This is because an array is converted to its pointer when being passed.
 * 
 * Arrays usually should not be used directly, but rather be capsualted.
 * 
 * Arrays allocated on the free store should be deleted, only once, and only
 * when they go out of scope. That’s most  easily  andmost  reliably  done  by  having  the  lifetime  
 * of  the  free-store  array  controlled  by  a  resource  handle
 * (e.g.,string(§19.3, §36.3), vector(§13.6, §34.2), orunique_ptr(§34.3.1)). 
 * automatic arrays should not be deleted. 
 */