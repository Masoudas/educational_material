/**
* We want to implement a k-way merge sort (keep in mind that there's a function in std for doing so for two
* vectors).
* 
* Officially, the problem is: 'Consider a biomedical application related to genetics being used for processing 
* large datasets. It requires ranks of DNA in a sorted manner to calculate similarity. But since the dataset 
* is huge, it can't fit on a single machine. Therefore, it processes and stores data in a distributed cluster, 
* and each node has a set of sorted values. The main processing engine requires all of the data to be in a 
* sorted fashion and in a single stream. So, basically, we need to merge multiple sorted arrays into a single 
* sorted array. Simulate this situation with the help of vectors.'
* To make this problem more interesting, the main frame is going to demand data from the nodes.
* 
* So we assume that we have all the data from each machine. Point is that in the heap we create to find the minimum
* element, we need track of from which machine we extract an element, and then replace it with the same machine 
* data (except unless we run out of data from that machine).
*/

#include <queue>
#include <vector>
#include <iostream>

struct node {
	int machine;
	int data;

	friend bool operator>(const node& n1, const node& n2) {
		return n1.data > n2.data;
	}
};

std::vector<int> v1 = { 1, 3, 8, 15, 105 };
std::vector<int> v2 = { 2, 3, 10, 11, 16, 20, 25 };
std::vector<int> v3 = { -2, 100, 1000 };
std::vector<int> v4 = { -1, 0, 14, 18 };

node* get_node_data(int machine) {
	node* data = nullptr;
	switch (machine)
	{
	case 1:
		if (v1.size()) {
			data = new node{ machine, v1.front() };
			v1.erase(v1.begin());
		}
		return data;
		
	case 2:
		if (v2.size()) {
			data = new node{ machine, v2.front() };
			v2.erase(v2.begin());
		}
		return data;

	case 3:
		if (v3.size()) {
			data = new node{ machine, v3.front() };
			v3.erase(v3.begin());
		}
		return data;

	case 4:
		if (v4.size()) {
			data = new node{ machine, v4.front() };
			v4.erase(v4.begin());
		}

		return data;
	}
}


class kway_merge_sort {
	std::priority_queue<node, std::vector<node>, std::greater<>> min_data{};
public:
	kway_merge_sort(int n) {
		for (int i = 0; i < n; i++) {
			min_data.emplace(*get_node_data(i + 1));
		}
	}

	bool has_next() {
		return min_data.size();
	}

	int get_next() {
		auto node = min_data.top();
		min_data.pop();

		auto next_data = get_node_data(node.machine);
		if (next_data) {
			min_data.push(std::move(*next_data));
		}

		return node.data;
	}
};


//int main() {
//	kway_merge_sort sorter{4};
//	while (sorter.has_next()){
//		std::cout << sorter.get_next() << ' ';
//	}
//}