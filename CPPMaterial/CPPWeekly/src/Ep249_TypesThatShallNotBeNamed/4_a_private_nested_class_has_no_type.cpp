/**
* Private nested classes have no name either. It's quite interesting that we can return them
*/


struct Idiotic_Linked_List {
private:
	struct Node{};

public:
	Node return_node() {	// Here, we can return a node, because Node is defined in the scope.
		Node node{};
		return node;	
	}
};

auto return_node(Idiotic_Linked_List list) {	// Here, we have no choice, but to return using auto.
	return list.return_node();
}