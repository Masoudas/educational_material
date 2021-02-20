/**
 * As we know, for a type T, T* referes to the address in memory where T is kept.
 * 
 * It is possible to perform some arithmetic operation on pointers to arrays.
 * 
 * Pointer is supposed to mimic the addressing mechanism of the machine. Most machines can't
 * address or reach a bit, hence the smallest entity we can access is a char. Note however that 
 * a bool occupies as much space as a char. 
 * 
 * Consider the following:
 * int∗ pi; //pointer to int
 * char∗∗ ppc; //pointer to pointer to char
 * int∗ ap[15];    //array of 15 pointers to ints
 * int (∗fp)(char∗);  //pointer to function taking a char* argument; returns an int
 * int∗ f(char∗);     //function taking a char* argument; returns a pointer to int
 * 
 * In general, it is not safe to use a pointer that has been converted (‘‘cast’’)
 * to a type that differs from the  type  of  the  object  pointed  to. Hence,
 * V* v;
 * T* p = static_cast<V*>v; // unsafe
 * 
 */
