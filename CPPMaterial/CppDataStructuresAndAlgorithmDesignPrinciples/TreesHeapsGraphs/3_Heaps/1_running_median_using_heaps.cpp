/**
* In this exercise, we're going to solve the long standing median value problem. The idea is that we'll have
* a min heap and a max heap. We try and balance the weight of each heap so that at most half, or half plus one
* element resides in a heap at each time. This way, we can simply calculate the median. For the first two elements,
* we need to write an if condition to jump start the two heaps (which could go into the constructor as well.) 
* Now, we can approach this problem two fold, either consider the weight of the heaps, or the value just put in.
* Let's start with the value:
* - If the new value is less than the median, it must go to the maxHeap. Now, if maxHeap has more elements than
* minHeap, let's pass its top there. 
* - Do the reverse if new value is greater than median.
* - To calculate the median, check which heap has more elements and return that heap. Otherwise, return the average
* of both heaps (IMPORTANT NOTE: Note how the average is calculated. If I had written (min + max) / 2, it would have
* been incorrect, because the result of this computation is an integer!!!. Be careful).
* 
* To understand why this approach works, suppose val <= median. Then, if maxHeap has one element more than min and
* now we add new value, we should pass its top to min to be alright, making the heaps balanced. If heaps were 
* balanced and now we add new element, its fine to move the top to the minHeap as well.
*/
#include <queue>
#include <iostream>

using std::priority_queue;

class median {
	priority_queue<int> maxHeap{};
	priority_queue<int, std::vector<int>, std::greater<>> minHeap{};

public:
	//void insert(int data) {
	//	// First element
	//	if (maxHeap.size() == 0)
	//	{
	//		maxHeap.push(data);
	//		return;
	//	}
	//	if (maxHeap.size() == minHeap.size())
	//	{
	//		if (data <= get())
	//			maxHeap.push(data);
	//		else
	//			minHeap.push(data);
	//		return;
	//	}
	//	if (maxHeap.size() < minHeap.size())
	//	{
	//		if (data > get())
	//		{
	//			maxHeap.push(minHeap.top());
	//			minHeap.pop();
	//			minHeap.push(data);
	//		}
	//		else
	//			maxHeap.push(data);
	//		return;
	//	}
	//	if (data < get())
	//	{
	//		minHeap.push(maxHeap.top());
	//		maxHeap.pop();
	//		maxHeap.push(data);
	//	}
	//	else
	//		minHeap.push(data);
	//}
	void insert(int val) {
		if (!maxHeap.size()) {
			maxHeap.emplace(val);
			return;
		}

		if (val <= get()) {
			maxHeap.emplace(val);
			if (maxHeap.size() > minHeap.size()) {
				minHeap.emplace(maxHeap.top());
				maxHeap.pop();
			}
		}
		else {
			minHeap.emplace(val);
			if (minHeap.size() > maxHeap.size()) {
				maxHeap.emplace(minHeap.top());
				minHeap.pop();
			}
		}

	}

	double get() {
		if (minHeap.size() == maxHeap.size()) return (minHeap.top() + maxHeap.top()) / 2.0;
		if (minHeap.size() < maxHeap.size()) return maxHeap.top();
		return minHeap.top();
	}
}; 

//int main()
//{
//	median med;
//	med.insert(5);
//	std::cout << "Median after insert 5: " << med.get() << std::endl;
//	med.insert(1);
//	std::cout << "Median after insert 1: " << med.get() << std::endl;
//	med.insert(4);
//	std::cout << "Median after insert 4: " << med.get() << std::endl;
//	med.insert(2);
//	std::cout << "Median after insert 2: " << med.get() << std::endl;
//	med.insert(3);
//	std::cout << "Median after insert 3: " << med.get() << std::endl;
//	med.insert(100);
//	std::cout << "Median after insert 100: " << med.get() << std::endl;
//	med.insert(0);
//	std::cout << "Median after insert 0: " << med.get() << std::endl;
//	return 0;
//
//}