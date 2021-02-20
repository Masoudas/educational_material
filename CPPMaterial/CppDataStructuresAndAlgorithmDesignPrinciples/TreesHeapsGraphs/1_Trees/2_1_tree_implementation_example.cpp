/**
* In this example, we try and implement the organizational structure of a company as a tree. We assume that
* each tree has two children, making it a binary tree.
* 
* Also note how we implement the destructor of the tree. We use the post order pattern together with the visitor
* pattern to destroy the children of each node.
* 
* If we look at the copy constructor, we can't create a node, unless we want to put the data right away in
* string_view. This is one reason why it's perhaps more desirable if we keep the data in node as pointer, rather
* than as raw value. Problem is that it reduces efficieny, given we have to write a destructor. I don't know
* honestly which one is better. We consider such an implementation in the next exercise.
* 
* One thing to note about this exersice is that the find method looks for a node that has the string in the entire
* tree. Now, imagine both marketing and R&D departments had a position called manager. That would mean that probably
* the wrong node will be found. See example 3 on writing a method that would actually find a particular parent to
* child trajectory.
*/
#include <string_view>
#include <stdexcept>

struct node {
	std::string_view position;
	node *left, *right;
};

class org_tree {
	node* root;
	node* find(node* start, const std::string_view& position) {
		if (!start) return nullptr;
		if (start->position == position) return start;

		auto left_result = find(start->left, position);
		if (left_result) 
			return left_result;
		
		return find(start->right, position);
	}

	org_tree(node* root) : root{ root } {}

	template<typename V>
	void post_order_traversal_impl(node* node, const V& visitor) {
		if (!node) { return; }
		post_order_traversal_impl(node->left, visitor);
		post_order_traversal_impl(node->right, visitor);
		visitor(node->position);
	}

	void copy_children(node* original, node* copy) {
		if (original->left) {
			copy->left = new node{ original->left->position, nullptr, nullptr };
			copy_children(original->left, copy->left);

		}
		if (original->left) {
			copy->right = new node{ original->right->position, nullptr, nullptr };
			copy_children(original->right, copy->right);
		}

	}

	void _destroy() {
		_destroy_traversal(root);
	}

	void _destroy_traversal(node* node) {
		if (!node) return;
		_destroy_traversal(node->left);
		_destroy_traversal(node->right);
		delete node;
	}

public:
	static org_tree make_tree(const std::string_view& head) {
		org_tree tree{ new node{ head, nullptr, nullptr } };
		return tree;	// Move constructor is used here.
	}

	void insert(const std::string& manager, const std::string& subordinate) {
		auto m_node = find(root, manager);

		if (!m_node) throw std::runtime_error{"Manager has left the building!"};

		if (!m_node->left) m_node->left = new node{ subordinate, nullptr, nullptr };
		else if (!m_node->right) m_node->left = new node{ subordinate, nullptr, nullptr };
		 
		throw std::runtime_error{ "Both nodes are occupied" };
	}

	template<typename V>
	void post_order_traversal(V&& visitor) {
		post_order_traversal_impl(root, visitor);
	}

	org_tree(const org_tree& other) {
		if (!other.root) {
			root = nullptr; return;
		};

		root = new node{other.root->position, nullptr, nullptr};
		copy_children(other.root, root);
	}

	~org_tree() {
		_destroy();
	}
};