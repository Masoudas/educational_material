/**
* To avoid using n^2 space to save the nodes of a graph, we can think of a couple of solutions. An interesting
* one is to use a vector of vector of pairs of ints. The pair serves the purpose of indicating the 'to node 
* connection'. For example if node 1 is connected to 2 by 900, then the pair would be (2, 900). indicating
* the connection. This would allow the size of the graph to grow as the number of edges (and in fact because
* we're implementing bidirectional graphs, as twice the number of edges).
*/

#include <iostream>
#include <vector>
#include <algorithm>

enum class city : int {
	Mashhad = 0, Marseille, Istanbul, London, Tehran
};

class graph {
	using edge = std::pair<int, int>;
	std::vector<std::vector<edge>> edges;

	graph(int n) {
		edges = std::vector<std::vector<edge>>(n, std::vector<edge>{});
	}

	void addEdge(city c1, city c2, int distance) {
		auto n1 = static_cast<int>(c1);
		auto n2 = static_cast<int>(c2);

		edges[n1].push_back({ n2, distance });
		edges[n2].push_back({ n1, distance });
	}

	void removeEdge(city c1, city c2, int distance) {
		auto n1 = static_cast<int>(c1);
		auto n2 = static_cast<int>(c2);

		std::remove_if(
			edges[n1].begin(), edges[n1].end(), [n2](const edge& e) { return e.first == n2; });
		std::remove_if(
			edges[n2].begin(), edges[n2].end(), [n1](const edge& e) { return e.first == n1; });
	}
};