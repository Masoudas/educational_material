/**
* We can represent a graph using its adjacency matrix. The adjacency matrix will hold the weight of each edge
* in the given direction (for unilateral graphs).
* 
* It's normally assumed that a graph has a prespecified number of nodes, but as the following example shows, this
* does not necessarily have to be the case, even with the following implementation.
* 
* In what follows, we implement the distance between cities as a graph, using adjaceny matrix. Note that a lack
* of connection is shown using -1.
* 
* The problem with this method is that the space required for representation of a graph is n^2. Using adjacency
* list however, we show that we can make the space proportional to the number of edges, as shown in the next
* section.
*/
#include <iostream>
#include <vector>

enum class city : int {
	Mashhad = 0, Marseille, Istanbul, London, Tehran
};

std::ostream& operator<<(std::ostream& o, city c) {
	switch (c) {
	case (city::Mashhad):
		o << "Mashhad";
		return o;
	case (city::Marseille):
		o << "Marseille";
		return o;
	case (city::Istanbul):
		o << "Istanbul";
		return o;
	case (city::London):
		o << "London";
		return o;
	case (city::Tehran):
		o << "Tehran";
		return o;
	}
}

using std::vector;
class graph_city {
	vector<vector<int>> adjacency;

	graph_city(int n) {
		adjacency.reserve(n);
		for (int i = 0; i < n; i++) {
			adjacency.emplace_back(n, -1);
		}
	}

	void addEdge(city c1, city c2, int distance) {
		std::cout << "ADD: " << c1 << "-" << c2 << std::endl;

		auto n1 = static_cast<int>(c1);
		auto n2 = static_cast<int>(c2);

		adjacency[n1][n2] = distance;
		adjacency[n2][n1] = distance;
	}

	void removeEdge(city c1, city c2, int distance) {
		std::cout << "REMOVE: " << c1 << "-" << c2 << std::endl;

		auto n1 = static_cast<int>(c1);
		auto n2 = static_cast<int>(c2);

		adjacency[n1][n2] = -1;
		adjacency[n2][n1] = -1;
	}
};
