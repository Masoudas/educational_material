/**
 * Let's dedicate a specific section to int type arithmetic.
 * As we know, int is always signed by definition, and its size always greater than equal short.
 * 
 * As we already indicated, when an unsigned int overflows, it goes back to zero (x%2^32 for example). When it is assigned a 
 * negative number, it underflows (becomes a large positive number 2^32 - x for example).
 * 
 * When an int overflows, the behavior is undefined. When it underflows, the behavior is undefined.
 * As we know, overflow only occurs with addition and multiplication, and underflow with subtraction.
 * 
 * What happens when two ints are mixed? The result is always an int. Hence int = int * int and if overflow 
 * occurs, result is unknown.
 * What happens when two unsigned ints are mixed? The result is always an unsigned int.
 * What happens when an unsigned is combined with a signed? The result is always the unsigned.
 * What happens when unsigend is assigned to signed? Starting from 2 ^ w (w highest bit),
 * the result becomes negative.
 * 
 * What happens when a type greater than int is mixed with int? The int type is promoted to greater type.
 * Note that we're not talking about the return type here, we're talking about mixing.
 * long = int * long; (int is promoted to long)
 * long = int * int; (no promotion happens here during multiplication, but result is promoted to long.)
 * 
 * To verify this, you might want to compare (I used long long here because on Windows machine sizeof(int) = sizeof(long)):
 * int x = pow(2, 30);
 * int w = 2;
 * long long y = 2;
 * long long z = x * y; // This would be a positive number
 * long long u = x * w; // This would be a negative number!
 * 
 * Note that it makes no difference if we had a literal here. for example, x * 2 would still be a negative, because
 * 2 would be interpreted as integer literal (smallest type that could fit the thing).
 * 
 * If one operand is unsigned int and the other is long, both are promoted to unsigned long (especially because long 
 * and int can be equal).
 * 
 */





