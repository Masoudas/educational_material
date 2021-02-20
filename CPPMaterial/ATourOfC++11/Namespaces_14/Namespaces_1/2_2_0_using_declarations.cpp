/**
* We can use using with particular members of a namespace to bring them to the current (scope of?) code.
* As of CPP20, we can do this to even bring enums in. 

* In layman's term, this says that in this scope, use string as defined by stl. A using-declaration 
* introduces a synonym into a scope. 
*/

#include<string>
#include<vector>
#include<sstream>

using std::string;

// Version I: Without the using declarative.
//std::vector<std::string> split(const std::string& s)
//// split s into its whitespace-separated substrings
//{
//	std::vector<std::string> res;
//	std::istringstream iss(s);
//	for (std::string buf; iss >> buf;)
//		res.push_back(buf);
//	return res;
//}

std::vector<string> split(const string& s)
{
	std::vector<string> res;
	std::istringstream iss(s);
	for (string buf; iss >> buf;)
		res.push_back(buf);
	return res;
}