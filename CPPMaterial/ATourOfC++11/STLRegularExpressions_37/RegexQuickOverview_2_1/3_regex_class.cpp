/**
* As is the case with all string classes, the regex has char type and type_trait as template:
template <class charT, class traits= regex_traits <charT>> class basic_regex

* Hence, we have wregex for wide chars and regex for normal regular expressions.
* 
* Specifying the grammer could actually be important if for example we wanted the regular expression not
* to be case sensitive (meh, I guess for my cases, I can use the regex itself to check for lower and 
* uppercase. Although it's fair to consider that for example if I'm looking for a file, and I don't care
* whether letters are lower or upper case, my regex should be case insensitive). 
*
* The following example shows how to change the grammer of regex.
*/

#include <regex>
#include <iostream>

void changin_regex_grammer() {
	using std::regex_constants::ECMAScript;
	using std::regex_constants::icase;

	std::string theQuestion = "C++ or c++, that's the question.";
	std::string regExprStr(R"(c\+\+)");

	std::regex rgx(regExprStr);
	std::smatch smatch;
	
	if (std::regex_search(theQuestion, smatch, rgx)) {
		std::cout << "case sensitive: " << smatch[0];       // c++
	}

	std::regex rgxIn(regExprStr, ECMAScript | icase);
	if (std::regex_search(theQuestion, smatch, rgxIn)) {
		std::cout << "case insensitive: " << smatch[0];     // C++
	}
}

