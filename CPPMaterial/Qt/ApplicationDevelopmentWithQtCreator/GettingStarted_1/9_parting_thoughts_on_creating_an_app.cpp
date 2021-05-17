/**
 * It does appear that qt requires header files as well as TUs to detect the program structure, particularly
 * in the .pro file. Hence, it's best to create both for it.
 * 
 * Note that QObject is what we mostly inherit in different contexts. For that to be effective and be inherited
 * as a public base of the class, it's best to design classes using struct keyword rather than class keyword.
 */