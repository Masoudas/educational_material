/**
* There are several ways to traverse a tree, some of which at the moment make no sense to me:
* 1- Preorder traversal: In this traversal, we first print the parent node, then its children (left and right),
* in a recursive fashion. So we print the root first, then its left child, then the left child of the left child,
* and so forth.
* 2- In-order traversal: In this traversal, we first visit the left node, then parent, then right node, in a 
* recursive fashion.
* 3- Post-order traversal: In this traversal, we first visit the children of a node, then the parent node.
* 4- Level order traversal: In this traversal, we traverse each level of the tree, then we go down. This
* traversal has the coolest implementation. We use a queue and start from the root. We deque each node,
* print its data, and then add it its children to the queue, if they're not null. The loop goes on until we
* reach a queue of size zero. To make it a little fancier, we add an extra for loop, which is equivalent to
* the current size of the queue. With this loop, the first time the size of the loop is 1, second time is 2,
* third time is 4, etc. So, we can access each level individually! Quite nice and elegant.
* 
* Question: How do we go from the bottom of a tree to the top? I guess if the tree is not organized in 
* some way, the only solution would be to hold a reference to the parent. But I don't think we have that many
* unorganized trees in practice, because if did, then we'd need to traverse the entire tree before finding the
* node we seek first and then go back from there, which doesn't make sense.
*/
#include <iostream>
#include <queue>

struct node {
	int data;
	node* left, *right;
};

class tree {
	node* root;

	void preorder_traversal() {	
		preorder_traversal_impl(root);
	}
	
	void preorder_traversal_impl(node* node) {
		if (!node) { return; }
		std::cout << node->data << ", ";
		preorder_traversal_impl(node->left);
		preorder_traversal_impl(node->right);
	}

	void in_order_traversal() { 
		in_order_traversal_impl(root); 
	}

	void in_order_traversal_impl(node* node) {
		if (!node) { return; }
		in_order_traversal_impl(node->left);
		std::cout << node->data << ", ";
		in_order_traversal_impl(node->right);
	}

	void post_order_traversal() {
		post_order_traversal_impl(root);
	}

	void post_order_traversal_impl(node* node) {
		if (!node) { return; }
		post_order_traversal_impl(node->left);
		post_order_traversal_impl(node->right);
		std::cout << node->data << ", ";
	}

	void level_order_traversal() {
		if (!root) {
			return;
		}

		std::queue<node*> nodes{};
		nodes.push(root);

		while (!nodes.empty()) {
			int size = nodes.size();
			for (int i = 0; i < size; i++) {
				auto node = nodes.front();
				nodes.pop();

				std::cout << node->data << ", ";
				if (!node->left) { nodes.push(node->left); }
				if (!node->right) { nodes.push(node->right); }
			}

			std::cout << std::endl;
		}

	}



};