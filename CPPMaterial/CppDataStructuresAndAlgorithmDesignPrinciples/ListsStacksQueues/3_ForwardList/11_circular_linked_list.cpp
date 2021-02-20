/**
* Question: How do we go about implementing a circular list? With the ability to go back and forth on the list? 
*
* Answer: We use a doubly linked list here. The solution we're going to implement here actually
* has a circular node structure. This would imply that the last node is linked backed to the first node. 
* For this to happen, we need a dummy node, which holds a null data. Now, to hold a null data in a sensible
* manner, we're going to implement our nodes to hold data pointers, so that the dummy node has null data in
* a sensible manner. Finally, we wrap this generic list in another interface responsible for traversing the list
* with methods such as, insert, remove, etc. Note that now, a normal begin iterator loops around, so we can just
* skip the dummy song!
* 
* constructor: Note how the constructor is made. A dummy node is created which points to itself.
* 
* insert method: Aim is to create a reverse list, where head is always the first element. Therefore we have, 
* null->h=1, null->h=2->1, null->h=3->2->1, null->h=4->3->2->1. Notice that this way, head will always remain
* the first node of the lot.
* 
* erase method: Find the node based on the given data, and erase the node.
* 
* iterator and const iterator: These are implemented the same way as a normal iterator.
* 
* begin and end method: Return the iterator, one pointing to dummy method and one to head.
* 
* copy constructor and initializer list constructor: Note that these two put elements in reverse order, making
* it null->h=1->2->3->4 for example. However, this does not matter. We could use a reverse iterator to take care 
* of this problem.
*/ 
#include <initializer_list>
#include <iostream>
#include <string_view>

template <typename T>
struct cir_list_node {
	T* data;
	cir_list_node *prev, *next;

	~cir_list_node() {
		delete data;
	}
};

template <typename T>
class circular_list {
	using node = cir_list_node<T>;
	using node_ptr = node*;

	node_ptr head{ nullptr };
	size_t n;

public:
	circular_list() : n{ 0 } {
		head = new node{ nullptr, nullptr, nullptr };

		head->next = head;
		head->prev = head;
	}

	circular_list(std::initializer_list<T> l) : circular_list{} {
		for (const T& data : l) {
			insert(data);
		}
	};

	circular_list(const circular_list& other) : circular_list{} {
		for (const T& data : other) {insert(data);}
	}

	~circular_list() {
		auto dummy = head->prev;
		while (size()) {
			auto oldHead = head;
			head = head->next;
			delete oldHead;
			n--;
		}

		delete dummy;

		// Suggestion by the book is to use the erase method as follows. But wouldn't it take longer
		// compared to what I wrote above? And what about the dummy node?
		/*
		while(size()){
			erase(*(head->data));
		*/
	}

	size_t size() {
		return n;
	}

	void insert(const T& data) {
		n++;
		node_ptr newNode = new node{ new T{data}, nullptr, nullptr };
	
		// auto oldHead = head; We could work with old here. The problem is that old head does not change
		// if there's a non dummy node. 

		auto p_head = head->prev; // If previous of head is dummy (no data), we put data right after
								  // otherwise, 	
		p_head->next = newNode;	  // This is common between if and else, hence brought out.
		newNode->prev = p_head;	 // This is common too.

		if (p_head == head) {
			newNode->next = head;
			head->prev = newNode;
			head = newNode;
		}
		else {
			newNode->next = head;
			head->prev = newNode;
			head = newNode;
		}
	}

	void erase(const T& data) {
		node_ptr d_node = head;
		while (d_node != head->prev & *(d_node->data) != data) { d_node = d_node->next; }

		if (d_node == head->prev) return;	// If no node is found, return.

		auto p_d_node = d_node->prev;
		auto n_d_node = d_node->next;
		
		p_d_node->next = n_d_node;
		n_d_node->prev = p_d_node;
		if (d_node == head) {			
			head = n_d_node;
		}

		delete d_node;
		--n;
	}

private:
	struct cir_list_it {
		cir_list_it(node_ptr ptr) : ptr{ ptr } {}
		
		cir_list_it& operator++() {
			ptr = ptr->next;
			return *this;
		}

		cir_list_it operator++(int) {
			cir_list_it temp{ *this };
			ptr = ptr->next;
			return temp;
		}

		cir_list_it& operator--() {
			ptr = ptr->prev;
			return *this;
		}

		cir_list_it operator--(int) {
			cir_list_it temp{ *this };
			ptr = ptr->prev;
			return temp;
		}

		friend bool operator==(const cir_list_it& left, const cir_list_it& right) {
			return left,ptr = right.ptr;
		}

		friend bool operator!=(const cir_list_it& left, const cir_list_it& right) {
			return left.ptr != right.ptr;
		}

		/*T& operator->() {
			return ptr;
		}*/

		T& operator*() {
			return *(ptr->data);
		}

	private:
		node_ptr ptr;

	};

	struct const_cir_list_it {
		const_cir_list_it(node_ptr ptr) : ptr{ ptr } {}

		const_cir_list_it& operator++() {
			ptr = ptr->next;
			return *this;
		}

		const_cir_list_it operator++(int) {
			const_cir_list_it temp{ *this };
			ptr = ptr->next;
			return temp;
		}

		const_cir_list_it& operator--() {
			ptr = ptr->prev;
			return *this;
		}

		const_cir_list_it operator--(int) {
			const_cir_list_it temp{ *this };
			ptr = ptr->prev;
			return temp;
		}

		friend bool operator==(const const_cir_list_it& left, const const_cir_list_it& right) {
			return left, ptr = right.ptr;
		}

		friend bool operator!=(const const_cir_list_it& left, const const_cir_list_it& right) {
			return left.ptr != right.ptr;
		}

		/*T& operator->() {
			return ptr;
		}*/

		const T& operator*() {
			return *(ptr->data);
		}

	private:
		node_ptr ptr;

	};

public:
	cir_list_it begin() {
		return cir_list_it{ head };
	}

	const_cir_list_it cbegin() const {
		return const_cir_list_it{ head };
	}

	const_cir_list_it begin() const {
		return cbegin();
	}

	cir_list_it end() {
		return cir_list_it{ head->prev };
	}

	const_cir_list_it end() const {
		return cend();
	}

	const_cir_list_it cend() const {
		return const_cir_list_it{ head->prev };
	}
};

void circulat_linked_list_test() {
	circular_list<int> c{};

	std::cout << "insertion: ";
	c.insert(1); c.insert(2); c.insert(3);
	std::copy(c.begin(), c.end(), std::ostream_iterator<int>{std::cout, "\t"});

	std::cout << "\nErasing 3: ";
	c.erase(3);
	std::copy(c.begin(), c.end(), std::ostream_iterator<int>{std::cout, "\t"});

	std::cout << "\nCopy constructor: ";
	circular_list<int> c2{ c };
	std::copy(c2.begin(), c2.end(), std::ostream_iterator<int>{std::cout, "\t"});
}

using std::string_view;

class playList {
	circular_list<string_view> songs{};

	void insert(const string_view& song) {
		songs.insert(song);
	}

	void erase(const string_view& song) {
		songs.erase(song);
	}

	void print_all_songs()
	{
		for (const auto& song : songs)
			std::cout << song << " ";
		std::cout << std::endl;
	}
};

