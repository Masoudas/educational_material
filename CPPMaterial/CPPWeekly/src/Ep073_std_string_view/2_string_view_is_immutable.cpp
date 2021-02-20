/**
* An string_view class has the property that it's immutable. Now, because this class is immutable,
* it gets as close to const char* as possible (just a thin wrapper around it), and it doesn't have the
* buffer a normal string uses. Therefore, it's a better choice for speed and optimization. The problem with
* it however is that it's immutable, and we can't modify it in place.
* 
* It's in the string_view header. 
* 
* The structure of the string_view is like string, in that there's a basic_string_view class, and string_view
* is just an alias for basic_string<char>, and then there's wstring_view, u16string_view, etc.
* 
* It's important to note that the iterator returns a const string, because we can't change the content of a 
* string_view. In other words, begin() is equal to cbegin().
* 
* Also note that like a basic string, it has the char_traits, for manipulation as template.
* 
* Also, note that string_view is constexpr, whereas a normal string isn't (given that we can change its content).
*/

#include <string_view>

using std::string_view;

void working_with_string_view() {
	string_view str = "My immutable string";

	// str[0] = w; Error! Can't change the content of string_view

	// str.data() Pointer to underlying cstyle string
	auto begin = str.begin();	// This is equivalent to cbegin()
	// *begin = 'c'; Error! constant string
	
	// str.insert() There's no insert method
	string_view str1 = str.substr(0, 2);	// Returns a new string view! Note no reference 
											// at the end of the return value.
											// Also, no return would have implied in place change.

}

void string_view_is_constexpr() {
	constexpr string_view str = "Yo!";

	//constexpr std::string str = "Yo!";
}