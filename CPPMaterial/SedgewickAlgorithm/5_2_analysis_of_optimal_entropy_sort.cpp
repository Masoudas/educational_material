/**
* We can show that quicksort uses 2ln2NH number of compares to sort an array of N elements,
* where H is the shannon entropy.
* 
* Hence, a suggestion for checking whether to use two way or three way sort is to compute the entropy
* of the array before sorting.
* 
* Question: How does one calculate the entropy? A better question would be, given an array, how can we 
* calculate how many times an element is repeated? The answer is simple (thanks to Mr. Bjarne). We use a
* dictionary. This of course requires memory usage. 
* If we didn't want to use memory, we could've used a loop to scan from start to end.
* If this wasn't for sort purposes, we could've sorted the array first :D
* 
*/
#include <unordered_map>
#include <iostream>
#include <cmath>

using namespace std;

template <typename T>
class entropy_calculator {
public:
	static double calculate(T* start, T* end) {
		double N = end - start;
		unordered_map<T, int> map{};
		while (start < end)
		{
			++map[*start];
			start++;
		}

		cout << "Printing Repetitions:" << endl;
		for (auto var : map)
		{
			cout << var.first << '\t' << var.second << endl;
		
		}

		double entropy = 0;
		for (auto pair : map) {
			double p = pair.second / N;
			entropy += -p * log2(p);
		}
		return entropy;
	}
};

//int main() {
//	int arr[] = { 1, 2, 3, 4 };
//
//	double entropy = entropy_calculator<int>::calculate(arr, arr+4);
//
//	cout << "Entropy is: " << entropy;
//}