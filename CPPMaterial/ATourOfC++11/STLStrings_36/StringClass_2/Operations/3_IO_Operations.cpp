/*
* A string has overloaded the >> and <<, so that they return an stream. 
* 
* So, there are a couple of cool ways to read from the command line:
* 
* -- getline(in, s, d)			:	 Read until a char is put
*	For this one, we use the method getline(istream, string, char), which is part of the stream class. It requires a
*	an stream (which is cin, and not getc()!!!), a string to put char in, an a termination char. For example, \n stops
*	when the user enters. The stop char would not be a part of the stream,
* 
* -- getline(in, s)				:	 Same as getline(in, s, d), where \n is widened to match string's char type.
* 
* -- >>							:	 Puts word in string before reaching a white space (\s, \t, \v, \n)
*	Because these methods return a reference to their input stream, they can be chained to get several inputs 
*	(The spaces are removed).
*/

#include <iostream>
#include <string>
using namespace std;

void get_line_using_stream_and_string() {
	string s;
	getline(cin, s, '\n');

	cout << s;
	
	// Getting several lines
	//vector<string> lines;
	//for (string s; getline(cin, s);)
	//	lines.push_back(s);
}

void get_word_from_command_line() {
	string first_name;
	string second_name;

	cin >> first_name >> second_name;

	cout << first_name << second_name;
}

