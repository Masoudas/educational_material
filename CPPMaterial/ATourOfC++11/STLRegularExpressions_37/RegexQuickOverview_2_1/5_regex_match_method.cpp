/**
* regex_match method and it's overloads are used for checking whether an entire string matches a particular 
* regular expression. As said before, the entire string should match the given regular expression for it to return
* true, otherwise it returns false.
* 
* It also accepts match_results classes for analyzing the result of search, which is useful only if we have
* grouping in the regex.
*/
#include <string>
#include <regex>
#include <iostream>
using std::string;

void using_regex_match_example() {
	string str1{ "C++" };
	string str2{ "C++ in a sentence" };

	std::regex pattern{ R"((c)(\+\+))" , std::regex::icase };

	if (std::regex_match(str1, pattern)) {
		std::cout << R"((c)(\+\+))" << " matches the string: " << str1 << std::endl;
	}

	if (!std::regex_match(str2, pattern)) {
		std::cout << R"((c)(\+\+))" << " doesn't match the string: " << str2;
	}

}

//int main() {
//	using_regex_match_example();	
//}