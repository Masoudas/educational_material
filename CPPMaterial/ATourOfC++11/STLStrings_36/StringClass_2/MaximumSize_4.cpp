/**
 * There's a static string::npos that shows a position beyond string length and is usually used to mean
 * the end of string. 
 * 
 * If we pass this size at the constructor, we throw a std::length_error, which happens when the string
 * is longer than the size string class can handle.
 * 
 * I write the code here, but there's no such construction at least in my windows machine.
 * string s9 {string::npos,'x'}; // throw length_error
 */
#include <string>
