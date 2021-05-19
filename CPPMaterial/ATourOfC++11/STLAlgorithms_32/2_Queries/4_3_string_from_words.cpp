/**
* Question: How can we form a string from each individual word?
* 
* We can think of two solutions:
* 1- Use accumulate to compute the sum. 
*	Note that we use the constructor to avoid adding space at the end. This method however is likely less optimal 
* than using ostringstream.
* 
* 2- Use ostreamstring to generate the sum of elements.
*	One thing to notice about this approach is that I can't pass the first word in the constructor of the stream
* generator. I need to pass it using the stream operation.
*/

#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
#include <iostream>
#include <sstream>

using std::string;
void sum_words_using_accumulate() {
	std::vector<string> words{ "This", "is", "C++" };

	std::string sentence{"This"};
	sentence = std::accumulate(++words.begin(), words.end(), sentence, 
		[](string&& out, const string& val) { return out + " " + val; });

	std::cout << sentence;
}

void sum_words_using_ostringstream() {
	std::vector<string> words{ "This", "is", "C++" };
	 
	std::ostringstream sentence{};	
	sentence << words[0];
	std::for_each(++words.begin(), words.end(), [&](const string& val) {sentence << " " << val; });

	std::cout << sentence.str();
}

//int main() {
//	sum_words_using_ostringstream();
//}