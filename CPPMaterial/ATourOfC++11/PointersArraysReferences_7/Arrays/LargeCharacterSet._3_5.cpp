/**
 * A string that starts with L is a large char set. 
 * wchar_t wide[] = L"Angst", where \u is the UNICODE char set.
 * 
 * We have six types of unicode, the most important three ar UTF-8, UTF16 and UTF32.
 * UTF-8 is actually 32 bits! The suffix we use for UTF-8 is u8. Then we have for example:
 * 
 * u8"The official vowels in Danish are: a, e, i, o, u, \u00E6, \u00F8, \u00E5 and y.".
 * I think this goes into wchar_t* type.
 * 
 */ 