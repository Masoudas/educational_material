/**
* Several methods come to mind when we want to delete (in my opinion!). For example, I guess we can recursively
* go down and replace the deleted node with its right child. In fact, we can even do better than that.
* 
* So imagine the following scenarios:
* 1- Node has no children: We do nothing.
* 2- Node has one child: We replace the node with the existing child. We can do this because severing a one edge
*	node does not alter the structure of the tree.
* 3- Node has two children: In this case, if we take one turn right, all the children node would be greater than
* the node we want to delete. So, we can find the smallest of such nodes by now going as left as we can. The only
* matter that remains is that the last left node might have right children (it has no left children of course). So,
* what we can do is that we need the parent of this last left node, we severe its child, attache it to the parent,
* and now, this last child is free to be put on the node that is already deleted.
* 
* How do we implement this method:
* 1- The normal approach requires knowing the parent of the node we want to delete, and the parent of the successsor
* node. Hence, we need two separate while loops for them. While this is a fine method, the next recursive method
* is also quite interesting.
* 2- Basically, we implement a recursive method of finding the node. Then we examine the node and if it has
* two children, we call another method to find the successor method. Now get this, we exchange the value of 
* successor with the node (rather than the actual node), and now, we continue the search with the successor
* value and from its node. Now, because this node only has one child, we can replace it with its child node,
* using the same node. A really elegant method for deletion I have to say.
* 
* But we can go one step further and make it truly elegant. Imagine this, as we start traversing the tree,
* the recursive method is implemented to do two things:
* 1- If the current node is not the node we seek, it returns the same node, however calls the same method.
* 2- If the current node is the node we seek, it returns the node it should be replaced with as follows:
*	- If the current node has no child, returns null.
*	- If it has one child, deletes the current node, and then returns the only child of this node.
*	- If it has two children, it finds the successor. Then, it replaces the value of current node with the
*	successor, and then starts the deletion from the successor node, with the successor value. Note that the
*   book starts from the right node of the replaced node, but I guess it's fine to start from the replaced 
*	successor.
* 
* What happens if there are several copies of an element in the tree?
*/

struct node {
	int val;
	node *left, *right;
};

class bst {
	node* root;

	node* find_successor(node* start) {
		node* current = start->right;
		while (current && current->left) {
			current = current->left;
		}

		return current;
	}

	void deleteValue(int val) {

	}

	node* deleteValue_impl(node* start, int val) {
		if (!start) return nullptr;

		if (val < start->val) {
			start->left = deleteValue_impl(start, val);
		}
		else if (val > start->val) {
			start->right = deleteValue_impl(start, val);
		}
		else {
			if (!start->left) {
				auto temp = start->right;
				delete start;
				return temp;	// This now is the child node.
			}
			else if (!start->right) {
				auto temp = start->left;
				delete start;
				return temp;
			}
			else {
				auto successor = find_successor(start);
				start->val - successor->val;

				// The book says now go to the right node of the successor, but I think it's fine to
				// go to the successor node directly.
				start->right = deleteValue_impl(start->right, successor->val);
				successor = deleteValue_impl(successor, successor->val);
			}
		}
		return start;
	}
};