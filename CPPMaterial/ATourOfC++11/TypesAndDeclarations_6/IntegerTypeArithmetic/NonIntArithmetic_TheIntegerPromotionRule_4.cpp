/**
 * Whenever a short integer type (which is short signed or unsigned, char signed or unsigned
 * or bool, int8_t, uint8_t) is used in an expression, it is promoted to an int type.
 * Hence for example:
 * 
 * unsigned char c = 255;
 * c++; c // c is promoted to int, then one is added, resulting in 256, then assigned back to c, which results in zero.
 * 
 * char c = 127;
 * c++; // c is promoted to 128, and then reassigned to c. However it overflows, so the outcome may be -128 or 0.
 * 
 * int d = c * 2; // This assignment is fine, due to promotion to int.
 * 
 * c * 2 > c; This assigment is true. But why? Because c * 2 is promoted to int, and so does c. Otherwise, 2 * c could
 * have been any value below 127 and this would have been false.
 * 
 * As another example, consider:
 * unsigned char x = 0;
 * unsigned char y = 1;
 * printf("%u\n", x - y); 
 * 
 * The outcome of this expression is -1.
 * 
 * 
 * For this reason, we should always perform operations on integer types or higher, to avoid confusion.
 */
