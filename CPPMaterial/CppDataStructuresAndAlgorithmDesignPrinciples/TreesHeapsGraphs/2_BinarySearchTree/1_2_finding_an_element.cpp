/**
* To find an element, as we said, we either turn left or right, depending on whether the search value
* is greater than the current node or not.
* 
* In what follows, we find the node recursively, and using a while loop.
*/

struct node
{
	int val;
	node *left, *right;
};

class BST {
	node* root{};

	node* find(int val) {
		node* goal = root;

		while (goal != nullptr && goal->val != val) {
			if (goal->val < val) goal = goal->right;
			else goal = goal->left;
		}

		// This maybe nullptr depending on whether we found our node or not.
		return goal;
	}

	node* find_r(int val) {
		return find_r_imp(root, val);
	}

	node* find_r_imp(node* node, int val) {
		if (!node) return nullptr;
		else if (node->val == val) return node;
		else if (node->val < val) return find_r_imp(node->right, val);
		else return find_r_imp(node->left, val);
	}

};

