/**
* One issue we have with the previous implementation of PQ is that random access to elements was
* impossible. We could resolve this by allowing indexing to the elements, i.e, letting the user of the API
* assign index to elements. Another advantage of this situation is that now we can delete from the middle of
* the pq as well, rather than just deleting the top node.
* 
* The API of such a list is given below. The change method is a very challenging method to implement. 
* A client is also given below.
* 
* To implement such a list, two solutions come to mind:
* 1-	We can create a node class, which holds the index to the item, together with the item. This solution
*	is slow when it comes to removing objects.
* 2-	Create an auxiliary list that holds items in an array. In the tree, use indexes instead of items.
* 3-	A third method which involves an inverse array, based on exercise 33, which is discussed in the 
*	implementation 5_6_2.
*
*/
#include <string>
#include <iostream>
using namespace std;

template<typename T>
class IndexMinPQ {
public:
	//IndexMinPQ(int maxN); All elements will have index between [0 maxN-1]
	virtual void insert(int k, T item) = 0;
	virtual void change(int k, T item) = 0;	// Change the item associated with k.
	virtual bool contains(int k) = 0;	// Whether it has the given index.
	virtual void delete_item(int k) = 0;	// Delete an item associated with this index.
	virtual T min() = 0;	// Peak minimum item.
	virtual int minIndex() = 0;	// Return the index of the minimal item.
	virtual int delMin() = 0;	// Delete the minimum item and return its index.
	virtual bool isEmpty() = 0;
	virtual int size() = 0;
};
