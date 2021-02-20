/**
 * As said earlier, the macros provided here help deal with chars and operations on them. THESE METHODS WORK
 * WITH CHARS. THE EQUIVALENT <cwctype> WORK WITH WIDE CHARS.
 * 
 * The idea here is that we want to avoid simple char comparisons like ch > 'a', because char is system
 * dependent and such comparisons are not portable and error prone. This is why we use islower().
 * 
 * 1- isspace(c) returns true if c is space(\s), horizontal tab(\t), vertical tab(\v), newline(\n), form feed (\f)
 * or carriage return (\r).
 * 
 * 2- isalpha(c)? Is [a-zA-Z] (not underscore)
 * 
 * 3- isdigit(c)? Is [0-9]
 * 
 * 4- isxdigit(c)? Is hexadecimal digit [a-fA-F]
 * 
 * 5- isupper(c)? islower(c)? Is upper or lower?
 * 
 * 6- isalnum(c)? is alpha or digit?
 * 
 * 7- iscntrl(c)? Is it a control character (ASCII 0..31 and 127)?
 * 
 * 8- ispunct(c)? Is c not a letter, digit, whitespace, or invisible control character?
 * 
 * 9- isprint(c)? Is c printable (ASCII ''..'~')?
 * 
 * 10- isgraph(c)? isalpha(c) or isdigit(c) or ispunct(c)? note: not space.
 * 
 * In addition, the standard library provides two additional functions:
 * 1- toupper(c): Either c or its equivalent upper case.
 * 2- tolowe(c): Either c or its equivalent lower case.
 */
#include <cctype>
#include <iostream>
using namespace std;

namespace CharacterClassification_2 {
    int main() {
        char c = '\t';

        cout << "Is char white space: " << isspace(c) << endl;

        char c1 = 'C';
        if (isalpha(c1)) {
            cout << "It's an alpha. " << endl;
            cout << "Is char white space: " << isupper(c1) << endl;
        }

        char c2 = '?';   // A punctuation mark.
        cout << "Is question mark ispunct: " << ispunct(c2) << endl;

        char c3 = 'c';
        c3 = static_cast<char>(toupper(c3));
        cout << "Upper case of c is: " << c3;

        return 0;
    }
}





