/**
 * Here are the rules:
 * 
 * 1- DON'T DO IT. Almost no gains compared to passing std::vector or std::array.
 * 
 * 2- Arrays are never copied, because there's no copy assignment for arrays.
 * 
 * 3- The first dimension is always ignored. Hence, a[5][10] in argument is simply interpreted as 
 * array pointer to array of 10 ints. The number of elements other than first should always be
 * declared, like a[][10][15];
 * 
 * 4- The first dimension is simply treated as a pointer, hence a[10] is treated as (*a), a[][2]
 * is treated as (*a)[2] (pointer to an array of two of the type (int)).
 * 
 * NOTE: the compiler treats n-d arrays when passed as 1-D arrays. Hence, we are always passing
 * an array of something 1D. But what is it? In the case int a[2][3][4], we're passing a 1D array
 * of arrays of [3][4] ints. Hence, (*p)[3][4]. This is the point, C++ only passes 1D arrays
 * to functions.
 * 
 * Hence, f(int[]) is .... correct.
 * f(int[][]) is .... incorrect, because the second dimension is not specified.
 * f(int *p)
 * 
 * NOTE: as a matter of fact, every single array of multi-dim can be passed as single pointer, because
 * after all, they're consecutive places in the memory.
 */ 

/**
 * Note that with both f(int (*a)[]) and f(int a[][2]) and because they're the same, we use
 * the same indexing notation:
 * 
 * for (row)
 *  for (column)
 *      use a[row][column]
 * 
 * With the pointer notation however, like f(*p), we use the dereferencing operation.


/**
 * Note the difference between f(int** p) and f1(int [][3]). Aside from the fact that the second
 * one wants only pointer to arrays of 3 integers, in the following only f1 would work:
 * int a[2][3];
 * 
 * f(a);
 * f1(a);
 * 
 * Why? Because a is a pointer to array of three ints, and it's not a pointer to pointer. The pointer to
 * pointer can be achieved via &a[0][0].
 */ 