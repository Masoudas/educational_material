/**
* Regex can be used for the following major tasks:
* 1- Check if a text matches a text pattern: std::regex_match
* 2- Search for a text pattern in a text: std::regex_search
* 3- Replace a text pattern with a text: std::regex_replace
* 4- Iterate through all text patterns in a text: std::regex_iterator and std::regex_token_iterator
* 
* Note that 1 checkes whether a given string fully matches a regex, whereas 2 checks if there's a string that
* satisfies the regex inside the text.
* 
* As we already know, regex in every environment or language has a particular grammer. c++ offers us six
* grammers, of which the big guy himself says we should use the default one, if we don't know what is what. 
* The grammers are there as part of an enumeration inside regex as static. The most important one however is
* icase, which makes regex comparison case insensitive. To use a combination of grammers, we can or them:
* Example: std::regex{R"[^\s]+", std::regex::icase | std::regex::ECMAScript}.
* 
* We require three steps when working with regular expressions:
* 1- Defining the regular expression: This is done using regex class
* 2- Storing the result of the search: The result is usually put in <?>match class
* 3- Processing the result: Playing with the resulting <?>match.
* Example:
    std::string text="C++ or c++.";
    std::string regExpr(R"(C\+\+)");
    std::regex rgx(regExpr);

    std::smatch result;
    std::regex_search(text, result, rgx);

    std::cout << result[0] << std::endl;

* As a side note, the <?>match is smatch for string and cmatch for const char*. Generally, anything in regex
* header related to string starts with s, anything related to const char* starts with c, and with wc for wide chars,
* and anything with ws for wide char strings. I guess I probably wouldn't need more that s suffix for years
* to come.
*/