/**
* So, don't forget that we can use find to merely check whether a character (set) exists in a string or not.
* For example, we want to check whether the file name of a given file equals 'string', and we can do as 
* 'does_our_file_name_exist' shows.
* 
* Now, imagine if the string we want to compare to is also part of an string. So let's say we want to check whether
* a particular part of a sentence exists in another sentence. How can we do so?
* 1- Solution I: We can create a new string_view, and then use find.
* 2- Solution II: Alternatively, we can use a for loop together with std::equal. But we know that comparing strings
*	as such is slow, and for example a binary search is a lot faster. Therefore, this one is not a solution.
*/
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

void does_our_file_name_exist() {
	std::vector<std::string> files{ "f1.txt", "f2.txt", "f3.txt", "f4.txt" };

	auto file_exists = std::any_of(
		files.cbegin(), files.cend(), [](auto file) {return file.find("f3") != std::string::npos; });

	if (file_exists) std::cout << "file f3 exists in the collection";
}

void search_for_word_in_sentence() {
	std::string sentence{ "This is my very long sentence, which I write here, in C++" };
	std::string word_sen{ "C++ is a computer programming language" };

	auto found = sentence.find(std::string_view{ word_sen.cbegin(), word_sen.cbegin() + 3 }) < std::string::npos; 
	if (found) std::cout << "The word exists in the sentence";
}

//int main() {
//	search_for_word_in_sentence();
//}