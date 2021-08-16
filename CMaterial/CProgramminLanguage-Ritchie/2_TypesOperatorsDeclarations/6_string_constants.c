/**
 * A string constant, or string literal, is a sequence of zero or more characters surrounded by double quotes, as 
 * in:
"I am a string"
or
"" // the empty string //
 * The quotes are not part of the string, but serve only to delimit it. The same escape sequences used in character 
 * constants apply in strings; \" represents the double-quote character. String constants can be concatenated at 
 * compile time:
 
"hello, " "world"

 * is equivalent to

"hello, world"

 * This is useful for splitting up long strings across several source lines.
 *
 * Technically, a string constant is an array of characters. The internal representation of a string has a null 
 * character ’\0’ at the end, so the physical storage required is one more than the number of characters written 
 * between the quotes. This representation means that there is no limit to how long a string can be, but programs 
 * must scan a string completely to determine its length. The standard library function strlen(s) returns the 
 * length of its character string argument s, excluding the terminal ’\0’.
 * 
 * Be careful to distinguish between a character constant and a string that contains a single character: ’x’ is 
 * not the same as "x". The former is an integer, used to produce the numeric value of the letter x in the 
 * machine’s character set. The latter is an array of characters that contains one character (the letter x) and a 
 * ’\0’.
 */