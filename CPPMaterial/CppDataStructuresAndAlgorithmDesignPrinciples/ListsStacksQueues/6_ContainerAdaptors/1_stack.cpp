/**
* This section is called adaptors, as we investigate containers that are built on top of other containers.
* 
* Stack is a single-ended deque, which implements the LIFO strategy. Seriously, if you check inside the
* implementation of stack, we see that it's implemented using a deque. 
*
* We normally prefer to use a deque as the underlying data structure of the stack. However, we can change
* what type of underlying container can be used by supplying it as a template parameter.
* As such, tt's interesting to note that there's no initializer list for the queue. I guess the reasoning is
* the implementation does not know what the underlying container is, it can't accept an initalizer_list (although
* we could ask, why not just use the push method with a for loop?!)
* Also note that as such, there's a templated move and copy constructor, which adapts the given template container
* to stack.
* 
* The most important methods are:
*	-	top 
*	-	push
*	-	pop
*	-	emplace
* 
* There is usually no overhead of forwarding the call to the underlying container as everything can be inlined
* by the compiler with optimizations.
*/

#include <stack>
#include <vector>

void create_a_stack_with_vector_container() {
	std::stack<int, std::vector<int>> stk{};

}


