/* 
* The goal of this exercise is to swap two nodes of a linked list, by creating the minimum
* number of temporaries possible.
* 
* We can think of the following simple rounded structure to exchange nodes, where each node is exchanged
* with the arrow.
* 
* So first, we set pre_1.next to point to n2. Then we do the same from pre2 to n1.
* At this point, all is left for us to do is to exchange the next of n1 and n2, fo which we require a temp.
*					   ____________________________	
*					 <|							   |					
*			pre_1	n1	 next_1		....		pre_2	n2	next_2
*			  |				|___________________________ |^___|^	
*			  |__________________________________________|	
*
* It's actually very important that we first set n2->next = n1->next. Why? Because suppose the previous of
* n2 (or pre_2) is equal to n1. In that case, in the previous step, n1 would be a self referencing node! Hence,
* If we first assign the next of n2 to n1, we've made a self referencing node! So, we need to first assign
* n1 to n2. Hence, it's very important to follow the counter clockwise motion of assignments.
* 
* If n1 is null, we must skip assignment to it. We naturally assume that n1 and n2 are not null.
* 
* This is written assuming we know that n2 is in front of n1.
*/
#include <iostream>
using namespace std;

template <typename T>
class list {
	struct Node {
		T item;
		Node* next;
	};

	Node* first = nullptr;
	Node* last = nullptr;
	int N = 0;
	
	/* Finds steps nodes after start until null.*/
	Node* find_node(Node *start, int steps) {
		if (steps <= 0) return start; 
		for (; start && steps--; start = start->next);

		return start;
	}

public:
	list(initializer_list<int> items) {
		first = new Node{items.begin()[0], nullptr};
		last = first;

		for (int index = 1; index < items.size(); index++)
		{
			Node* new_last = new Node{ items.begin()[index], nullptr };
			last->next = new_last;
			last = new_last;
		}

		N = items.size();
	}

	void print() {
		for (Node* node = first; node; node = node->next) cout << node->item << '\t';
		cout << endl;
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

	void swap_nodes(int n1, int n2){
		if (n1 < 0 || n2 < 0) return;

		if (n1 > N - 1 || n2 > N - 1) return;

		if (n1 > n2) swap(n1, n2);

		Node* node1_p = n1 ? find_node(first, n1 - 1) : nullptr;
		Node* node1 = n1 ? node1_p->next : first;

		Node* node2_p = find_node(node1, n2 - n1 - 1);
		Node* node2 = node2_p->next;

		node1_p ? node1_p->next = node2 : first = node2;
		node2_p->next = node1;

		Node* temp = node2->next;
		node2->next = node1->next;
		node1->next = temp;

		// Reassigning the last node if node1 is the new last node.
		if (!node1->next) last = node1;
	}

	T peek() {
		return last->item;
	}
};

void test_node_swaps() {
	list<int> list{1, 2, 3 ,4};
	list.print();

	cout << "Swapping second and third node" << endl;
	list.swap_nodes(1, 2);
	list.print();

	cout << "Swapping first and second node" << endl;
	list.swap_nodes(0, 1);
	list.print();

	cout << "Swapping first and fourth node" << endl;
	list.swap_nodes(0, 3);
	list.print();

	cout << "Add a new last node to check if last is set" << endl;
	list.add(5);
	cout << "New last node is: " << list.peek() << endl;
}

//int main() {
//	test_node_swaps();
//}