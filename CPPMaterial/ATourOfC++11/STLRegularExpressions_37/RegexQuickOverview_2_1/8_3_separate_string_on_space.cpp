/**
* Exercise: Separate a string on white space, giving each individual word as a result?
* 
* Solution: We know that a word is a set of at least one char. The problem however is that a char is just
* a-z, A-Z and 0-9 together with _. Hence, a better alternative is to use the negate of white space. In conclusion,
* the regular expression is [^\s]+. So, we can use this regex together with a sregex_iterator to find what we seek.
*/
#include <regex>
#include <string>
#include <iostream>

void separate_on_white_space() {
	std::regex pattern{ R"([^\s]+)", std::regex::icase };
	std::smatch match{};

	std::string sentence{ "This is my  sentence in C++, by c++, for C++" };

	std::sregex_iterator begin{ sentence.cbegin(), sentence.cend(), pattern };
	std::sregex_iterator end{};

	for (; begin != end; begin++) {
		std::string word = (*begin).str();

		std::cout << word << '\n';
	}
}

//int main() {
//	separate_on_white_space();
//}
