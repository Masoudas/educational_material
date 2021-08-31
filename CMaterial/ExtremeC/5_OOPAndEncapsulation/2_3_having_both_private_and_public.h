/**
 * Me:
 * Here's a question. Can we have a struct with both public and private fields? The answer as opposed to what I
 * was expecting is yes!
 * 
 * Why is this the case? Well, I don't know! But we can do it, and the compiler would not throw any error 
 * indicating that the structure has been repeated. I guess in C, structures are only memory access methods, and 
 * as such, repeating them would cause no harm. But it is odd that we can extend them in a source file.
 */

/** Inside a header file:
typedef struct {
	int public;
} public_and_private;

*/

/** Inside a source file
typedef struct {
	int public;
	int private;
} public_and_private;
*/