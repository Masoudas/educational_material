/**
* As it interests me, I shall implement a resizable priority queue. 
* 
* The only thing we need to do however is to use a vector rather than array. When vector size increases,
* everything is taken care of by the vector. When removing a node, again because we move the last element
* of the underlying vector, the vector size shrinks.
* 
* Point of interest: vector increases size when we insert elements, and we insert elements using the 
* bracket operator of vector.
* 
* Note that the vector keeps the size of the pq as well. The problem with this implementation is that we 
* have to move the entire array once an element is deleted, making the cost of deletion O(n), which is not
* good at all! 
* 
* Another very interesting issue of this implementation is that to ensure that the elements start from 1,
* we construct and empty object at the first element. Note that we prefer not to keep pointers, because
* that would slow down the priority queue. So now, we impose another condition on the user, they have to
* supply objects that have default constructors, which is not good! Is there any way to circumvent this?
* The only solution I can think of, is to copy the first inserted method into first location, but that
* would imply making the insert method ugly too, by addition of a check constraint!
* 
* Finally, note how ugly the delete method has become. Especially, we have to check for the sink method
* to ensure that sinking happens only when we have at least one node!
*/
#include <string>
#include <vector>
#include <iostream>

template<typename T, typename LESS = std::less<T>>
class MaxPQ {
	std::vector<T> pq{T{}};	// Initialize with at least one space, allowing indexing to start from 1.
	LESS isLess = LESS{};
public:
	MaxPQ(std::initializer_list<T> keys) {
		for (auto key : keys) insert(key);
	}

	void insert(T key) {
		pq.emplace_back(key);
		swim(pq.size() - 1);
	};

	T delMax() {
		if (isEmpty()) throw "Yo man, queue is empty!";

		T max = std::move(pq[1]);

		std::swap(pq[1], pq[pq.size() - 1]);
		pq.pop_back();

		if (!isEmpty()) sink(1);

		return max;
	};

	int size() { return pq.size() - 1; }

	[[NoDiscard]] bool isEmpty() { return pq.size() == 1; }

private:
	void sink(int k) {
		while (2 * k <= size()) {
			int i = k * 2;
			if (i < size() && isLess(pq[i], pq[i + 1])) i++;
			if (isLess(pq[i], pq[k])) break;
			std::swap(pq[k], pq[i]);
			k = i;
		}
	}

	void swim(int k) {
		while (k > 1 && isLess(pq[k >> 1], pq[k]))
		{
			std::swap(pq[k], pq[k >> 1]);
			k = k >> 1;
		}
	}
};

//int main() {
//	using std::string;
//	MaxPQ<string> max_pq{};
//	
//
//	for (string str = ""; std::getline(std::cin, str, '\n') && str.length() != 0;) {
//		if (max_pq.size() == 4) max_pq.delMax();
//		max_pq.insert(str);
//	}
//
//	std::cout << "Printing the smallest " << max_pq.size() << " elements in order: \n";
//	for (int i = 0; i++ < 4;) {
//		string min = max_pq.delMax();
//		std::cout << min << '\t';
//	}
//}