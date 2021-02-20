/***
 * There's a reason why the say think of a multid-imensional array as an array of arrays (i.e, 
 * a one dimensional array of some entity). This will help never forgetting how arrays are passed
 * to functions for example.
 * 
 * 
 * The rule is that the variable decays to a one dimensional pointer. Hence for example,
 * when we declare:
 * 
 * int a[] = {1, 2, 3};
 * 
 * a in this expression decays to a pointer to one integer. Now when we say
 * 
 * int a[2][3]; a also decays to a pointer to a one dimensional array. But what would that
 * array hold? a pointer to an array of three integers. This is exactly what happens when
 * we pass an array to function (see _3_8).
 *
 * Also, this is the reason why we can't say int** p = a for a two dimensional array, 
 * because a is a pointer to an array of three integers. We must say p = &a[0]
 */