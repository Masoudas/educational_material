/**
 * A regular expression is a matching engine (usually state machine) created from a set of chars, such as string.
 * This is equivalent to the pattern we intend to match.
 * 
 * Here's the definition of it in STL:
template<class C, class traits = regex_traits<C>>
class basic_regex {
public:
using value_type = C;
using traits_type = traits;
using string_type = typename traits::string_type;
using flag_type = regex_constants::syntax_option_type;
using locale_type = typename traits::locale_type;
˜basic_regex(); // not virtual; basic_regex is not meant to be used as a base class
// ...
};

* traits_type will be discussed later. */

/**
Like string, regex is an alias for the version that uses chars:

using regex = basic_regex<char>;

The meaning of regular expression patterns is controlled by syntax_option_type constants defined
identically in regex_constants and regex. But for the most part, we don't want to touch that. 
There's one option however, "ECMAScript The regular expression grammar is the one used by ECMAScript
in ECMA-262 (with minor modifications; §iso.28.13)".So this is the grammar of the regex.

So we have serveral constructors and several methods to change locale and other info after.

The simplest form of initializinga regex is with a string.
*/
#include <regex>
#include <string>
#include <iostream>

using namespace std;
void defining_the_basic_regex(){
    regex pat1 {R"(\w+\d∗)"}; // no way of outputting the pattern in pat1. R with paranthesis indicates raw string.
                // Pattern is one or more words, then zero or more digits. 
    string s {R"(\w+\d∗)"};
    regex pat2 {s};
    cout << s << '\n'; // the pattern in pat2
}