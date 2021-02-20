/**
* Consider the following sum_all() function. Obviously, it calculates the sum of all elements in an array. Now,
* if we consider the 'Node' structure below, we see that it does the same operation, only for nodes. This computes 
* the sum of the ints in the singly-linked list implemented by the Nodes.
* 
* These two code fragments differ in detail and in style, but an experienced programmer will immediately say, 
* "Well, this is just two implementations of the accumulate algorithm." This is a popular algorithm. Like most 
* popular algorithms, it has many names, including reduce, fold, sum, and aggregate. However, let us try to 
* develop a general algorithm from the two concrete examples in stages, so as to get a feel for the process of 
* lifting.
* 
* First, we can abstract away the types that don't have to specific:
* -	int and double
* -	linked list and array.
* More over, we can write a pseudo-code for the algorithm as follows:
// pseudo code:
T sum(data)
// somehow parameterize by the value type and the container type
{
	T s = 0
	while (not at end) {
		s = s + current value
		get next data element
	}
	return s
}
* To make this concrete, we need three operations to access the "container" data structure:
* - Not at end of the container
* - Get current element
* - Get next element.
* 
* For the actual data, we need three ops too:
* - Initialization to zero.
* - Addition.
* - Return the result (which is essentailly being copiable or movable.)
* 
* Obviously, this is rather imprecise, but we can have the following implementation:
// concrete STL-like code:
template<typename Iter, typename Val>
Val sum(Iter first, Iter last)
{
	Val s = 0;
	while (first != last) {
		s = s + *first;
		++first;
	}
	return s;
}
* Here, I took advantage of knowing the usual STL way of representing a sequence of values. The sequence is 
* represented as a pair of iterators supporting three operations:
* - * for accessing the current element
* - ++ for moving to the next element
* - != for comparing iterators to check if we are at the end of a sequence.
* 
* We now hav e an algorithm (a function template) that can be used for both arrays and linked lists and for both 
* ints and doubles.
* 
* Note that to provide an iterator for the handcrafted linked list, we need to provide an iterator. We could do so,
* simply by providing stand-alone operators, rather than a concrete type, we we do below.
* 
* An OMG point on defining the overloaded operators: As we may recall, it's not allowed to define stand-alone 
* operators on pointers. Why? Because C++ has the sole authority on working with pointers. Hence for example, 
* operator++(Node*) is incorrect, because we're now defining how the increment operation on a data should work! In
* other words, the big guy has given us wrong examples on purpose in the book to let us recall this point!
* 
* Finally note that in this scheme, sum is as efficient as the original double one. We do not want to reach
* generality at the cost of efficiency.
*/

double add_all(double* array, int n)
// one concrete algorithm on array of doubles
{
	double s{ 0 };
	for (int i = 0; i < n; ++i)
		s = s + array[i];
	return s;
}

struct Node {
	Node* next;
	int data;
};

int sum_elements(Node* first, Node* last)
// another concrete algorithm on list of ints
{
	int s = 0;
	while (first != last) {
		s += first->data;
		first = first->next;
	}
	return s;
}

Node* operator++(const Node& node) { return node.next; }
int& operator*(Node& node) { return node.data; }

/*
Node* operator++(Node* p) { return p->next; }
int operator*(Node* p) { return p->data; }
*/

Node* end_node() { return nullptr; }