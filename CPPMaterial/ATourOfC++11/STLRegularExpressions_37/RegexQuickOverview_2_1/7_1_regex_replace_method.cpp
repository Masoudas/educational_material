/**
* Used for replacing whatever matches the given regular expression with the given expression. The result of 
* regex_replace is a new string as return value of the function. If we want to avoid creating a new string,
* we have to supply the method with a find method. Note that a regex_iterator is created implicity, meaning 
* EVERY occurance of a regex is replaced, and not just the first one. There is, however, a flag to take care
* of this:
* - If flags contains std::regex_constants::format_first_only, only the first match is replaced.
* - If flags contains std::regex_constants::format_no_copy, the non-matched subsequences are not copied into
*	out iterator.
* 
* 
* Question: Can we replace a particular group with the given string? For example, we want to replace the file
* name of a file? The way to access a particular group content is with []. Each new bracket gives access to a
* new group. Moreover, $n, where n is the group number, gives access to the group content. Note finally that $&
* gets the entire matched string, and not just each individual group. To place an actual dollar sign, we should
* use $$. All these information is contained in std::regex_format
*/
#include <regex>
#include <iostream>

void replacement_and_creating_a_new_string() {
	using namespace std;

	string future{ "Future" };
	string unofficialName{ "The unofficial name of the new C++ standard is C++0x. So it's C++0x and not C++98" };

	regex rgxCpp{ R"(C\+\+0x)" };
	string newCppName{ "C++11" };
	string newName{ regex_replace(unofficialName, rgxCpp, newCppName) };

	regex rgxOff{ "unofficial" };
	string makeOfficial{ "official" };
	string officialName{ regex_replace(newName, rgxOff, makeOfficial) };	// This does not create two objects,
																			// as return value is rvalue.

	cout << officialName << endl;
	// The official name of the new C++ standard is C++11.
}

void replacement_without_creating_a_new_string() {
	using namespace std;

	string unofficialName{ "The unofficial name of the new C++ standard is C++0x. So it's C++0x and not C++98" };
	regex rgxCpp{ R"(C\+\+0x)" };

	regex_replace(
		unofficialName.begin(), unofficialName.begin(), unofficialName.end(), rgxCpp, "C++11");

	cout << unofficialName;
}

void replacing_a_particular_match_with_its_own_reformatted_content() {
	std::string text = "Quick brown fox, owns a pet brown fox";
	std::regex vowel_re("(ow)(n)");

	// Accessing each matched group
	std::cout << std::regex_replace(text, vowel_re, "[$2][$1]") << '\n';

	// Chanigng matched groups
	std::cout << std::regex_replace(text, vowel_re, "[q][$&]") << '\n';
}

//int main() {
//	replacing_a_particular_match_with_its_own_reformatted_content();
//}