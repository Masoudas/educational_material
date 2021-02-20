/**
* The object of type std::match_results is the result of a std::regex_match or std::regex_search (not
* the return type of course. The return type is boolean).
* 
* std::match_results is a CONTAINER having at least one capture group of a std::sub_match object. 
* The std::sub_match objects are sequences of characters. Each sub_match object (apart from the first one
* which is the plain matched sequence) is a match group of regex (a group as we recall is whatever between
* paranthesis).
* 
* As we already said, match_results has four aliases, the most important of which is smatch, which is used
* for string (cmatch and wmatch are also there).
* 
* Among the usual methods of match_results that are not too obvious, we have:
* -	smatch[i]	Returns the ith capture group.
* -	smatch.length(i)	Returns the length of the ith capture group.
* -	smatch.position(i)	Returns the position of the ith capture group.
* -	smatch.str(i)	Returns the ith capture group as string.
* - smatch.format(...)	Formats std::smatch objects for the output.
*
* The sub_match class is pretty much like match_results. It has four aliases. It's the elements of the 
* match_results container (smatch[i] returns ith sub_match).
* 
* The following methods are of interest:
* cap.matched()	Indicates if this match was successful.
* cap.first() and cap.end()	Returns the begin and end iterator of the character sequence.
* cap.length()	Returns the length of the capture group.
* cap.str()	Returns the capture group as string.
* cap.compare(other)	Compares the current capture group with another capture group.
*/
#include <string>
#include <regex>
#include <iostream>


void smatch_and_regex_search() {
	std::string sentence{ "This is written in C++, or in c++, but not C + +" };
	std::regex pattern{ R"((c)(\+\+))", std::regex::icase };
	
	std::smatch match{};
	
	if (std::regex_search(sentence, match, pattern)) {	// Found instance(s)
		std::cout << "A match was Found, and smatch has three parts:\n " ;
		std::cout << "The total matched string is:" << match[0] << "\n ";

		std::cout <<  "The first matched grous is " << match[1] << ", and the second matched group is " << match[2];
	}
}
//
//int main() {
//	smatch_and_regex_search();
//}