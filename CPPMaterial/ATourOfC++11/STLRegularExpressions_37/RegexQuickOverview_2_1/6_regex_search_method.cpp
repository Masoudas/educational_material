/**
* std::regex_search checks if text contains a text pattern. You can use the function with and without a 
* std::match_results object and apply it to a C string, a C++ string or a range. (Interpret this as if
* there's at least one match, as opposed to if it matches for regex_match).
* 
* The following shows how to use regex_search with const char, wchar and string.
*/
#include <regex>
#include <string>
#include <iostream>

void regex_search_with_const_char() {
	// regular expression holder for time
	std::regex crgx("([01]?[0-9]|2[0-3]):[0-5][0-9]");

	// const char*
	std::cmatch cmatch;

	const char* ctime{ "Now it is 23:10." };
	if (std::regex_search(ctime, cmatch, crgx)) {
		std::cout << ctime << std::endl;                   // Now it is 23:10.   
		std::cout << "Time: " << cmatch[0] << std::endl;   // Time: 23:10
	}
}

void regex_search_with_string() {
	// std::string
	std::smatch smatch;

	// regular expression holder for time
	std::regex crgx("([01]?[0-9]|2[0-3]):[0-5][0-9]");

	std::string stime{ "Now it is 23:25." };
	if (std::regex_search(stime, smatch, crgx)) {
		std::cout << stime << std::endl;                   // Now it is 23:25.
		std::cout << "Time: " << smatch[0] << std::endl;   // Time: 23:25
	}
}


void regex_search_with_wide_char() {
	// regular expression holder for time
	std::wregex wrgx(L"([01]?[0-9]|2[0-3]):[0-5][0-9]");

	// const wchar_t*
	std::wcmatch wcmatch;

	const wchar_t* wctime{ L"Now it is 23:47." };
	if (std::regex_search(wctime, wcmatch, wrgx)) {
		std::wcout << wctime << std::endl;                 // Now it is 23:47.
		std::wcout << "Time: " << wcmatch[0] << std::endl; // Time: 23:47
	}

}

void regex_search_with_wide_char_string() {
	// regular expression holder for time
	std::wregex wrgx(L"([01]?[0-9]|2[0-3]):[0-5][0-9]");

	// std::wstring
	std::wsmatch wsmatch;

	std::wstring  wstime{ L"Now it is 00:03." };
	if (std::regex_search(wstime, wsmatch, wrgx)) {
		std::wcout << wstime << std::endl;                  // Now it is 00:03.
		std::wcout << "Time: " << wsmatch[0] << std::endl;  // Time: 00:03
	}

}