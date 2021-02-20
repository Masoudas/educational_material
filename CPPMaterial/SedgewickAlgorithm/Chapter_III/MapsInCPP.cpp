/**
* maps are pairs of key and value. They are associated containers. Two values shall not have the same key.
* 
* We need to use std::pair to insert values inside the map, using the insert method.
* We can also use the bracket operator to set the (key,value) pair. The key need not already exist.
* 
* If a replicate key is placed inside the map, it is ignored by the map!
* map.insert(std::pair<int,char>{1,'A'})
* map.insert(std::pair<int,char>{1,'B'}) // This is ignored by the map. we need to use insert_or_assign();
*/
#include <map>
#include <iostream>
using namespace std;

void inserting_values_in_map() {
	map<int, char> mp{};

	mp[0] = 'A';
	mp[-1] = 'z';

	mp.insert(pair<int, char>{1, 'B'});

	cout << mp[-1] << " " << mp[0] << " " << mp[1] << endl;
}

void insert_ignores_repeated_keys() {
	map<int, char> mp{};
	mp.insert(pair<int, char>(1, 'A'));
	mp.insert(pair<int, char>(1, 'B'));

	map<int, char>::iterator itr = mp.begin();
	for (; itr != mp.end(); itr++)
	{
		cout << itr->first << " " << itr->second << endl;
	}

	cout << "Map did not accept a pair with a duplicate key." << endl;

	mp.insert_or_assign(1, 'B');
	cout << "Using insert or assign changes the value: " << mp[1];
}

void set_value_of_existing_key() {
	map<int, char> mp{};
	mp.insert(pair<int, char>(1, 'A'));

	mp[1] = 'B';

	cout << "Changing value at key [1]: " << mp[2] << endl;
}

void replicating_an_existing_map() {
	map<int, char> mp{};
	mp[1] = 'A';
	mp[2] = 'B';

	map<int, char> mp_rep{ mp.begin(), mp.end() };	// Use the iterator of the other map in the constructor.
	map<int, char>::iterator itr = mp.begin();
	for (; itr != mp.end(); itr++)
	{
		cout << itr->first << " " << itr->second << endl;
	}
}

void removing_a_key_from_map() {
	map<int, char> mp{};
	mp[1] = 'A';
	mp[2] = 'B';
	mp[3] = 'C';
	mp[4] = 'D';
	mp[-1] = 'z';

	mp.erase(1);

	mp.erase(mp.begin(), mp.find(3));	// What is this one good for? This one removes all the keys that are below this element.

	map<int, char>::iterator itr = mp.begin();
	for (; itr != mp.end(); itr++)
	{
		cout << itr->first << " " << itr->second << endl;
	}
}

//int main() {
	//map_ignored_repeated_keys();
	//insert_ignores_repeated_keys();
	//set_value_of_existing_key();
	//replicating_an_existing_map();
	//removing_a_key_from_map();
//}