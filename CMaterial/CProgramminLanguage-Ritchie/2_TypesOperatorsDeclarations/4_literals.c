/**
 * An integer constant like 1234 is an int. A long constant is written with a terminal l (ell) or L , as in 
 * 123456789L ; an integer constant too big to fit into an int will also be taken as a long. Unsigned constants 
 * are written with a terminal u or U , and the suffix ul or UL indicates unsigned long.
 * 
 * Floating-point constants contain a decimal point ( 123.4 ) or an exponent ( 1e-2 ) or both; their type is 
 * double , unless suffixed. The suffixes f or F indicate a float constant; l or L indicate a long double.
 * 
 * 
 * The value of an integer can be specified in octal or hexadecimal instead of decimal. A leading 0 (zero) on an 
 * integer constant means octal; a leading 0x or 0X means hexadecimal. For example, decimal 31 can be written as 
 * 037 in octal and 0x1f or 0x1F in hex. Octal and hexadecimal constants may also be followed by L to make them 
 * long and U to make them unsigned : 0XFUL is an unsigned long constant with value 15 decimal.
 * 
 * A character constant is an integer, written as one character within single quotes, such as ’x’. The value of a 
 * character constant is the numeric value of the character in the machine’s character set. For example, in the 
 * ASCII character set the character constant ’0’ has the value 48, which is unrelated to the numeric value 0. If 
 * we write ’0’ instead of a numeric value like 48 that depends on the character set, the program is independent 
 * of the particular value and easier to read. Character constants participate in numeric operations just as any 
 * other integers, although they are most often used in comparisons with other characters.
 * 
 * Certain characters can be represented in character and string constants by escape sequences like \n (newline); 
 * these sequences look like two characters, but represent only one. In addition, an arbitrary byte-sized bit 
 * pattern can be specified by ’\ooo’, where ooo is one to three octal digits (0...7) or by ’\xhh’, where hh is 
 * one or more hexadecimal digits ( 0...9,):
 
#define VTAB ’\013’ // ASCII vertical tab //
#define BELL ’\007’ // ASCII bell character //

 * or, in hexadecimal, (a...f, A...F ).
#define VTAB ’\xb’ // ASCII vertical tab //
#define BELL ’\x7’ // ASCII bell character //

 * The character constant ’\0’ represents the character with value zero, the null character. ’\0’ is often written 
 * instead of 0 to emphasize the character nature of some expression, but the numeric value is just 0.
 */