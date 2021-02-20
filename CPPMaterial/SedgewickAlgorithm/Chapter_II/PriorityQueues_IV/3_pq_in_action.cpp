/**
* Imagine we have an stream of N data, and we want to find the smallest or largest M values among them.
* 
* One choice would be to wait for all the data, and then sort. This would take space N, and complexity
* average of NlogN.
* 
* With a priority queue, the space will decrease to M. 
* 
* Now, one option is to sort M, then compare each new key against the set. This however could be costly, because
* of the cost of comparison and replacement. 
*
* With a MinPQ (and not a maxPX) however, we can under efficient implementation remove the smallest key everytime
* and then in the end, we'd have the keys that have been consistenly the smallest.
*/
#include <iostream>
#include <string>
using namespace std;

template <typename T>
class priority_queue {
public:
	virtual T delMin() = 0;
	virtual void insert(T item) = 0;
	virtual int size() = 0;
};

/**
* Only the largest keys remain.
*/
void find_largest_items(int M) {
	priority_queue<string> *minPQ = nullptr;

	for (string str = "" ; getline(cin, str, '\n') && str.length() != 0;) {
		if (minPQ->size() == M) minPQ->delMin();	// With some stipulation!
		minPQ->insert(str);
	}
}
