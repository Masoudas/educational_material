/**
* A queue is essentially like stack, with the difference being that we can access both the front and the back
* of the queue.
* 
* Once again, note that we can change the underlying container of a queue. There's also no initializer_list.
* There's also the same templated copy and move constructor as stack.
*/

#include <queue>

void queue_example() {
	using std::queue;

	queue<int> q{};
	q.emplace(1);	// Same generic method as always.

	q.front();	// As always, returns a reference.
	q.pop();
}
