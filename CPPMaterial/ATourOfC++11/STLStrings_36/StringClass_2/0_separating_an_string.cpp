/**
* Let's ensure that we get this right, so that we won't have another roller-coaster in the future.
* 
* First, let's set the terms straight. When we talk about an string like "/home/masoud/dir", and we talk about
* breaking the string down on '/', we mean:
* 1- Keeping from start of string to the first slash.
* 2- Keeping what happens between two slashed.
* 3- Keeping what happens from last slash to the end of the string.
* 
* string::find(const string& str, size_t pos) returns (in size_t) the first position where str occurs in string.
* Note that as expected, this method returns the exact (first) occurance of the string. Also, if it can't find
* a position, it returns npos, and if str is zero length, returns current position.
* 
* Now, compared to Java for example, there's no method that breaks down a string on a given regular expression
* for example, and then returns the broken string. We have two options:
* 1- Return the position from first char after slash, to the last position. There is however one point of caution
* with this method. If find goes beyond last char, it returns npos. So we should check with an if to set the last
* postion to the end of the string (and not npos).
* 2- using std::substr(pos, count) to create a new string. Note that cound here is the length of the string (0
* means string of length zero). Note that substring has the propery that if count > len, it returns all chars from
* pos to end. This is particularly important for something like x/dir, because now, substr(2, string::npos) returns
* only dir, and does not throw for example.
* 
*/

#include <string_view>
#include <iostream>

void find_all_instances() {
	using std::string_view;
	string_view str = "az/az/az/az/az/";

	size_t start = 0;
	while (true) {
		start = str.find('w', ++start);

		if (start == string_view::npos) return;
		std::cout << start << '\t';
	}
}

void separate_first_on_slash() {
	using std::string_view;
	string_view path = "/user/masoud/home/masoud/";

	auto loc1 = path.find("/", 5);
	auto loc2 = path.find("/", loc1 + 1); 

	auto s_path1 = path.substr(loc1 + 1, loc2 - loc1 - 1);
	std::cout << "Second folder between two slashes is: " << s_path1 << '\n';
}

void separate_all_on_slash() {
	using std::string;
	string path = "~/user/masoud/home/dir";
	//string path = "/user/masoud/home/dir";
	//string path = "/user/masoud/home/";

	auto loc1 = 0; // Search starting position (one after slash)
	auto loc2 = path.find('/', loc1); // Position of slash

	// If no slashes exist, we return.
	if (loc2 == string::npos) return;

	while (true) {	
		// The total length is at least one.
		if (loc2 - loc1 >= 1) std::cout << path.substr(loc1, loc2 - loc1) << '\t'; 
		// if (loc2 - loc1 >= 1) { std::pair{loc1, loc2 == npos ? loc2, path.size() - 1}} // Be careful! Find may
																						  // go beyond last char.	

		if (loc2 == string::npos) return;

		loc1 = loc2 + 1;
		loc2 = path.find('/', loc1);
	}

}

//int main() {
//	find_all_instances();
//}

