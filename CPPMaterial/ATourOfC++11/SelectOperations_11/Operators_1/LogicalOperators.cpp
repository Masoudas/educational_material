/**
 * This includes &&, || and !. They take operands of arithmetic and pointer type (remember that if (ptr) is true or false,
 * if ptr is null), and turn them into logical statements. The first two evaluate the second argument only if necessary.
 * 
 * while (p && !whitespace(∗p)) ++p;
 * Here, p is not dereferenced.
 */