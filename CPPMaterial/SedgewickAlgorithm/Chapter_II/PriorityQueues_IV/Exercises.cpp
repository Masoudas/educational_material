#include <queue>
#include <iostream>
#include <vector>
#include <list>
#include <tuple>
struct One {
	/**
	* A couple of points should be noted as we do this exercise:
	* 1- A priority queue can be modeled as a queue, with the difference being that elements that are larger
	*	relative to other elements are closer to the top. Regardless of the internal structure of PQ, we're 
	*	certain that P comes out faster than O. Hence, externally we show [ ... O ... P ... ], even though
	*	internally we might have [ ... P ... O ... ]
	* 
	* 2- A priority queue is not an stable queue (or sort algorithm), in the sense that when we insert two
	* elements of the same type, there's no way for us to know which one comes out. Imagine O->P->P. Now, which
	* P comes first depends on the internal structure of the PQ.
	* 
	* In what follows, the bracket represents the queue abstraction of PQ, not its internal representation.
	*/
	/**
	* P R I O -> [R P O I]
	* * -> R : [P O I]
	* R -> [R P O I]
	* * * -> R P : [O I]
	* I -> [O I I]
	* * -> O : [I I]
	* T -> [T I I]
	* * -> T : [I I]
	* Y -> [Y I I]
	* * * * -> Y I I []
	* Q U E -> [U Q E]
	* * * * -> U Q E []
	* U -> [U]
	* * -> U : []
	* E -> [E]
	* 
	* The output is [R R P O T Y I I U Q E U]
	* 	
	P R I O* R** I* T* Y*** Q U E***
		U* E
	*/

	static void checking_with_stl_pq() {
		std::queue<char> pq_output{};

		std::priority_queue<char> pq{};	// Comparator by default is less(), meaning top node is max.
		pq.emplace('P'); pq.emplace('R'); pq.emplace('I'); pq.emplace('O');

		pq_output.push(pq.top());	pq.pop();	// Notice that top returns a const reference to element.
												// We need to pop after!
		pq.emplace('R');

		pq_output.push(pq.top());	pq.pop();
		pq_output.push(pq.top());	pq.pop();

		pq.emplace('I');
		pq_output.push(pq.top());	pq.pop();

		pq.emplace('T');
		pq_output.push(pq.top());	pq.pop();

		pq.emplace('Y');
		pq_output.push(pq.top());	pq.pop();
		pq_output.push(pq.top());	pq.pop();
		pq_output.push(pq.top());	pq.pop();

		pq.emplace('Q'); pq.emplace('U'); pq.emplace('E');

		pq_output.push(pq.top());	pq.pop();
		pq_output.push(pq.top());	pq.pop();
		pq_output.push(pq.top());	pq.pop();

		pq.emplace('U');
		pq_output.push(pq.top());	pq.pop();

		pq.emplace('E');

		std::initializer_list<char> l{ 'R', 'R', 'P', 'O', 'T', 'Y', 'I', 'I', 'U', 'Q', 'E', 'U' };

		bool all_equal = true;
		for (auto begin = l.begin(); all_equal && (begin != l.end()); begin++) {
			all_equal = (*begin) == pq_output.front();
			pq_output.pop();
		}

		if (all_equal) std::cout << "Priority queue result equals expectation";
	}

};

struct Two {
	/**
	* There are a couple of issues. Suppose we have a stack or queue that keeps all the elements. And suppose we
	* return the maximum value of it. Question is, do we keep the value separately from the stack? Or we have
	* to reach the middle of the stack and remove it, which puts a heavy computational burden. On the other
	* hand, what happens to the rest of the elements. Do we need to calculate the maximum one more time, hence
	* everytime introduce an O(n) computational burden.
	*/
};

struct Three {
	/**
	* Clearly list structures are better here, because popping an element does not force them to redefine
	* the underlying data structure. In particular, ordered list is better than lazy list, given that we
	* don't have to search the entire array every time.
	*/
	struct ordered_array {
		std::vector<int> pq{};

		void insert(int v) {
			auto begin = pq.begin();
			while (begin != pq.end() && (*begin) > v) begin++;

			pq.insert(begin, v); // Interesting to note that for the empty case, this is handled properly.
		}

		int remove() {
			int max = pq.front();	// Data return methods never pop!
			pq.erase(pq.begin());

			return max;
		}

		static void test() {
			Three::test(ordered_array{});
		}

	};

	struct lazy_array {
		std::vector<int> pq{};

		void insert(int n) {
			pq.push_back(n);
		}

		int remove() {
			auto pos = std::max_element(pq.begin(), pq.end());

			int max = *pos;
			pq.erase(pos);

			return max;
		}

		static void test() {
			Three::test(lazy_array{});
		}
	};

	struct ordered_list {
		std::list<int> pq{};

		void insert(int v) {
			auto begin = pq.begin();
			while (begin != pq.end() && (*begin) > v) begin++;

			pq.insert(begin, v);
		}

		int remove() {
			int max = pq.front();
			pq.pop_front();
			return max;
		}

		static void test() {
			Three::test(ordered_list{});
		}
	};

	struct lazy_list {
		std::list<int> pq{};

		void insert(int n) {
			pq.push_front(n);	// No diff if we used push back!
		}

		int remove() {
			auto pos = std::max_element(pq.begin(), pq.end());

			int max = *pos;
			pq.erase(pos);

			return max;
		}

		static void test() {
			Three::test(lazy_list{});
		}
	};

private:
	template<typename T>
	static void test(T t) {
		T o{};
		o.insert(1); o.insert(2); o.insert(3);

		int max = o.remove(); int max_1 = o.remove(); int max_2 = o.remove();
		std::cout << max << '\t' << max_1 << '\t' << max_2 << '\n';
	}
};

struct Four {
	/**
	* Given that for each index m we have that a[m] <= a[m/2], yes.
	*/
};

struct Five {
	/**
	* When we put the second S, we have [ - Y S U A Q E S]. Then after addition of new elements, we get
	* [ - Y T U S Q E S A I O N].
	*/
};

struct Six {
	/**
	* P R I O * R * * I * T * Y * * * Q U E * * * U * E
	* 
	* P R I O -> [- R P I O]
	* * -> R : [- O P I]
	* R -> [- R O I P ]
	* * -> R : [ - P O I]
	* ...
	*/
};

struct Seven {
	/**
	*
	*/
};

struct Eight {

};

struct Nine {
	/**
	* Given that E has to be the top node, and that D has to always be a child, then we have few options left
	* afterward.
	* 
	* [E D A B C] or variation of B and C
	* [E D B A C] or variation of A and C
	* [E D C A B] or variation of A and B
	* 
	* For keys A A A B B, we have:
	* [B B A A A]
	* [B A B A A]
	*/
};

struct Ten {
	/**
	* Note that in this case, the parent node is at 0, and its children are at 1 and 2. Hence, we see that the
	* children of node k are at 2(k+1) and 2(k+1) + 1. Similarly, the parent of a node k is at floor(k/2).
	*/
};

struct Eleven {
	/**
	* Unordered array. An ordered array would sort the array every time, and the heap requires sinking an sorting.
	* Consequently, unordered array is the best choice, as insertion is of order O(1).
	*/
};

struct Twelve {
	/**
	* A heap requires O(1) for finding the max, but so does an ordered array. However, when it comes to deletion,
	* a heap has a bettern performance, and ordered array possibly requires reallocation. So, we go with heap. 
	*/
};

template<typename T>
struct Thirteen {
	/**
	* The issue that we should worry about is ensuring that the if a node in the last level of the heap hierarchies
	* has only one root, the loop stops, and we compare it separately. We do this by eliminating
	*/ 
	T pq[];
	int n = sizeof pq / sizeof(T);	// Ok ...

	void sink(int k) {
		while ((2 * k) + 1 < n) {
			int i = 2 * k;
			if (pq[i] < pq[i + 1]) i++;
			if (pq[k] > pq[i]) break;	// If we didn't put the break here, we'd get over children unnecessarily!
			swap(pq[k], pq[i]);
			k = i;
		}

		/*if (k == n - 1 && pq[n-1] < pq[k]) { // If this is indeed the nth element of the array.
			swap(pq[k], pq[n-1]);
		}*/
	}
};

struct Fourteen {
	/**
	* The minimum number of exchanges for removing the maximum element is two. In particular, if the first floor(N/2)
	* elements are the children of the second largest elements, and the floor(N/2) + 1 smallest element is at the
	* Nth location of the heap, then we only require one operation. So one for exchanging N with 1 and one for the
	* next exchange.
	* 
	* Now assume N = 15.
	* 
	* Now, if we remove the the max here, then to remove the next max element we require three new exchanges for the
	* new removal. This is because the third largest key is now at the second level, and only the fourth largest
	* key is smaller than it. However, we can't put it at the N-1 location. However, we can put the fifth largest
	* element there. Hence, we require two exchanges plus one exchange for the original exchange.
	* 
	* For the third removal, we again need at least three exchanges, with the same argument.
	*/
};

struct Fifteen {
	/**
	* For the sake of argument let's assume that the array has n+1 elements, rather than n elements. The test
	* would be to compare element k with k/2 and check whether it's smaller.
	* 
	* Note that the templated implementation below assumes that we're using a contiguous memory, so that we can
	* actually calculate the distance between two iterators.
	* 
	* This implementation says that for an empty array, the array is heap oriented, because if there exist a child
	* note, it should be greater than the parent!
	* 
	*/
	template<typename T>
	static bool is_heap(T begin, T end) {
		int N = std::distance(begin, end);	// Don't forget that this the number of elements, because we calculate
											// till end. Just reminding this!
		for (int i = N - 1; i > 1; i--) {
			if (begin + i > begin + i >> 2) return false;
		}
		
		return true;
	}
};

struct Eighteen {
	/**
	* The answer to the first question is yes. After removal of the largest element, then the first child node
	* has to go back to its original location, and its child has to go back to its original location and so forth.
	* So the tree returns to its original shape.
	* 
	* For higher orders, we can argue in an inductive manner. If we insert two elements and remove the max, then 
	* the queue is the same as when we entered one element. If we remove that one as well, then we get the original
	* queue.
	*/
};

struct Nineteen {
	/**
	* Note that the first element of each level of a tree starts with 1, 2, 4, 8, ..., or if we count from 0, then
	* 0, 1, 3, 7, ... . Also note that this number is equivalent to 2^logn - 1. Consequently, we first skip that 
	* many elements, and starting from the (2^logn - 2)th element, we sink.
	* 
	* Note that the start calculation is in fact unnecessary, because the sink operation checks for whether or not
	* there's an element to swap the current element with.
	*/
	template<typename _Itr>
	static void heapify(_Itr begin, _Itr end) {
		size_t N = std::distance(begin, end);

		size_t start = std::pow(2, std::log2(N)) - 2;
		for (int i = start; i >= 0; i--) {
			sink(begin, i, N);
		}
	}

	static void test() {
		int arr[] = { 3, 4, 1, 2 };
		Nineteen::heapify(arr, arr + 4);
		for (int i = 0; i < sizeof(arr) / sizeof(int); i++) {
			std::cout << arr[i] << '\t';
		}
	}
private:
	template<typename _Itr>
	static void sink(_Itr begin, size_t index, size_t N) {
		while (2 * index + 1 < N) {
			int j = 2 * index + 1;
			if (j + 1 < N && *(begin + j + 1) > *(begin + j)) j++;

			if (*(begin + j) < *(begin + index)) break;
			std::swap(*(begin + index), *(begin + j));

			index = j;
		}
	}
};

struct TwentyOne {
	/**
	* So, One solution would be to wrap the data in an index class, which holds the index of element, together with
	* an auxiliary variable containing the number of elements so far. A MaxPQ can be used for stack and a MinPQ for
	* queue. For the stack, the index value is equal to auxiliary variable. For queue, note that we remove from 
	* index 1, but because we can't reindex, the auxiliary variable is the number of elements put in the queue thus 
	* far. For a random bag, we just randomly index the elements.
	* 
	* If we wanted however, we can mix the data structure to get the benefits of both queue and pq or stack and pq.
	* For this end, we'd just need an indexed pq together with an auxiliary counter. 
	* 
	* Say we wanted an stack priority_queue.  Now, if the user gets the max of pq for example, it's Ok. But for pop,
	* we must check the element corresponding to the auxiliary exist (meaning we need to implement a loop for it).
	* For a queue, we'd have to let the auxiliary variable increase. The loop here would be the reverse of the above,
	* and we'd start from 0 and stop when we see the element. Of course, if we had the freedom to implement the queue 
	* inside, a simple reindexing would go a long way here!
	*/
};

struct TwentyTwo {
	/**
	* To resize the array, we use the strategy that if half the elements of the array are full, we double the 
	* size of the array, and if less than half the array is full, we half the size.
	* 
	* We must not forget that pq has first element empty.
	*/
	int N;
	int size;

private:
	int* pq;	

	void _expand_array() {
		if (N >= size / 2) {
			size *= 2;
			int* pq_old = pq;

			pq = new int[size];
			std::copy(pq_old, pq_old + N + 1, pq);

			delete[] pq_old;
		}
	}

	void _shrink_array() {
		if (N < size / 2) {
			size /= 2;
			int* pq_old = pq;

			pq = new int[size];
			std::copy(pq_old, pq_old + N + 1, pq);

			delete[] pq_old;
		}
	}

	void swim(int index) {
		while ((index >> 1) > 0) {
			if (pq[index] < pq[index >> 1]) break;
			std::swap(pq[index], pq[index >> 1]);

			index = index >> 1;
		}
	}

	void sink(int index) {
		while ((index << 1) < N) {
			int j = index << 1;

			if (j + 1 < N && pq[j] < pq[j + 1]) j++;
			if (pq[j] < pq[index]) break;

			std::swap(pq[j], pq[index]);

			index = j;
		}
	}

public:
	TwentyTwo() : N{ 0 }, size{ 1 + 1 }, pq{ new int[size] {} } {}

	void insert(int key) {
		N++;
		_expand_array();

		pq[N] = key;
		swim(N);
	}

	int delete_max() {
		int max = pq[1];

		pq[1] = pq[N--];
		if (N > 0) sink(1);

		_shrink_array();

		return max;
	}

	~TwentyTwo() {
		delete[] pq;
	}

	static void test() {
		TwentyTwo maxPQ{};

		maxPQ.insert(1);
		_print_add(maxPQ);

		maxPQ.insert(2);
		_print_add(maxPQ);

		maxPQ.delete_max();
		_print_remove(maxPQ);

		maxPQ.delete_max();
		_print_remove(maxPQ);
	}

	static void _print_add(const TwentyTwo& pq) {
		std::cout << "After inserting an element, num elements is " << pq.N << ", and size of array is: " 
			<< pq.size << '\n';
	}

	static void _print_remove(const TwentyTwo& pq) {
		std::cout << "After removing an element, num elements is " << pq.N << ", and size of array is: " 
			<< pq.size << '\n';
	}
};

struct TwentyFour {
	/**
	* As we already guessed, if we want to implement a pq as a binary tree, we need a structure that keeps the
	* path to the parent node as well.
	* 
	* In this implementation, we always have the parent node, but it may or may not contain valid data.
	* 
	* To find a particular node, we implement a recursive find method that finds a node based on its index. The
	* idea here is that if we divide the index by two, we get the parent of that node, and dividing that by two,
	* we get its parent. The number of possible divisions equals the depth of the point, and dividing it by the
	* depth gives us back the root node.
	* 
	* See also TwentyFour_A.
	*/
private:
	struct node {
		int data;
		node* parent;
		node* left;
		node* right;
	};

	int N;
	node* root;

	void sink(node* nd) {
		while (nd->left) {
			node* exchange_node = nd->left;
			if (nd->right && exchange_node->data < nd->right->data) exchange_node = nd->right;

			if (exchange_node->data < nd->data) break;
			std::swap(exchange_node->data, nd->data);

			nd = exchange_node;
		}
	}

	void swim(node* nd) {
		while (nd->parent && nd->data > nd->parent->data) {
			std::swap(nd->data, nd->parent->data);
			nd = nd->parent;
		}
	}

	node* find_node_impl(node* parent, int index, int level) {
		if (level == 0) return parent;

		int level_parent = index / std::pow(2, level - 1);	// The parent of the node at this level.
		if ((level_parent % 2) == 0) {
			if (!parent->left) {
				node* left = new node{ -1, parent, nullptr, nullptr };
				parent->left = left;
			}
			return find_node_impl(parent->left, index, level - 1);
		} else {
			if (!parent->right) {
				node* right = new node{ -1, parent, nullptr, nullptr };
				parent->right = right;
			}
			return find_node_impl(parent->right, index, level - 1);
		}
	}

	/// <summary>
	/// Finds nodes, starting from N == 1. Creates a new node if the node does not exist (or all nodes in the path)
	/// </summary>
	/// <param name="index">index of node, starting from 1</param>
	/// <returns>a pointer to the requested node</returns>
	node* find_node(int index) {
		int level = std::log2(index);
		return find_node_impl(root, index, level);
	}

public:
	TwentyFour() : N{ 0 }, root{ new node{ 0, nullptr, nullptr, nullptr } } {}

	void insert(int val) {
		if (N == 0) {
			N++;
			root->data = val;
			return;
		}

		node* new_node = find_node(++N);	// Find and create the new node.
		new_node->data = val;	

		swim(new_node);	// Swim from this new node.
	}

	int delMax() {
		if (N == 0) {
			throw "The queue is empty";
		} 
		int max = root->data;

		node* last_node = find_node(N--);	// Find the last node.
		root->data = last_node->data;	// Exchange the data with that of the last node.
		if (last_node->parent)
		{ 
			if ( last_node->parent->left == last_node) 
			{
				last_node->parent->left = nullptr;
			}
			else
			{
			last_node->parent->right = nullptr;
			}
		}

		delete last_node;	// Delete last node. Remember that it has no children.
		sink(root);	// Sink the root node.
		return max;
	}

	static void test() {
		TwentyFour node_pq{};

		node_pq.insert(5); node_pq.insert(2); node_pq.insert(3); node_pq.insert(4); node_pq.insert(1);

		for (int i = 0; i < 5; i++) {
			std::cout << "current max value of pq is:" << node_pq.delMax() << '\n';
		}

		node_pq.insert(1); node_pq.insert(2); node_pq.insert(3); node_pq.insert(4); node_pq.insert(5);
		for (int i = 0; i < 5; i++) {
			std::cout << "current max value of pq is:" << node_pq.delMax() << '\n';
		}
	}
};

struct TwentyFour_A {
	/**
	* There's another interesting alternative to going from the child node to the parent node when finding the 
	* trajectory of nodes. That is, we can start from the parent node and go down, rather than going up!
	* 
	* To illustrate, consider the children of node i, and how they grow!
	*					 i
	*		2*i					2*i + 1
	* 2*2*i		2*2*i + 1	2*2*i + 2	2*2*i + 1
	* 
	* It's evident that at depth 2, the children of the right node (that is 2*i + 1) have their index start at
	* 2^depth * i + 2^(depth-1). Therefore, all we need to do is to calculate this expression, and then compare
	* it with the index given to us, to see if it's greater than equal to this value or not. If it's greater than
	* equal, then we need to continue from the right trajectory, otherwise we need go the left node and continue.
	* Now, once the depth is zero, we just need to check and see which child is equal to the index we want.
	* 
	* Example: assume that we want the trajectory to node 12. We know that the depth of the tree is 3.
	* 1 * (2 ^ 3) + 2^2 == 12 <= 12: Right child.
	* 3 * (2 ^ 2) + 2^1 == 14 > 12: left child.
	* 6 * (2 ^ 2) + 0 == 12 : Arrived at node (depth is zero)
	* 
	* Example: assume that we want the trajectory to node 11. We know that the depth of the tree is 3.
	* 1 * (2 ^ 3) + 2^2 == 12 > 10: Left child
	* 2 * (2 ^ 2) + 2^1 == 10 <= 10: Right child
	* 5 * (2 ^ 1) + 2^0 == 11 : Arrived at node (depth is zero, right child)
	* 
	* Example: assume that we want the trajectory to node 17. We know that the depth of the tree is 4.
	* 1 * (2 ^ 4) + 2^3 = 24 > 17: Left child
	* 2 * (2 ^ 3) + 2^2 = 20 > 17: Left child
	* 4 * (2 ^ 2) + 2^1 = 18 > 17: Left child
	* 8 * (2 ^ 1) + 2^0 == 17 : Arrived at node (depth is zero, right child)
	*/
};

struct TwentyFive_A {
	/**
	* This is the approach I used to take prior to this point, which had a computational burden of O(n^2). As 
	* we're about to see, things can get extremely complicated. 

	* Consider two arrays i in [0, 1, 2, ..., N] and j in [0, 1, 2, ..., N]. One would assume that starting from 
	* the first array, the best solution is to increment i and j such that j >= i. However, the result is not depicted 
	* in any particular order in this way. This is because the sequence is increasing in i and j. In fact, we have
	* the following progression:
	* (i,i), (i,i+1), (i,i+2), (i,i+3), ...
	*			(i+1,i+1), (i+1,i+2), (i+1,i+3), (i+1,i+4), ...
	*							(i+2,i+2), (i+2,i+3), (i+2,i+4), (i+2,i+5), ...	
	* 
	* We can see that at each level, some values of the previous level are less than equal to the first value of the
	* current level. Solution to this problem? Keep generating new values as long as the sequence is increasing.
	* Once it's decreasing, stop and show all the values that are less than and equal to this decreasing value. Then
	* start generating values again. The problem once again is that the space required is not N^2, but it's going to
	* be a multiple of N, which is a lot! This method is implemented in print_all.
	* 
	* Now, to compute all distinct a, b, c and d such that a^3+b^3 = c^3 + d^3, suppose that we have a and b. 
	* If we set d = c, then 0 <= c <= cubedRoot((a^3 + b^3)/2), and for each pair (c,d) that we find, there will
	* be a pair (d,c). Now, all we need to do is calculate d = cubedRoot(a^3 + b^3 - c^3) to check and see if d 
	* is a rational number. This however can be difficult, as we need to check to see how close d is to a rational 
	* number! While this is perfectly possible (need to check if abs(d - (int)d) < epsilon, another solution 
	* perhaps is to determine a lower and higher boundary for d. Suppose WLOG that a <= b, then  
	* 2a^3 - c^3 <= d^3 <= 2b^3 - c^3. Hence, we can write a for loop over int d, and check that if there's a d 
	* satisfying the equation for all such d.
	* 
	* Consequently, we need a double for loop, for which we choose c, and then for a chosen c, we check all d
	* in the given range, and set d as such, then check for equality.
	* 
	* Note that if for a pair (c,d) we have that a^3+b^3 == c^3 + d^3, we need to plus one the number of equal 
	* pairs. The same story goes for every pair (a,b).
	* 
	* The computational complexity of this algorithm is O(n^2)
	*/ 
	using minPQ = std::priority_queue<int, std::vector<int>, std::greater<int>>;
	static void print_all(int j) {
		minPQ pq{};
		std::cout << "A total of " << ((j + 2) * (j + 1) / 2.0) << " values should be printed\n";
		int counter = 1;
		for (int i = 0; i <= j; i++) {
			auto l = std::pow(i, 3) + std::pow(i, 3);
			for (int k = i; k <= j; k++) {
				auto r = std::pow(i, 3) + std::pow(k, 3);
				if (pq.empty()) pq.emplace(r);
				else if (l < r) pq.emplace(r);
				else {
					std::cout << "size is " <<  pq.size() << '\n';
					while (!pq.empty() && pq.top() < r) {
						auto val = pq.top();
						pq.pop();
						std::cout << counter++ << " --> " << val << '\n';
					}
					std::cout << counter++ << " --> " << r << '\n';
				}
				l = r;
			}
		}
	}

	static void equal_pairs(int a) {
		int counter = 0;
		for (int i = 0; i <= a; i++)
		{
			for (int j = i; j <= a; j++) 
			{
				counter += 4 * equal_pair_ab(i, j);
			}
		}

		
		std::cout << "Total number is: " << counter;
	}

private:
	static int equal_pair_ab(int a, int b) {
		int max_3 = std::pow(std::max(a, b), 3);
		int min_3 = std::pow(std::min(a, b), 3);

		int counter = 0;
		int c_max = std::pow((std::pow(a,3) + std::pow(b,3)) / 2.0, 1 / 3.);
		for (int c = 0; c <= c_max; c++) {
			int c_3 = std::pow(c, 3);

			int d_min = std::pow(2 * min_3 - c_3, 1 / 3.);
			int d_max = std::pow(2 * max_3 - c_3, 1 / 3.);
			
			for (int d = d_min; d <= d_max; d++) {
				if ((max_3 + min_3 - c_3) == std::pow(d,3) ){
					counter++;
					break;
				}
			}
		}

		return counter;
	}
};

struct TwentyFive_B {
	/**
	* As theey always say, there's a simpler algorithm for each one that contains several fors and whiles!
	* Now, considering the approach proposed in A, we can start with the pairs (0,0), (1,0) ..., (N,0). 
	* 
	* Assume we start and print the result of (0,0). Then, lets, create the rows (i,j) we discussed in 1, by 
	* incrementing j. Hence, we'd have (0,1). Now, compared to what have in the next row, which is (1,0), we
	* can print (0,1), thus we increment the second, and we have (0,2). Now, comparing to all we have generated,
	* we see that (1,0) is the next minimal element, and we print it, and increment the second to have (1,1). 
	* Continuing in this order, we see that we'd cover all the rows (depicted below):
	* starting elems:
	* (0,0),			(0,1),(0,2),....
	* (1,0),			(1,1),(1,2),....
	* ....
	* (N,0),			(N,1),(N,2),....
	* 
	* And we have printed every possible pair, in order. Notice how we go below in this approach every time we 
	* increment the second pair. The solution is to use a minPQ to keep our values ordered. Very clever solution
	* indeed! To keep track of i and j, we use tuple from std.
	* 
	* For the second part, we can simply start from the top element of the queue mentioned before. Then we pop
	* everytime, and we count the number of times we get equal values. Now, the problem mentions finding distinct
	* (a,b,c,d). So, note that (a,b) and (c,d) go over the two sides of the equality together. Hence, we have a
	* total possiblity of 8 permutations, namely (a,b,c,d), (b,a,c,d), (a,b,d,c), (b,a,d,c), (c,d,a,b), (c,d,b,a),
	* (d,c,a,b), (d,c,b,a).
	* 
	* Now, let's say we have a==b or c==d. Each of these equalities imply that we halve the number of equalities,
	* Note that a==b==c==d implies only 1 distinct permutation, and that only happens for (0,0), (1,1) pairs, and
	* there's only one such pair. On the other hand, each of a==c, a==d, b==d, b==c in and of themselves halve the
	* number of equalities. In face, note that if either of these hold, then we have no choice, but having the other
	* pair equal. Therefore, we only need to check for a==c or a == d. Consequently, we have the following:
	* 1- If there's only one pair, then n-distinct is 1.
	* 2- Else if a == b or c == d, then n-disctint is 4.
	* 3- Else if a == c or a == d, then n-distinct is 4.
	* 4- Else, n-distinct is 8.
	* Note that in this schema, a pair should never be compared to itself. This is because permutations involving
	* (i,j) = (i,j) are computed using the pair (j,i).
	* 
	* Note: It appears that we don't actually need the vector and comparison of elements, because it's possible
	* to have only two pairs, and those are permutations of one another, but I don't have a proof for this!
	* 
	* I'm really glad I spent as much time as I did on this exercise. I really learned a lot!
	*/
	using tuple = std::tuple<int, int, int>;

	struct greater {
		bool operator()(const tuple& lhs, const tuple& rhs) {
			
			return std::get<2>(lhs) > std::get<2>(rhs);
		}
	};

	using minPQ_tuple = std::priority_queue<tuple, std::vector<tuple>, greater>;

private:
	static minPQ_tuple _generate_pq(int N) {
		minPQ_tuple pq{};
		for (int i = 0; i <= N; i++)
		{
			tuple t = std::make_tuple(i, 0, std::pow(i, 3));
			pq.emplace(std::move(t));
		}

		return pq;
	}
	
public:
	// There's always room for improvement. How about just changing min, rather than creating  a new tuple t?
	static void print_all(int N) {
		auto tuple_minPQ = _generate_pq(N);

		while (!tuple_minPQ.empty())
		{
			auto min = tuple_minPQ.top(); 
			tuple_minPQ.pop();
			std::cout << "(" << std::get<0>(min) << "," << std::get<1>(min) << ")" << " --> " << 
					std::get<2>(min) << "\n";

			if (std::get<1>(min) < N) {
				int i = std::get<0>(min); int j = std::get<1>(min) + 1;
				tuple t = std::make_tuple(i, j, std::pow(i, 3) + std::pow(j, 3));
				tuple_minPQ.emplace(std::move(t));
			}

		}
	}

	static void equal_pairs(int N) {
		auto tuple_minPQ = _generate_pq(N);

		std::vector<tuple> equal_pairs{};
		tuple p_min = tuple_minPQ.top(); tuple min = tuple_minPQ.top(); tuple_minPQ.pop();
		int total_ctr = 0;
		while (true)
		{
			if (std::get<2>(min) == std::get<2>(p_min)) {
				equal_pairs.push_back(min);
			}
			else {
				total_ctr += count_equal_pairs(equal_pairs);
				equal_pairs.clear();

				equal_pairs.push_back(min);
				p_min = min;
			}

			if (std::get<1>(min) < N) {
				int i = std::get<0>(min); int j = std::get<1>(min) + 1;
				tuple t = std::make_tuple(i, j, std::pow(i, 3) + std::pow(j, 3));
				tuple_minPQ.emplace(std::move(t));
			}

			if (tuple_minPQ.empty()) {
				total_ctr += count_equal_pairs(equal_pairs);
				equal_pairs.clear();
				break;
			}
			
			min = tuple_minPQ.top(); 
			tuple_minPQ.pop();
		}

		std::cout << "Total number of equal pairs is: " << total_ctr;
	}

private:
	static int count_equal_pairs(const std::vector<tuple>& equals) {
		if (equals.size() == 1) return 1;

		int count = 0;
		for (int i = 0; i < equals.size(); ++i) {
			for (int j = i + 1; j < equals.size(); ++j) {
				int a = std::get<0>(equals[i]); int b = std::get<1>(equals[i]);
				int c = std::get<0>(equals[j]); int d = std::get<1>(equals[j]);

				if (a == b || c == d) {
					count += 4;
				}
				else if (a == c || a == d) {
					count += 4;
				}
				else {
					count += 8;
				}
			}
		}

		return count;
	}

};

struct TwentySix_A {
	/**
	* First, regarding the insertion sort (exercise 2.1.25) we can use a midpoint search to find the location 
	* where the elements are smaller, and then swap all elements from that location to the current location. 
	* The solution manual just keeps the current compare value in memory, but I don't think that's what's intended
	* here.
	* 
	* Now, coming back to the current exercise, assume that we want to swim. So keep the node from which we want to
	* swim, and using binary search from [1, ... i/2], find the parent node where the node to swim is smaller than.
	* By doing so, we only require to exchange the nodes in between. This solution however requires many a log
	* calculation, so I don't think binary searching the parents is actually a great idea! Perhaps, just comparing
	* the child value only with the parent and then exchaning is a good enough solution.
	* 
	* For the sink, go over the children, find the max, and compare it with the node to be sank. Continue this op
	* until reaching a point where the child node is no longer smaller. Then, starting from that child node, push
	* the child node one up. Finally, put the original parent node into the child.
	*/
	int pq[];

	void swim(int i) {	// i is the index of the node to swim.
		if (i <= 1) return;

		int child = pq[i];
		int j = i >> 1;
		while (j > 1 && pq[j] < child) { j >>= 1; };

		int k = i >> 1;
		while (k != j) {
			std::swap(pq[k], pq[k << 1]);
			k = k >> 1;
		}

	}



};

struct TwentySeven {
	/**
	* So, the way the solution manual has solved this problem is to keep track of the minimum everytime it's 
	* inserted. 
	* 
	* While this is the solution required by the book, and the natural one, we can keep another point in mind.
	* That is, note that the children of each node are smaller than their parents. Consequently, the smallest
	* node is a child less node, or nodes at the bottom of the tree. So assume that we've i nodes in the tree,
	* then we calculate i/2. So from the node i/2 + 1 till 2^(log(i/2) + 1) - 1 and from 2^(logi) till i, we 
	* have nodes that are childless. Hence, the minimum lies in one of these nodes. Note however that this
	* method is considered O(N), because we may have to check N/2 nodes! I can't see any use for this method,
	* so let's just stick to keeping track of the min!
	*/
};

struct TwentyNine {
	/**
	* I was hoping for a solution that didn't involve indexing, but that's apparently the only way.
	* 
	* So, the idea is this. We create an struct called Element for each inserted element. This struct would
	* contain the location of the element in both minPQ and maxPQ, together with their value. Now, what we 
	* do is that everytime an element is inserted, swims, or sinks, we just update the index of the corresponding
	* pq. Then, when it's time to remove min or max element, we go to the other tree. Then, we remove that 
	* element from the other tree, place the last element in there, and then we sink AND swim the node. That 
	* way, both trees will be updated.
	* 
	* I thought of another solution that would take O(n), namely, we could just minHeap or MaxHeap the array 
	* based on the demand of the user. This solution would use far less memory. However, the computational
	* complexity of computing min or max is O(n).
	* 
	* In the following implementation, we could think of ways of dropping the Type enum to judge the type based
	* on the supplied operation, or we can define another struct that contains both operation and Type.
	* 
	* Note that when removing elements, we need to first sink from position so that the child elements are
	* Ok, then we need to swim.
	*/
private:
	struct Element {
		int val;
		int pos_min;	// position in the min tree
		int pos_max;	// position in the max tree.
	};

	enum class PQType {min, max};

	using PQ = std::vector<Element*>;
	using minOp = std::greater<int>;
	using maxOp = std::less<int>;

	PQ min_pq{ new Element{0,0,0} };
	PQ max_pq{ new Element{0,0,0} };
	minOp greater_op{};
	maxOp less_op{};
	int N = 0;

	void swap_index(PQType t, Element* e1, Element* e2) {
		switch (t)
		{
		case TwentyNine::PQType::min:
			std::swap(e1->pos_min, e2->pos_min);
			break;
		case TwentyNine::PQType::max:
			std::swap(e1->pos_max, e2->pos_max);
			break;
		}
	}

	template<typename Op>
	void swim(PQType t, int k, PQ& pq, const Op& op) {
		while (k > 1 && op(pq[k>>1]->val, pq[k]->val)) {
			std::swap(pq[k], pq[k >> 1]);
			swap_index(t, pq[k], pq[k >> 1]);
			k >>= 1;
		}
	}

	template<typename Op>
	void sink(PQType t, int k, PQ& pq, const Op& op) {
		while ((k << 1) <= N) {
			int j = k << 1;

			if ((j + 1) <= N && op(pq[j]->val, pq[j + 1]->val)) ++j;
			if (!op(pq[k]->val, pq[j]->val)) break;
			std::swap(pq[j], pq[k]);
			swap_index(t, pq[j], pq[k]);
			k = j;
		}
	}

public:
	void insert(int val) {
		++N;
		// The new element is placed at the last position of both PQs
		Element* new_elem = new Element{ val, N, N };
		min_pq.emplace_back(new_elem);
		max_pq.emplace_back(new_elem);

		swim(TwentyNine::PQType::max, N, max_pq, less_op);
		swim(TwentyNine::PQType::min, N, min_pq, greater_op);
	}

	int max() {
		if (N == 0) {
			throw "min/max PQ is empty";
		}

		return max_pq[1]->val;
	}

	int min() {
		if (N == 0) {
			throw "min/max PQ is empty";
		}

		return min_pq[1]->val;
	}

	void remove_max() {
		int min_pos = max_pq[1]->pos_min;	// Position of this element in the minPQ

		--N;	// N is decremented here, so that there's no problem during sinking.
		// Here, we take care of max_pq as usuall
		std::swap(max_pq[1], max_pq[N+1]);	// Put last element on top.
		max_pq[1]->pos_max = 1;	// Notice that the position of this element is now 1.
		max_pq.pop_back();	// Now pop the last element.
		sink(TwentyNine::PQType::max, 1, max_pq, less_op);

		// Now, going to the minPQ, we need to replace last index with min_pos, and then swim once, and next
		// sink so that all elements are in proper order.
		if (min_pos == N + 1) {	// If min_pos is incidentally the last position 
			min_pq.pop_back();	// Just pop the last element, and we're done.
		} else {
			std::swap(min_pq[min_pos], min_pq[N+1]);	// Put last element on the position
			min_pq[min_pos]->pos_min = min_pos;	// Correct the position of this element.
			min_pq.pop_back();	// Get rid of the removed element.
			sink(TwentyNine::PQType::min, min_pos, min_pq, greater_op); // sink first
			swim(TwentyNine::PQType::min, min_pos, min_pq, greater_op);	// then swim.
		}
		

	}

	void remove_min() {
		int max_pos = min_pq[1]->pos_max;	// Position of this element in the maxPQ
		
		--N;	// N is decremented here, so that there's no problem during sinking.
		// Here, we take care of the min_pq as usuall
		std::swap(min_pq[1], min_pq[N+1]);	// Put last element on top.
		min_pq[1]->pos_min = 1;	// Notice that the position of this element is now 1.
		min_pq.pop_back();	// Now pop the last element.
		sink(TwentyNine::PQType::min, 1, min_pq, greater_op);

		// Now, going to the maxPQ, we need to replace last index with max_pos, and then swim once, and next
		// sink so that all elements are in proper order.
		if (max_pos == N + 1) {	// If incidentally, max_pos is the last element of this array
			max_pq.pop_back();	// Get rid of the removed element, and we're done!
		}
		else {
			std::swap(max_pq[max_pos], max_pq[N + 1]);	// Put last element on the position
			max_pq[max_pos]->pos_max = max_pos;	// Correct the position of this element.
			max_pq.pop_back();	// Get rid of the removed element.
			sink(TwentyNine::PQType::max, max_pos, max_pq, less_op); // then sink
			swim(TwentyNine::PQType::max, max_pos, max_pq, less_op);	// swim first
		}
		
		

	}

	int size() {
		return N;
	}

	static void test() {
		TwentyNine minMaxPQ{};

		minMaxPQ.insert(1); minMaxPQ.insert(2); minMaxPQ.insert(3); minMaxPQ.insert(4); minMaxPQ.insert(0);

		print_min_max(minMaxPQ);
		
		std::cout << "\nAfter removing max\n";
		minMaxPQ.remove_max();
		print_min_max(minMaxPQ);

		std::cout << "\nAfter removing min\n";
		minMaxPQ.remove_min();
		print_min_max(minMaxPQ);

		std::cout << "\nAfter removing max\n";
		minMaxPQ.remove_max();
		print_min_max(minMaxPQ);

		std::cout << "\nAfter removing max\n";
		minMaxPQ.remove_max();
		print_min_max(minMaxPQ);

		std::cout << "\nAfter removing max\n";
		minMaxPQ.remove_max();
		print_min_max(minMaxPQ);

		minMaxPQ.insert(1);
		std::cout << "\nAfter reinserting 1\n";
		print_min_max(minMaxPQ);

	}

private:
	static void print_min_max(TwentyNine& minMaxPQ) {
		if (!minMaxPQ.size()) {
			std::cout << "Size is now zero\n";
			return;
		}
		std::cout << "current min and max are (" << minMaxPQ.min() << "," << minMaxPQ.max() << ")\n";
	}

};

int main() {
	TwentyNine::test();
}