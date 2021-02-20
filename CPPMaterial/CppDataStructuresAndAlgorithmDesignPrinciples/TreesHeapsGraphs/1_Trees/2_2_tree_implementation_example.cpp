/**
* So now, let's implement a tree structure, assuming that we keep a pointer to the data, rather than the 
* actual data.
* 
* Question: Would be alright I wrote the destructor as 'delete left; delete right;'? I guess in a technical sense,
* there's no issue deleting the objects as such. The problem however might be that the recursion length could become
* very significant. Therefore, it's probably preferable to delete the nodes by hand. The issue is that in my 
* implementation, I use a recursion too, so what's the difference then? 
* 
* Pay special attention to how the copy constructor is called, using one recursion method, courtesy of yours truly.
* Also, note that with the copy assignment, we need to first delete the already existing tree, and then start making
* a copy.
*/
#include <string>
#include <stdexcept>
#include <queue>
#include <iostream>

template<typename T>
struct node {
	T* data;
	node *left, *right;

	~node() {
		delete data;
	}
};

template <typename T>
class tree {
	node<T>* root;

	tree(const T& data) {
		root = new node<T>{ new T{data}, nullptr, nullptr };
	}
	 
	void _destroy() {
		_destroy_traversal(root);
	}

	void _destroy_traversal(node<T>* node) {
		if (!node) return;
		_destroy_traversal(node->left);
		_destroy_traversal(node->right);
		delete node;
	}

	node<T>* _find(node<T>* parent, const T& data) {
		if (!parent) return nullptr;

		if (data == *parent->data) return parent;

		auto left = _find(parent->left, data);
		if (left) return left;

		return _find(parent->right, data);
	}

	node<T>* copy_traversal(node<T>* original) {
		auto node_cp = new node<T>{ new T{*original->data}, nullptr, nullptr };

		if (original->left) {
			node_cp->left = copy_traversal(original->left);
		}

		if (original->right) {
			node_cp->right = copy_traversal(original->right);
		}

		return node_cp;
	}

public:
	static tree build_tree(const T& root) {
		return tree{ root };
	}

	tree(const tree& other) {
		if (other.root) {
			root = nullptr;
			return;
		}

		root = copy_traversal(other.root);
	}

	void insert(const T& parent, const T& data) {
		auto p_node = _find(root, parent);

		if (!p_node) throw std::runtime_error("Parent node was not found");

		if (!p_node->left) {
			p_node->left = new node<T>{ new T{data}, nullptr, nullptr };
		}
		else {
			p_node->right = new node<T>{ new T{data}, nullptr, nullptr };
		}
	}

	tree(tree&& other) noexcept {
		root = other.root;
		other.root = nullptr;
	};

	tree& operator=(const tree& other) {
		// Remove existing tree
		_destroy();
		root = copy_traversal(other.root);
	}

	tree& operator=(tree&& other) noexcept {
		root = other.root;
		other.root = nullptr;

		return *this;
	};

	template<typename V, typename W>
	void level_order_traversal(V&& visitor1, W&& visitor2) {
		std::queue<node<T>*> queue{};
		
		queue.push(root);
		while (queue.size() != 0) {
			int n_nodes = queue.size();
			for (int i = 0; i < n_nodes; i++) {
				auto node = queue.front();
				queue.pop();

				if (node->left) queue.push(node->left);
				if (node->right) queue.push(node->right);

				visitor1(*node->data);
			}
			visitor2();
		}
	}
};

void create_a_simple_tree() {
	tree<std::string> tr = tree<std::string>::build_tree("God");

	tr.insert("God", "Adam");
	tr.insert("God", "Eve");

	tr.insert("Adam", "Kaine");
	tr.insert("Adam", "Able");
	tr.insert("Eve", "Other child 1");
	tr.insert("Eve", "Other child 2");

	auto print_node = [](const std::string& str) { std::cout << str << '\t'; };
	auto next_level = []() { std::cout << '\n'; };
	 
	tr.level_order_traversal(print_node, next_level);

	std::cout << "\nCopy of the tree prints:\n\n";
	auto tr_cp{ tr };
	tr.level_order_traversal(print_node, next_level);
}

//int main() {
//	create_a_simple_tree();
//}