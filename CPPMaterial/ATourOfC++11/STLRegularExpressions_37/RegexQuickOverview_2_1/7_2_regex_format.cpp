/**
* Used as replace is used, only to create new strings rather than replacing the original one, by formatting a
* new expression (I guess perhaps creating a new string using replace does the same job).
* The dollar stuff we talked about in regex_replacement are used exactly the same.
*/

#include <regex >
#include <string>
#include <iostream>

void create_a_new_string_by_formatting() {
	std::string future{ "Future" };
	const std::string unofficial{ "unofficial, C++0x" };
	const std::string official{ "official, C++11" };

	std::regex regValues{ "(.*),(.*)" };
	std::string standardText{ "The $1 name of the new C++ standard is $2." };
	std::string textNow = std::regex_replace(unofficial, regValues, standardText);
	std::cout << textNow << std::endl;
	// The unofficial name of the new C++ standard is C++0x.

	std::smatch smatch;
	if (std::regex_match(official, smatch, regValues)) {
		std::cout << smatch.str();                                   // official,C++11
		std::string textFuture = smatch.format(standardText);
		std::cout << textFuture << std::endl;
	}                       // The official name of the new C++ standard is C++11.
}