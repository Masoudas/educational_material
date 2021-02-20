#include <algorithm>
#include <iostream>
#include <ctime>
using namespace std;

template <typename T>
class Seventeen {
	/**
	* The idea of the sort is that when merging two groups of nodes, the ones until the first natural
	* index need not be changed. Only the ones that are after the first index need to be detached 
	* and put back. Then in the end, the merge must return the last node of the merged list.
	*/
	struct Node {
		T item;
		Node* next;

		Node() = default;	// To allow for memberwise initialization.
		~Node() { if (next) delete next; }
	};

	Node* first = nullptr;
	Node* last = nullptr;

	int N = 0;

public:
	Seventeen() = default;

	void add(T item) {
		Node* node = new Node{ item, nullptr };

		if (!first) {
			first = node;
		}

		if (last) {
			last->next = node;
		}

		last = node;
		N++;
	}

	/**
	* Find the last node for which there's order, starting from the given order.
	*/
	Node* find_order(Node* node) const {
		if (!node) return node;

		for (; (node->next != nullptr) && (node->item) < (node->next->item); node = node->next);

		return node;
	}

	int size() const { return N; }

	bool isEmpty() const { return N == 0; }

	void sort() noexcept {
		Node* first_ordered = find_order(first);
		
		while (first_ordered->next != nullptr)
		{
			Node* second_ordered = find_order(first_ordered->next);
			first_ordered = merge(first_ordered, second_ordered);	

			first_ordered = find_order(first_ordered);
		}

		last = first_ordered;
	}

	~Seventeen() {
		if (first) {
			delete first;
		}
	}

	void print() {
		for (Node* node = first; node; node = node->next) cout << node->item << '\t';
		cout << endl;
	}

private:
	/**
	* Merges two naturally ordered sets together, and then returns the last node for which sort has happened.
	*/
	Node* merge(Node* const first_ordered, Node* const second_ordered) {
		Node* curr = first;
		Node* pre = nullptr;

		Node* second_list = first_ordered->next;
		Node* second_list_pre = first_ordered;
		Node* after_second = second_ordered->next;

		if (curr->item > second_list->item) {
			// Keeping track of this node, to be installed after previous.
			Node* after_pre = second_list;
			
			// Changing top of list.
			second_list = second_list->next;	
			second_list_pre->next = second_list;
			
			// Changing bottom of list, i.e, setting first to second
			after_pre->next = first;
			first = after_pre;
			
		}
		pre = first;
		curr = first->next;
		
		while (second_list != after_second && curr != after_second)	// We can't make this condition tigher I think.
		{
			if (curr->item > second_list->item) {
				// Keeping track of this node, to be installed after previous.
				Node* after_pre = second_list;

				// Changing top of list.
				second_list = second_list->next;
				second_list_pre->next = second_list;

				// Changing bottom of list.
				after_pre->next = curr;
				pre->next = after_pre;
				
				pre = after_pre;
			}
			else {
				pre = curr;
				curr = curr->next;
			}

		}

		return pre;

	}

public:
	static void test_seventeen() {
		Seventeen<int> list{};
		list.add(1);
		list.add(2);
		list.add(4);
		list.add(3);

		list.sort();

		list.print();
	}
};

template <typename T>
class Eighteen {
	/*
	* 
	* One would assume that to randomly shuffle a list, we'd just exchange two elements. That way,
	* the shuffling time is linearithmetic (NlogN. This happens because C[N] = C[N-1}+ + C[N-1]_ + N).
	* The problem with this method is that for example a list like [1 2] is always shuffled to [2 1].
	* Hence, we need to have a random variable saying whether we want to perform an exchange or not.
	* 
	* The problem with the shuffling is that I need to have access to the previous element of the list
	* being shuffled for the first element.
	*/
	struct Node {
		T item;
		Node* next;
	};

	Node *first = nullptr;
	Node *last = nullptr;
	int N = 0;
public:
	Eighteen() { 
		srand(static_cast<unsigned>(time(0))); 
	}

	void add(T item) {
		Node* node = new Node{ item, nullptr };

		if (!first) {
			first = node;
		}

		if (last) {
			last->next = node;
		}

		last = node;
		N++;
	}

	int size() const { return N; }

	bool isEmpty() const { return N == 0; }

	void print() {
		for (Node* node = first; node; node = node->next) cout << node->item << '\t';
		cout << endl;
	}

	void shuffle() {
		_divide(0, N - 1);
	}
private:
	void _divide(int lo_index, int hi_index) {
		if (lo_index >= hi_index) return;

		int mid_index = floor((lo_index + hi_index) / 2.0);

		Node* lo_p = lo_index ? find_node(first, lo_index - 1) : nullptr;
		Node* lo = lo_p ? lo_p->next : first;
		Node* mid = find_node(lo, mid_index - lo_index);
		Node* hi = find_node(mid, hi_index - mid_index);

		_shuffle(lo_p, lo, mid, hi);
		_divide(lo_index, mid_index);
		_divide(mid_index + 1, hi_index);
	}

	/* We first shuffle the first two elements of the two lists. That way, we know the starting element of
	* both elements*/
	void _shuffle(Node* lo_p, Node* lo, Node* mid, Node* hi) {
		Node* hi_next = hi->next;

		Node* l1_previous = lo_p;
		Node* l1_current = lo;

		Node* l2_previous = mid;
		Node* l2_current = mid->next;

		bool shuffle = rand() % 2;
		// Shuffle first element;
		if (shuffle) {
			swap_nodes(lo_p, lo, mid, mid->next);		
			l1_previous = l2_current;
			l2_previous = l1_current;
		}
		else {
			l1_previous = l1_current;
			l2_previous = l2_current;
		}
		
		if (!lo_p) {
			first = l1_previous;
		}

		l1_current = l1_previous->next;
		l2_current = l2_previous->next;
		while (l2_current != hi_next && l1_current != mid->next)
		{
			shuffle = rand() % 2;
			if (shuffle) {
				swap_nodes(l1_previous, l1_current, l2_previous, l2_current);
				l1_previous = l2_current;
				l2_previous = l1_current;

			}
			else {
				l1_previous = l1_current;
				l2_previous = l2_current;
			}
			l1_current = l1_previous->next;
			l2_current = l2_previous->next;
		}

		if (!l2_previous->next) {
			last = l2_previous;
		}
	}

	/* Finds count nodes after node start */
	Node* find_node(Node* start, int count) {
		if (count <= 0) return start;

		while (count--)
		{
			start = start->next;
		}

		return start;
	}

	/* Swaps two nodes in list, using the previous nodes of each. null node for previous is acceptable.
	 Swap using the circular rule. See swap_nodes_in_linked_list in Chapter_I.SectionIII*/
	void swap_nodes(Node* n1_p, Node* n1, Node* n2_p, Node* n2) {
		if (n1_p) n1_p->next = n2; else first = n2;

		n2_p->next = n1;
		
		Node * temp = n2->next;
		n2->next = n1->next;
		n1->next = temp;

		if (!n1->next) last = n1;
	}

public:
	static void test_eighteen() {
		Eighteen<int> list{};
		list.add(1);
		list.add(2);
		list.add(3);
		list.add(4);
		
		list.shuffle();

		list.print();
	}
};

template <typename T, int SIZE_T>
class Nineteen {
public:
	/*
	* One would assume that inversion occurs in the merge method, and to count them we only require 
	* to check the two bottom if loops in the merge method.
	* 
	* Perhaps a more interesting question here would be to check how many times a particular element has
	* been inverted. For that, we need two auxiliary arrays. One is keeping the index track, and the other
	* one is a counter for each index. So let's say we have [3 2 1]. Then index = [0 1 2] and count = [0 0 0]
	* We swap 0 and one. Hence [2 3 1] and [1 0 2] and count[index[0]]++ and count[index[1]]++; Keeping on
	* in this manner, we can find the number of count for each element. Then we can give the total number of
	* swaps using this array too, as a sum of it.
	*/
	static T* merge_sort(T* start, T* end) {
		int N = end - start;

		T* aux = new int[N]{};
		T* index = new int[N]{};
		T* count = new int[N]{};

		sort(start, aux, index, count, 0, N - 1);

		delete[] aux;
		delete[] index;
		return count;
	}

	static void sort(T* vec, T* aux, T* index, T* count, int lo, int hi) {
		if (lo >= hi) return;
		int mid = (hi + lo) / 2.0;

		sort(vec, aux, index, count, lo, mid);
		sort(vec, aux, index, count, mid + 1, hi);
		merge(vec, aux, index, count, lo, mid, hi);
	}

	static void merge(T* vec, T* aux, T* index, T* count, int lo, int mid, int hi) {
		int i = lo; int j = mid + 1;

		memcpy(aux + lo, vec + lo, SIZE_T * (hi - lo + 1));

		for (int k = lo; k <= hi; k++)
		{
			if (i > mid) vec[k] = aux[j++];	// No swap
			else if (j > hi) vec[k] = aux[i++];	// No swap
			else if (aux[i] < aux[j]) {
				i++;	// No swap
			}
			else {
				swap_ptr(vec + k, aux + j);
				swap_ptr(index + k, index + j);
				count[k]++;
				count[j]++;

				j++;
			}
		}


	}

	static void swap_ptr(T* t1, T* t2) noexcept {
		T temp = move(*t1);
		*t1 = move(*t2);
		*t2 = move(*t1);
	}

	static void test_nineteen() {
		int arr[] = { 2, 3, 1 };

		int* counts = merge_sort(arr, arr + 3);

		cout << "Printing sorted array" << endl;
		for (auto var : arr)
		{
			cout << var << '\t';
		}
		cout << endl;
		cout << "Printing counts" << endl;

		for (int i = 0; i < 3; i++) {
			cout << counts[i] << '\t';
		}
	}
};

class Twenty {
	/*
	* In other words, we want the index of the sorted elements, rather than the actual element. This is 
	* actually what I did in exercise 19.
	* 
	* Question: Say we have an array. The question is what is the index of the i-th smallest element?
	* Answer: One solution would be to sort, and then find that element. Is there a faster approach here?
	* The heap based solutions are useful.
	*/
};

template <typename T>
class TwentyOne_1 {
	/*
	* Let's solve this problem for two lists first. In such a case, all we need to do is to first sort the arrays,
	* the start from the left and search. The comparison is of order N + M in the worst case, because just like a 
	* normal sort, we may need to compare every individual element (say [1, 3, 5] and [2 4 5]). However, this is over
	* shadowed by the cost of sort.
	* 
	* 
	*/
	static void find_common_element(T* begin1, T* end1, T* begin2, T* end2) {
		sort(begin1, end1);
		sort(begin2, end2);

		int N1 = end1 - begin1;
		int N2 = end2 - begin2;

		int i = 0; int j = 0;
		while (true) {
			if (i > N1 - 1 || j > N2 - 1) {
				cout << "No common element"; break;
			}

			if (begin1[i] == begin2[j]) { cout << "Common element is: " << begin1[i] << endl; break; }
			else if (begin1[i] < begin2[j]) i++;
			else j++;
		}
	}
public:
	static void test_twentyone_1() {
		string arr1[] = { "Miss", "This", "Hiss" };
		string arr2[] = { "Kiss", "Piss", "Miss", "Niss" };

		find_common_element(arr1, arr1 + 3, arr2, arr2 + 4);
	}
};

template <typename T>
class TwentyOne_2 {
	/*
	* Now, we try to solve the problem for three arrays. Like before we first need to sort them, which would take
	* NlogN time. Then we need a comparison. Note that for each two arrays we need N + M comparisons. An upper bound
	* would be to find the common among two lists, and then compare it with the third. This would require N + M +
	* (N + M + K) comparisons.
	* 
	* Note however that if we tried to compare the three lists simulatenously, we go over a worse case, where each two
	* arrays would be compared to each other twice. Therefore, we would need (N + M) + (N + K) + (M+K) comparisons.
	* Hence, it would be better to find the list of common elements, and then compare them to the third list.
	* 
	* To solve the need for keeping the list of common names, there's actually a simpler solution. We can find the common
	* part of two lists, then search for it in the other list.
	* 
	* Now, an even better solution is to do this for every two permutation of lists. Find common between one and two.
	* Check the common of two and three, if the index of first has not changed, return result, otherwise, now compare 
	* one and three. This method would take N + M + K comparisons!
	* 
	*
	*/
	static void find_common_element_bad_method(T* begin1, T* end1, T* begin2, T* end2, T* begin3, T* end3) {
		sort(begin1, end1);
		sort(begin2, end2);
		sort(begin3, end3);

		int N1 = end1 - begin1;
		int N2 = end2 - begin2;
		int N3 = end3 - begin3;

		int i = 0; int j = 0; int k = 0;
		while (true)
		{
			if (i > N1 - 1 || j > N2 - 1 || k > N3 - 1) {
				cout << "No common element"; break;
			}

			if (begin1[i] < begin2[j]) i++;
			else if (begin2[j] < begin1[i]) j++;
			else {
				if (begin2[j] == begin3[k]) {
					cout << "The common element is: " << begin2[j];
					break;
				}
			}

			// Comparing one and three
			if (begin3[k] < begin1[i]) k++;
			else if (begin1[k] < begin3[i]) i++;

			// Comparing two and three
			if (begin3[k] < begin2[j]) k++;
			else if (begin2[j] < begin3[k]) j++;
		}
	}

	static void find_common_element_good(T* begin1, T* end1, T* begin2, T* end2, T* begin3, T* end3) {
		sort(begin1, end1);
		sort(begin2, end2);
		sort(begin3, end3);

		T* begins[] = { begin1, begin2, begin3 };
		T* ends[] = { end1, end2, end3 };

		int c_list1 = 2;
		int c_list2 = 3;
		int nc_list = 1;
		int max_index[] = {0, 0, 0};

		while (true) {
			choose_list(&c_list1, &c_list2, &nc_list);
			int common = find_common_two_lists(
				begins[c_list1] + max_index[c_list1 - 1], ends[c_list1], 
				begins[c_list2] + max_index[c_list2 - 1], ends[c_list2]);
			
			max_index[c_list1 - 1] = common;
			max_index[c_list2 - 1] = common;

			if (common < 0) {
				cout << "No common was found" << endl;
				break;
			}
			else {
				if (common == max_index[nc_list]) {
					cout << "Common element is: " << begin1[common];
					break;
				}
				
			}

		}
	}

	static int find_common_two_lists(T* begin1, T* end1, T* begin2, T* end2) {
		int N1 = end1 - begin1;
		int N2 = end2 - begin2;

		int i = 0; int j = 0;
		while (true) {
			if (i > N1 - 1 || j > N2 - 1) return -1;

			if (begin1[i] == begin2[j]) { return i; }
			else if (begin1[i] < begin2[j]) i++;
			else j++;
		}
	}

	static void choose_list(int* c_list_1, int* c_list_2, int* nc_list) {
		if (*c_list_1 == 1) {
			if (*c_list_2 == 2) {
				*c_list_2 = 3;
				*nc_list = 2;
			}
			else {
				*c_list_1 = 2;
				*nc_list = 1;
			}
		}
		else {
			*c_list_1 = 1; *c_list_2 = 2; *nc_list = 1;
		}
	}

public:
	static void test_twentyone_2() {
		string arr1[] = { "Miss", "This", "Hiss" };
		string arr2[] = { "Kiss", "Piss", "Niss", "Miss" };
		string arr3[] = { "Miss", "Viss", "Diss", "Bliss" };

		find_common_element_good(arr1, arr1 + 3, arr2, arr2 + 4, arr3, arr3 + 4);
	}
};

class Twenty_Two {
	/*
	* Imagine we broke down the list into three parts. Then for comparison, we have to compare each element of array
	* one with two, two with three, and three with two. Hence, we'd be doing 3*N comparisons. We 
	* then have write C(N) = 3C(N/3) + 3N, and we arrive at 3Nlog_3(N), which is equal to 3Nlog(N)/log_2(3)
	* which is the same as NlogN.
	*/
};
//int main() {
//	TwentyOne_2<string>::test_twentyone_2();
//}
