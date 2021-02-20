/**
* As we may recall, some characters have particular meanings in regular expressions, such as +, *, etc.
* Now, when trying to write regex, we sometimes need to use literal chars, such as +, for which we should
* use \, and say \+ for example. However, \+ is not a recognized string token, which is why we need to use
* \\+, so that slash is taken literlly, which in conjunction with + is interpreted by regex as \+.
* 
* Note that '\+' is afterall two chars, and construcing an string as such does not throw an error. It's
* only when you try to interpret is a regex that you get into problem, namely \+ is not a escapable expression
* (unlike \n for example).
* 
* To avoid all of this, we use raw strings. raw strings have the property that '\' is interpreted literally,
* and is not escaped. Don't forget the parantheis when writing raw strings.
* 
*/
#include <string>

void defining_regex_with_raw_string() {
	using std::string;

	// string reg_ex{ "C\+" }; Error, \+ is not a special character.
	string st1{ R"(C\+)" };
}
