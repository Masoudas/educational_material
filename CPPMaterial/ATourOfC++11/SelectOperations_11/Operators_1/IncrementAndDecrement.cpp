/**
 * The post increment operator (i++) is more resource consuming that pre-increment (++i).
 * This is because post increment operator creates a copy of the variable, then adds to it,
 * which is not the case for pre-increment. Hence, where possible, we use pre-increment.
 * Why do we create a temporary with post-fix? Because in the current expression, we're still
 * using the same value (not the augmented one). Hence, overloading the increment and decrement
 * looks something like this:
 MyOwnClass& operator++()
 {
   ++meOwnField;
   return (*this);
 }

 MyOwnClass operator++(int)
 {
  MyOWnCLass tmp = *this;
  ++(*this);
  return tmp;
 }
 * 
 * 
 * Moreover, most compilers substitute post with pre increment operator when possible.
 * 
 * We also know that ++ can be used with pointers!
 * 
 * Now consider the following code:
 * int length = strlen(q);
 * for (int i = 0; i<=length; i++)
 *   p[i] = q[i];
 * 
 * This is wasteful apparently. We could write:
 * while (q!= 0){
 *      *p++ = *q++; 
 * }
 * *p = 0;
 * 
 * Aha, however, note that the value of p = q is q (the whole expression I mean, hence for example w = p = q, then w is q)
 * and because this is also a logical expression when we say *p (where zero terminates it), then
 * we can further simplify it as:
 * while (*p++ = *q++);
 * Note that when p++ and q++ reach termination point, first null is assigned to p, then the condition is checked. Hence,
 * p is always set to null.
 * 
 * However, as we know, the most efficient way of copying two expressions is to use strcpy:
 * char∗ strcpy(char∗, const char∗); // from <string.h>
 * For more general copying, we know that memcpy is the option.
 * 
 * 
 */ 