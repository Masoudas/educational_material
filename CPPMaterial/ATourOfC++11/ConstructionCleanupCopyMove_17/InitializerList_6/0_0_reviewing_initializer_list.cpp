/**
* As we recall, initializer list provides access to underlying elemens in a constant
* manner, meaning they can be read, but not written. So for example, there's no move assignment
* or constructor associated with them.
* 
* Note that initializer list does not allow direct indexing using [].
*
*/
#include <initializer_list>
#include <iostream>
using namespace std;

void init_list_function(initializer_list<int> args) {
	int* arr = new int[args.size()];
	
	// args[i] is not allowed.

	int i = 0;
	for (auto var : args)
	{
		*(arr + i) = var;
	}

	for (auto begin = args.begin(), end = args.end(); begin < end; begin++)
	{
		cout << *begin;
	}
}

