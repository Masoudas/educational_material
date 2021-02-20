/**
* Question is, can we search for a key inside a map? How about a value? How about a key value pair?
* 
* The map allows us to directly look for a key, which is to be expected. However, there's no corresponding method
* for finding a value. Therefore, finding a value (as it should be) a linear algorithm, and there can be duplicates
* as well.
* 
* find_if is a good solution for finding a value.
*/
#include <string>
#include <unordered_map>
#include <algorithm>

using std::unordered_map;
using std::string;

void contains_a_key() {
	std::unordered_map<string, int> m{};

	m.contains("key");
}

void find_value() {
	std::unordered_map<string, int> m{};
	
	std::find_if(m.cbegin(), m.cend(), [](const auto& pair) { return pair.second == 5; });
}