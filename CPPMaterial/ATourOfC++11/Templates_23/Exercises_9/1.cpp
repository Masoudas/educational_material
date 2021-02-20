#include <iostream>

template<typename T>
struct Link {
	Link* pre;
	Link* suc;
	T val;
};

template<typename T>
class List {
	Link<T>* head;

public:
	List(const T& t) : head{ new Link<T>{nullptr, nullptr, t } } { }
	void print_all() const {
		Link<T>* node = head;
		while (node) {
			std::cout << head->val << '\t';
			node = node->suc;
		}
	};
};