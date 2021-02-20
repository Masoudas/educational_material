/**
* Insertion follows the same logic as find. First we need to traverse the tree to find the proper parent node 
* for that node. Once we've found the node, we insert it there.
* 
* In what follows, we implement the insertion method both as recursive and non-recursive. Honestly,
* the non-recursive version is very ugly, and a childish copy of the recursive method. Given that the depth
* of recursion does not exceed log(n) (for a balanced tree, where n is the number of nodes), the recursive
* method should be fine.
* 
* Question: Do we accept duplicate elements in a bst (i.e, equal values)? This is a good question. Imagine if
* we have a class, and we formed a bst based on one particular parameter of that class, then duplicate values
* should not be discarded. In this implementation of a tree, duplicate values go to the left.
*/
struct node {
	int val;
	node *left, *right;
};

class bst {
	node* root;

	void insert(int val) {
		insert_imp_r(root, val);
	}

	void insert_imp_r(node* parent, int val) {
		if (parent->val < val) {
			if (!parent->right) {
				parent->right = new node{ val, nullptr, nullptr };
			}
			else {
				insert_imp_r(parent->right, val);
			}
		}
		else {
			if (!parent->left) {
				parent->left = new node{ val, nullptr, nullptr };
			}
			else {
				insert_imp_r(parent->left, val);
			}
		}
	}

	void insert_imp(node* parent, int val) {
		if (!parent) {
			root = new node{ val, nullptr, nullptr };
			return;
		}

		while (true) {
			if (parent->val < val) {
				if (!parent->right) {
					parent->right = new node{ val, nullptr, nullptr };
					break;
				}
				parent = parent->right;
			}
			else {
				if (!parent->left) {
					parent->left = new node{ val, nullptr, nullptr };
					break;
				}
				parent = parent->left;
			}
		}
	}


};
