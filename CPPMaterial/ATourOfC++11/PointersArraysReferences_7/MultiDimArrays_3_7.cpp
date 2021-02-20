/**
 * We think of multi-dim arrays as 1D arrays, with pointers pointing
 * to lower entities. This is because if T* t is a pointer to t, then *t is of type t. Now, because
 * a is (loosely speaking) a pointer, hence *a should refer to the type it points to.
 * For example:
 * int a[2][3][4];
 * Here, a is 1D array of pointers of size 2, pointing to matrices of size [3][4].
 * 
 * Hence, we can say:
 * int (a*)[3][4] = a;
 * int (a*)[3][4] = ++a;
 * 
 * Hence for example the expression *( *( *(a + 2) + 1) + 2) must be interpreted as follows:
 * 1- buffer – An array of 5 two dimensional arrays, i.e. its type is “array of 5 two dimensional arrays”.
 * 2- buffer + 2 – displacement for 3rd element in the array of 5 two dimensional arrays.
   3- *(buffer + 2) – dereferencing, i.e. its type is now two dimensional array (I think more precisely, a pointer to 1D arrays)
   4- *(buffer + 2) + 1 – displacement to access 2nd element in the array of 7 one dimensional arrays.
   5- *( *(buffer + 2) + 1) – dereferencing (accessing), now the type of expression “*( *(buffer + 2) + 1)” is an array of integers.
   6- *( *(buffer + 2) + 1) + 2 – displacement to get element at 3rd position in the single dimension array of integers.
   7- *( *( *(buffer + 2) + 1) + 2) – accessing the element at 3rd position (the overall expression type is int now)
 * 
 * As we know at the end of the day, any array is just a consecutive position in the memory. Hence, 
 * we can actually access it using 1D pointers two. So for example to access the same element, one might
 * say that it is at 2 * (3 * 4) + 1 * 4 + 2. Hence for example:
 * element_data = *( (int *)buffer + 2 * (3 * 4) + 1 * 4 + 2 ); 
 * gets us to the same location. 
 * What is (int *)buffer? (It is equivalent to saying: int *x = &buffer[0][0][0] I think!!!!)
 */ 