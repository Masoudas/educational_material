/* 
* Considering we know how reheapification works, the problem of removing max node or 
* insertion can be solved as follows
* 
* 1- Insertion: Put the node in the first empty child node available (too which we keep an index),
*	then swim that node.
* 
* 2- Deletion: First remove node 1 of the list. Now, place the last node of the in the first, and then
* start sinking that node (I never would have guessed that). Why would this work? Because naturally
* everytime we sink a node, the higher order nodes are ordered.
* 
* Assuming all of this, we try and implement such a heap, using a heap interface.
* 
* Implementation point I: Note that the insert method asks for a copy of key, not a reference to key.
* This way, the queue does not keep a copy of elements inside. Hence, queue elements are independent from the
* outside.
* 
* Implementation point II: How do we create a constructor which accepts several keys? Well, we can use the insert
* method repeatedly.
* 
* Implementation point III: Should the data structure be constexpr? Nope, because the whole purpose of pq is to
* remove the max from the top, rendering compile-time constancy moot!
* 
* Implementation point IV: The comparison method is defined as a template. Note that we don't demand an instance
* at construction, just to ponder the effects of such move (as opposed to demanding an instance during construction)
*/
#include <string>
#include <iostream>
#include <array>
using namespace std;

template <typename T>
class priority_queue {
public:
	virtual void insert(T key) = 0;	// The interface is not responsible for deleting objects! Get reference.
	virtual T delMax() = 0; // The interface is not responsible for deleting objects.
	virtual int size() = 0;
	virtual bool isEmpty() = 0;
	 
};

// Don't forget that nodes start from index 1 and not 0 of the pq vector, to make parent finding simpler.
template <typename T, int SIZE_PQ, typename COMP = std::less<T>>
class MaxPQ : public priority_queue<T> {
	array<T, SIZE_PQ + 1> pq;
	int N = 0;
	COMP isLess = COMP{};
public:
	constexpr MaxPQ() : pq(array<T, SIZE_PQ + 1>{}) {}

	MaxPQ(initializer_list<T> keys) {
		if (keys.size() > SIZE_PQ) throw "Yo man!";
		pq = array<T, SIZE_PQ + 1>{};

		N = keys.size();
		for (auto key : keys) insert(key);
	}

	void insert(T key) override {
		if (SIZE_PQ == size()) throw "Yo man";
		pq[++N] = key;
		swim(N);
	};


	T delMax() override {
		if (isEmpty()) throw "Yo man!";

		T max = move(pq[1]); 
		swap_nodes(1, N--);
		sink(1);

		return max;
	};
	
	int size() override { return N; }
	
	[[NoDiscard]] bool isEmpty() override { return N == 0; }

private:
	void sink(int k) {
		while (2 * k <= N) {
			int i = k * 2;
			if (i < N && isLess(pq[i], pq[i + 1])) i++;
			if (isLess(pq[i], pq[k])) break;
			swap_nodes(k, i);
			k = i;
		}
	}

	void swim(int k) {
		while (k > 1 && isLess(pq[k >> 1], pq[k]))
		{
			swap_nodes(k, k >> 1);
			k = k >> 1;
		}
	}

	void swap_nodes(int i1, int i2) {
		T temp = move(pq[i1]);
		pq[i1] = move(pq[i2]);
		pq[i2] = move(temp);
	}
};

//int main() {
//	MaxPQ<string, 3> max_pq{};
//	
//
//	for (string str = ""; getline(cin, str, '\n') && str.length() != 0;) {
//		if (max_pq.size() == 3) max_pq.delMax();
//		max_pq.insert(str);
//	}
//
//	cout << "Printing the smallest elements in order: \n";
//	for (int i = 0; i++ < 3;) {
//		string min = max_pq.delMax();
//		cout << min << '\t';
//	}
//}