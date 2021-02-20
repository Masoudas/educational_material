/**
* To implement IndexMinPQ according to exercise 33, we use three arrays:
* 1-	pq: Holds the indexes.
* 2-	keys: Holds the keys corresponding to each index.
* 3-	qp: It's the inverse of pq. Hence, the positions correspond to indexes, and the values are the
*	locations in the binary heap. We use the convention that qp[i] = -1 if an index is not on the tree.
* 
* The contains method now uses qp to test whether an index is on the tree or not. The sink and swim methods
* will remain the same.
* 
* We assume that the index starts from 0, and not from 1.
* 
* Question: Why do we need the inverse? Essentially, for the delete_item function. If we hadn't used the delete,
* we would have needed to search for the index inside the pq array.
*/
#include <array>
#include <string>
#include <iostream>
using namespace std;

template <typename T, int SIZE>
class IndexMaxPQ {
	int N = 0;
	array<T, SIZE> keys{};
	array<int, SIZE + 1> pq{};
	array<int, SIZE> qp{-1};

	void sink(int k) noexcept {
		while (2 * k <= N)
		{
			int j = 2 * k;
			if (j < N && less(j, j + 1)) j++;
			if (!less(k, j)) break;
			swap_elems(k, j);
			k = j;
		}
	}

	void swim(int k) noexcept {
		while (k > 1 && less(k/2, k)) {
			swap_elems(k / 2, k);
			k = k / 2;
		}
	}

	bool less(int i, int j) {
		return keys[pq[i]] < keys[pq[j]];
	}

	void swap_elems(int i, int j) {
		int index1 = pq[i];
		int index2 = pq[j];

		qp[index1] = j;
		qp[index2] = i;

		pq[i] = index2;
		pq[j] = index1;
	}

public:
	IndexMaxPQ() {
		fill(&qp[0], &qp[SIZE-1] + 1, -1);	// Setting array initial values to -1.
	}
	IndexMaxPQ(const IndexMaxPQ& ref) = delete;
	IndexMaxPQ(IndexMaxPQ&& ref) = delete;

	bool contains(int k) {
		if (k >= SIZE) throw "Yo man!";
		return qp[k] != -1;
	}

	void insert(int k, T&& item) {
		if (k > SIZE || (N == SIZE) || qp[k] != -1) throw "Yo man!";
		++N;

		keys[k] = item;
		qp[k] = N;
		pq[N] = k;

		swim(N);
	}

	void change(int k, T&& item) {
		if (k > SIZE) throw "Yo man!";
		keys[k] = item;	// The key is completely replaced with a new key.

		swim(k);
		sink(k);
	}

	T max() noexcept {
		return keys[pq[1]];
	}

	int index_max() {
		return pq[1];
	}

	void delMax() {
		int index = pq[1];

		qp[index] = -1;
		// How do we delete the T object here? We can't!. Its memory location is preserved!
		// Unless we use pointers to objects in our vector.
		int index_N = pq[N--];
		pq[1] = index_N;
		qp[index_N] = 1;

		sink(1);
	}

	void delete_item(int k) {
		int node = qp[k];
		qp[k] = -1;

		int index_N = pq[N];
		pq[node] = index_N;
		qp[index_N] = node;

		N--;
		sink(node);
		swim(node);

		
	}
};


void test_contains() {
	IndexMaxPQ<string, 3> pq{};

	pq.insert(0, "A");
	pq.insert(1, "C");
	pq.insert(2, "B");

	cout << "Checking if contains all three" << '\n';
	for (int i = 0; i < 3; i++) {
		bool contains = pq.contains(i);
		cout << contains << '\t';
	}
	cout << '\n';
}

void test_delMin() {
	IndexMaxPQ<string, 3> pq{};

	pq.insert(0, "A");
	pq.insert(1, "C");
	pq.insert(2, "B");

	cout << "Printing queue in order" << '\n';
	for (int i = 0; i < 3; i++) {
		string max = pq.max();
		cout << max << '\t';

		pq.delMax();
	}
	cout << '\n';

}

void test_delete_item(){
	IndexMaxPQ<string, 4> pq{};

	pq.insert(0, "A");
	pq.insert(1, "B");
	pq.insert(2, "C");
	pq.insert(3, "D");

	pq.delete_item(2);

	cout << "Printing queue in order after deleting second index (or C):" << '\n';
	for (int i = 0; i < 3; i++) {
		string max = pq.max();
		cout << max << '\t';

		pq.delMax();
	}
	cout << '\n';
}

void test_change_index() {
	IndexMaxPQ<string, 4> pq{};

	pq.insert(0, "A");
	pq.insert(1, "B");
	pq.insert(2, "C");
	pq.insert(3, "D");

	pq.change(2, "F");

	cout << "Printing queue after changing index 2 to F:" << '\n';
	for (int i = 0; i < 4; i++) {
		string max = pq.max();
		int index = pq.index_max();
		cout << "(" << index << "," << max << ")" << '\t';

		pq.delMax();
	}
	cout << '\n';
}

//
//int main() {
//	test_contains();
//	test_delMin();
//	test_delete_item();
//	test_change_index();
//}