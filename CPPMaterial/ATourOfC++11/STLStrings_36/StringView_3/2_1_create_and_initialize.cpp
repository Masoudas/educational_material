/**
* There are five ways to create a string view, three of them come by using constructor, one is by using the 
* substr method, and the last one is through the assignment operator.
* 
* -	Empty string view:	std::string_view str_view
* - From a C-string:	std::string_view str_view2("C-string")
* -	From a string view:	std::string_view str_view3(str_view2)
* - From a C array: 	std::string_view str_view4(arr, sizeof arr)
* 
* - From a string_view:	str_view4= str_view3.substring(2, 3)
* 
* - From a string view:	std::string_view str_view5 = str_view4
* 
* 
* Here's something to note: Because an string_view does not allocate new memory, then it's a very light container
* over the single string we create. I had this thought that in order to work with substrings of a string, I better
* pass indexes around. However, note that substring is immutable and does not allocate new memory. Hence, creating
* a substring keeps reference to the original string. Hence, keep on using string_views as you would in any other
* language.
* 
* string_view s1{"Here"};	// Allocates one memory for here and that's it.
* string_view s2 = s1.substr(2);	// No new memory is allocated. Still points to the same memory as s1.
*/
#include <string_view>
using std::string_view;

void create_string_view() {
	char str[] = { 'a', 'b', 'c' }; // str is pointer to char (not const). 
									// &str is address pointer to array of three chars :D
	//char (*address)[3] = &str;

	string_view str1{ str };	// Fine!

}