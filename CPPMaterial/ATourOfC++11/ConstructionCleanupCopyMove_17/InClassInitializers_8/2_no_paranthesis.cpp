/**
* For pretty obscure reasons, we can use = or {} for initialization inside a class, but not the () notion.
*/

#include <vector>

using namespace std;

struct my_struct
{
	vector<int> k{ 1, 2, 3 };
	vector<int> j = { 1, 2, 3 };
	// vector<int> i(10);	This can't be used!
};