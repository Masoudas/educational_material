/**
* Some people implement linked list by keeping the first node as pointer to pointer.
* What good will it do? Nothing I guess.
*/
template <typename T>
class list {
	struct Node{
		T item;
		Node* next;
	};

	Node** first;
	Node** last;

public:
	list() = default;

	void add(T item) {
		Node* node{ item, nullptr };

		if (!*first) *first = node;

		*last->next = node;
		last = &node;
	}

	T remove_first() {
		T item = *first->item;

		first = &first->next;
	}
};