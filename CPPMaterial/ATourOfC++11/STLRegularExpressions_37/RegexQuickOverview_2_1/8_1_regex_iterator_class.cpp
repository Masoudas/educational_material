/**
* It’s quite convenient to iterate with std::regex_iterator and std::regex_token_iterator over the matched texts. 
* std::regex_iterator supports the matches and their capture groups. std::regex_token_iterator supports more. 
* You can address the components of each capture and by using a negative index, your can access the text between 
* the matches.
*/
#include <regex>
#include <string>
#include <iostream>
#include <unordered_map>

void find_each_word_with_regex_iterator() {

    using std::cout;
    std::string text{ "That's a (to me) amazingly frequent question. It may be the most f\
        requently asked question. Surprisingly, C++11 feels like a new language: The pieces \
        just fit together better than they used to and I find a higher-level style of progra\
        mming more natural than before and as efficient as ever." };

    std::regex wordReg{ R"(\w+)" }; 
    std::sregex_iterator wordItBegin(text.begin(), text.end(), wordReg);
    const std::sregex_iterator wordItEnd;

    std::unordered_map<std::string, std::size_t> allWords;
    for (; wordItBegin != wordItEnd; ++wordItBegin) {
        ++allWords[wordItBegin->str()];
    }

    for (auto wordIt : allWords) cout << "(" << wordIt.first << ":"
        << wordIt.second << ")";
    // (as:2)(of:1)(level:1)(find:1)(ever:1)(and:2)(natural:1) ...

}