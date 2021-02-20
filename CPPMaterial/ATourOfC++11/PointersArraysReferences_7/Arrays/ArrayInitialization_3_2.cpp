/**
 * A syntax like this initializes an array without specifying its size.
 * int a[] = {1,2,3};
 * 
 * If initializer specifies not enough arguments, the rest are initialize to zero.
 * All array elements that are not initialized explicitly are zero-initialized (or empty initialized). 
 * int a[4] = {1} // {1, 0, 0, 0}
 * 
 * We also have:
 * int a[3] = {0}; // valid C and C++ way to zero-out a block-scope array
 * int a[3] = {}; // invalid C but valid C++ way to zero-out a block-scope array
 * 
 * What happens to an array with no initialization? The best I've found so far is that
 * it has random values! But not sure.
 * int a[5];
 * 
 * There's no built-in copy mechanism for arrays. Hence, initialization with other arrays
 * or a direct copy is not possible.
 * int a2[3] = a; // Error
 * int a3 = a;  // Error
 * 
 * Note: Initialization with expression has unspecified behavior. Essentially, when writing expressions
 * for initializing an array, we don't know which ones are executed first.
 * 
 * int a[2] = {f(), g()}; // We don't know if f is executed first or g.
 * 
 * int n = 1;
 * int a2 = {++n, ++n}; Could be either {2,3} or {3, 2}
 * 
 * For higher dimension arrays, it is possible to initialize in one line as well.
 * 
 * int a[2][3] = {1, 2, 3, 4, 5, 6, }// First row is 1,2,3. Second row is 4,5,6.
 * 
 * With string literals, we know that not defining the size means str length + \0.
 * char c[] = "aaa";
 * 
 * That being said, if we determine the size, and the string exceeds the array size,
 * the array is truncated:
 * char c[3] = "aaa"; // This array will have three elements, and does not terminate in \0.
 * 
 */

/*
* What about empty initialization? such as int[10] arr = {};
*/