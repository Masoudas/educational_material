/**
* Several improvements can be suggested on quicksort:
* 1-	Cutoff: Switching to insertion sort for small arrays (5 to 15 size) helps.
* 2-	Median of three partition: Choosing the median of three elements (so that we know the median
*	falls on one of the elements, not (a+b)/2, ensures randomness. Though, the cost of calculating median
*	need to be considered.
* 3-	Entropy-optimal sorting: Say we wanted to sort a personnel system usign quicksort, based on their
*	gender. The problem with quick sort is that it will go through all elements to sort them. What we can
*	do instead is to use a. So the suggestion would be to partition in a three way manner, so that the left
*	part has less than values, the middle part has equal values, and the top part has greater than values.
*   This is known as Dutch National Flag problem and was of course solved by none other than Dijkstra.
* 
*	Dijkstra you brilliant brilliant man. So here's the idea. We want the last of the array to be the greatest.
*   So when ever we see a greater element, we put it at the end. So define an index gt = hi, and then decrement
*   it every time. Now, the equal elements are like a snake. Say we have from index lt to lt + k of equal elements.
*   If we see an element which is less than at lt + k, we just need to exchange that element with lt. So now,
*   the snake is from lt + 1 to lt + k + 1. What is the initial value of lt? I'd have to say lt = lo, because 
*   this is the first element of equal value. So this partinioning is more costly than the normal partioning of
*   the quick-sort, because we actually make an exchange if say we didn't have that many equal elements.
*   Naturally, the stopping condition is when our indexer meets i.
* 
*   This was indeed lovely!
*/
#include <iostream>
using namespace std;

template <typename T>
void three_way_exchange(T*, T*);

template <typename T>
void three_way_partition(T* t, int lo, int hi) {
	int lt = lo; int gt = hi; int i = lo + 1;

	T v = *t;
	while (i <= gt) {
		T elem = *(t + i);

		if (elem == v) { i++; }
		else if (elem > v) { three_way_exchange(t + i, t + gt--); }
		else { three_way_exchange(t + i++, t + lt++); }
	}

}

template <typename T>
void three_way_exchange(T *elem1, T *elem2) {
	T t = move(*elem1);
	*elem1 = move(*elem2);
	*elem2 = move(t);
}

//int main() {
//	int arr[] = { 3, 1, 3, 2, 4, 2, 1 };
//	three_way_partition(arr, 0, 6);
//
//	for (auto val : arr)
//	{
//		cout << val << "\t";
//	}
//	cout << endl;
//}