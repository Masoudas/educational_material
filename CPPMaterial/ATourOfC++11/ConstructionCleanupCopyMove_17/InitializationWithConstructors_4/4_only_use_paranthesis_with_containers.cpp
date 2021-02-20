/*
* Essentially, we don't need the paranthesis constructor (Bjarne says it has no advantage over the
* bracket constructor). The only case is when we have an initializer list and a constructor
* that takes a parameter. In such cases, using the () specifies that we want to use the constructor
* with single element, and not initializer list. Why? Because if we wanted to use the initilizer_list
* with paranthesis, we have to write ({}), meaning use the brackets!
*
* (Me: Why would initializer list take precedence over a single element in overload resolution?
	As we say in InitializerList_6 _2, while all overload resolution rules hold, an initializer
	list takes precedence over other constructors.)
*/
#include <vector>
#include <iostream>
using namespace std;

void the_case_for_using_paranthesis_constructor() {
	vector<int> vec(10);	// Vector of ten elements.
	vector<int> vec1{ 10 };	// Vector with element ten.
	vector<int> vec2({ 10 });	// Use initializer list with element 10. So vector of one element.

	cout << "Prints zero for vector of ten elements: " << vec[0] << endl;
	cout << "Prints 10 for vector of one element with ten: " << vec1[0] << endl;
	cout << "Prints 10 for vector of one element with ten: " << vec2[0] << endl;
}

void with_strings_no_need() {
	vector<string> vec1{ "Using initializer_list" };
	//vector<string> vec1( "Using initializer_list" ); Wrong! There's no constructor with string parameter!
}

//int main() {
//	the_case_for_using_paranthesis_constructor();
//}