/**
* std::regex_token_iterator enables you by using indexes to specify which capture groups you are interested in 
* explicitly. If you don’t specify the index, you will get all capture groups, but you can also request specific 
* capture groups using its respective index. The -1 index is special: You can use -1 to address the text between 
* the matches. To access a particular subgroup of a particular match, use {{match, subgroup}}.vvvvvvvvvvvvvvvvvvvvvvvvvggggggg
*/

#include <regex>
#include <string>
#include <iostream>

void using_token_iterator() {
    // tokenIterator.cpp 
    using namespace std;

    string text = "Pete Becker,The C++ Standard Library Extensions,2006: \
        Nicolai Josuttis,The C++ Standard Library,1999";

    regex regBook(R"((\w+)\s(\w+),([\w\s\+]*),(\d{4}))");
    sregex_token_iterator bookItBegin(text.begin(), text.end(), regBook);

    const sregex_token_iterator bookItEnd;
    while (bookItBegin != bookItEnd) {
        cout << *bookItBegin++ << endl;
    }                         // Pete Becker,The C++ Standard Library Extensions,2006
                              // Nicolai Josuttis,The C++ Standard Library,1999

    sregex_token_iterator bookItNameIssueBegin(text.begin(), text.end(), regBook, { {2,4} });
    const sregex_token_iterator bookItNameIssueEnd;

    while (bookItNameIssueBegin != bookItNameIssueEnd) {
        cout << *bookItNameIssueBegin++ << ", ";
        cout << *bookItNameIssueBegin++ << endl;
    }                                           // Becker, 1999
                                                // Josuttis, 2001

    regex regBookNeg(":");
    sregex_token_iterator bookItNegBegin(text.begin(), text.end(), regBookNeg, -1);

    const sregex_token_iterator bookItNegEnd;
    while (bookItNegBegin != bookItNegEnd) {
        cout << *bookItNegBegin++ << endl;
    }                    // Pete Becker,The C++ Standard Library Extensions,2006
                         // Nicolai Josuttis,The C++ Standard Library,1999

}
