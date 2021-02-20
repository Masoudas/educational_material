/**
* A tree is non-linear data structure, where each node has other nodes attached to it in a hierarchical
* order. 
* 
* For example, we can represent the hierarchy of courses one student needs to take before taken a particular
* course using trees
* 
* The data structure constitutes nodes, which hold references to child nodes. 
*/
#include <vector>

template <typename T>
struct node {
	T data;
	std::vector<node*> children;	// Can hold an arbitrary number of children.
};

node<int>* root = new node<int>{ 5, {nullptr, nullptr} };	// Yep!

