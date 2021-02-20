/**
* Unordered map is essentially like an unordered set, with the difference being that we have a key value relation
* here. Hence, the location of each value corresponds to the location of hash value key, where the implication here
* is that two separate memory locations are used for storing both keys and values (and not just saving the value
* in the location indicated by key's hash value).
* 
* A major difference between a map and a set is that a map has a bracket operator, allowing it to be indexed by the
* key values. Note that bracket as always returns by reference, so modifying it changes the value, which is not a
* problem regarding the integrity of the hash table.
* 
* Aha! Very important note: If a key does not exist, because the bracket operator returns a reference, and it
* doesn't want to throw an exception, it will create a default value. Hence, if the class doesn't have an empty
* constructor, we can't create a map for it! Interestingly enough, we don't get this error until we access a 
* non-existent element. We may wonder why not check default constructible at compile time? The answer probably
* is that the library allows us to create such a map, so long as we're certain we ensure that such a case doesn't
* happen.
* 
* Note that as we already know, operations such as find are much faster here.
*/
#include <unordered_map>
#include <string>
#include <iostream>

struct non_default{
	non_default(int){}
};

void constructing_and_iterating_over_map() {
	using std::string;
	using map = std::unordered_map<string, int>;

	map m1{ };	// Recall that there's no initializer list constructor.
	m1.emplace("v1", 1); m1.emplace("v2", 2); m1.emplace("v3", 3);

	// Structured binding with automatic rvalue reference deduction.
	for (auto&& [key, value] : m1) {
		std::cout << "Key is: " << key << " and value is: " << value << '\n';
	}

	std::cout << m1["v4"] << '\n';	// No error! returns 0 here.
}

void no_map_for_classes_with_non_default_constructed_classes() {
	std::unordered_map<int, non_default> m2{}; //Error! no such map is possible! But no such error is thrown yet!

	//m2[1] = { 5 }; Here's where we get the error!
}

//int main() {
//	no_map_for_classes_with_non_default_constructed_classes();
//}

