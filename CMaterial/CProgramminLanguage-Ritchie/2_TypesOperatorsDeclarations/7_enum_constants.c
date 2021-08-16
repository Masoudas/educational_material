/**
 * There is one other kind of constant, the enumeration constant. An enumeration is a list of constant integer 
 * values, as in enum boolean { NO, YES };
 * 
 * The first name in an enum has value 0, the next 1, and so on, unless explicit values are specified. If not all 
 * values are specified, unspecified values continue the progression from the last specified value, as the second 
 * of these examples:
 
enum escapes { BELL = ’\a’, BACKSPACE = ’\b’, TAB = ’\t’, NEWLINE = ’\n’, VTAB = ’\v’, RETURN = ’\r’ };
enum months { JAN = 1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC }; // FEB = 2, MAR = 3, etc. //
 
 * Names in different enumerations must be distinct. Values need not be distinct in the same enumeration. 
 * Enumerations provide a convenient way to associate constant values with names, an alternative to #define with 
 * the advantage that the values can be generated for you. Although variables of enum types may be declared, 
 * compilers need not check that what you store in such a variable is a valid value for the enumeration. 
 * Nevertheless, enumeration variables offer the chance of checking and so are often better than #defines. In 
 * addition, a debugger may be able to print values of enumeration variables in their symbolic form.
 */