/*
* In C++, we're able to resize a string, making it modifiable in terms of size. 
* We have a couple of methods inside the string class:
* 
* 1- size() = length()		:		Both return the size of the string
* 2- max_size()				:		Maximum size of string possible!
* 3- resize(n,c)			:		Resize the string, get the size c
* 4- reserve(n)				:		Ensure than string can hold n chars without reallocation
* 5- capacity()				:		The number of chars the string can hold without reallocation.
* 6- shrink_to_fit()		:		Make capacity = size
* 7- clear()				:		clear the string
* 8- empty()				:		Is string empty?
* 
* 
* How does one access a particular character of the string "s" to write in it?
* s[i]						:		Accesss element i
* s.at(i)					:		Same as []
* s.front()					:		First (front) char
* s.back()					:		Last (back) char
* s.push_back(c)			:		Put c at end.
* s.pop_back()
* s+=x						:		Add x to this string
* s = s1 + s2				:		Concatenation. An optimized version of s+=s1; s+=s2;
* s.c_str() = s.data()		:		A C-Style version of the string (zero terminated).
* s.swap(s,s2)				:		Swap the values s and s2.
* 
* An out-of-range access using at() throws std::out_of_range. A +=(), push_back(), or + 
* that would cause size() to exceed max_size() will throw std::length_error
* 
* Note: If we put a zero termination string somewhere in the middle of a string, ugly things may happen!


*/
#include <string>
#include <iostream>

using namespace std;

void play_with_string_size() {
	string str = "Base";	

	cout << "Initial capacity is: " << str.capacity() << endl;
	cout << "Value at 0 is: " << str[0] << endl;

	for (int i = 0; i <= 4; i++)
	{
		str = str + " " + str;	// The assignment does not create a new class. We can check this by printing the memory address.
		// cout << &str << endl;
	}
	
	cout << "Concatenated string: " << str << endl;
}

void string_with_null_char_in_middle() {
	string str = "a\0a";	// This baby has three chars, but only two will be shown!
	const char* s = str.c_str();

	cout << "String with null termination in the middle returns size 1 instead of three: " << strlen(s) << endl;
}