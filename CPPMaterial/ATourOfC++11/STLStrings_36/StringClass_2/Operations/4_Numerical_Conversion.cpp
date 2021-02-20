/*
* There are operations to derive equivalent numerical values from a string. These would only work with string and
* wstring forms of base_string.
* 
* The methods are named sto*, like string to int (stoi), string to double (stod).
* 
* x = stoi(s,p,b)				:			reads s as integer x, starting from s[0]. if p!=nullptr, ∗p is set to how many chars
*											were used from s to form x; b is the base of the number (between 2 and 36, inclusive)
* y = stol(s,p,b)				:			string to long.
* z = stoul(s,p,b)				:			string to unsigned long.
* x = stoll(s,p,b)				:			String to long long
* x = stoull(s,p,b)				:			String to unsigned long long
* x = stof(s,p)					:			String to float
* x = stod(s,p)					:			String to double
* x = stold(s,p)				:			String to long double
* 
* Bjarne says he prefers string_stream interface over these methods for string to value conversions.
* 
* Also note that initial white spaces are skipped.
* 
* If a conversion function doesn’t find characters in its string argument that it 
* can convert to a number, it throws invalid_argument.
* 
* The sto∗ functions encode their target type in their names. This makes them unsuitable for generic
* code where the target can be a template parameter. In such cases, consider to<X> (§25.2.5.1).
*/

#include <string>
#include <iostream>
using namespace std;

int convert_string_to_value() {
	string s{ "12345.54321" };
	size_t size = 0;
	int x = stoi(s, &size);
	cout << "Equivalent integer value is: " << x << " and stoi used: " << size << " from string s";

	return 0;
}