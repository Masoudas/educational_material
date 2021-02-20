/*
* There are a couple of ways to get a substring of a string.
* 
* 1- The easiest one would be to use the constructor string{s, p, l}, which creates a new string from string s, 
* from position p, with length l. Note that if l > size, then the entire string is returned.
* 
* 2- s.substr(p,n)
*		Returns a new basic_string{&s, start=p, length=n}. If p + m exceeds N-1 (npos), the last position would 
* be N-1.
* 
*/
#include <string>
#include <iostream>

using namespace std;
void create_substring_using_constructor() {
	string str1{ "This" };

	string sub_str1{ str1, 0, 2 };
	cout << sub_str1;
}

void create_substring_using_method() {
	string str1{ "This" };

	cout << "This would print Th: " << str1.substr(0, 2) << endl;

	cout << "Exceeding length would print the entire string: " << str1.substr(0, 6);
}

//int main() {
//	create_substring_using_method();
//}