/**
* As opposed to what is common knowledge, we can actually modify a string in three ways (note however that these
* modifications are simply about moving the interal char pointer of string view around, which is why they're 
* acceptable):
* 
* 1- remove_prefix: Removes n number of chars from the beginning.
* 2- remove_postfix: Removes n number of chars from the end of string.
* 3- swap: swaps the content of this string with the given string (question: Does it modify both strings?
* Well, the name of the method is not copy, but swap, so yes).
*/
#include <iostream>
#include <string_view>

void remove_pre_post_fix() {
    using namespace std;
    string str = "   A lot of space";
    string_view strView = str;
    strView.remove_prefix(min(strView.find_first_not_of(" "), strView.size()));
    std::cout << str << std::endl << strView << endl; // "A lot of space"

    char arr[] = { 'A',' ','l','o','t',' ','o','f',' ',
                  's','p','a','c','e','\0', '\0', '\0' };
    string_view strView2(arr, sizeof arr);
    auto trimPos = strView2.find('\0');
    if (trimPos != strView2.npos) strView2.remove_suffix(strView2.size() - trimPos);
    cout << arr << ": " << sizeof arr << endl             // A lot of space: 17 
        << strView2 << ": " << strView2.size() << endl;  // A lot of space: 14 
}

void swap_strings() {
    std::string_view str1{ "String 1" };
    std::string_view str2{ "String 2" };

    str1.swap(str2);

    std::cout << "Content of str1 is now str2: " << str1;
}
//
//int main() {
//    swap_strings();
//}
