/*
* String classes provide standard iterators.
* 
* p=s.begin()			:			p is an iterator to the first character of s
* p=s.end()				:			p is an iterator to one beyond the end of s
* p=s.cbegin()			:			p is a const_iterator to the first character
* p=s.cend()			:			p is a const_iterator to one beyond the end of s
* p=s.rbegin()			:			p is the beginning of the reverse sequence for s
* p=s.rend()			:			p is the end of the reverse sequence for s
* p=s.crbegin()			:			p is a const_iterator to the beginning of the reverse sequence for s
* p=s.crend()			:			p is a const_iterator to the end of the reverse sequence for s
* 
* The reverse iterators reverse the string by themselves, so there's no need to for example write begin()--.
* 
*/
#include <string>
#include <iostream>

using namespace std;

void using_string_iterators_basics() {
	string str{ "abc" };

	string::reverse_iterator begin = str.rbegin();	// Reverse begin (which would be c)
	string::reverse_iterator end = str.rend(); // Reverse end (before a).

	for (; begin != end; ++begin) {
		cout << *begin;
	}

}


