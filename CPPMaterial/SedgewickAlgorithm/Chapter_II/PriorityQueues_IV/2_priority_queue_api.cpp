/**
* We shall use delMax() for removing the maximum element, and insert() for adding a new element.
* With implementation, we can add constructors that get an array, specify size of pq, or an empty constructor.
*/
#include <initializer_list>
using namespace std;
template <typename T>
class priority_queue {
	virtual T delMax() = 0;
	virtual void insert(T item) = 0;
	virtual int size() = 0;
	virtual bool empty() = 0;
	virtual T max() = 0;
	virtual ~priority_queue() = 0;
};


template <typename T>
class MaxPQ : priority_queue<T> {
	MaxPQ() {}
	MaxPQ(int size){}
	MaxPQ(initializer_list<T> list){}
};