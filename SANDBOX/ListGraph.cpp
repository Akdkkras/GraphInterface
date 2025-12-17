#include <cassert>
#include "ListGraph.h"

ListGraph::ListGraph(int size) : adjacencyLists_(size) {}

ListGraph::ListGraph(const IGraph& graph) {
	adjacencyLists_.resize(graph.VerticesCount());
	for (int i = 0; i < graph.VerticesCount(); ++i) {
		adjacencyLists_[i] = graph.GetNextVertices(i);
	}
}

void ListGraph::AddEdge(int from, int to) {
	assert(0 <= from && from < adjacencyLists_.size());
	assert(0 <= to && to < adjacencyLists_.size());
	adjacencyLists_[from].push_back(to);
}

int ListGraph::VerticesCount() const {
	return static_cast<int>(adjacencyLists_.size());
}

std::vector<int> ListGraph::GetNextVertices(int vertex) const {
	assert(0 <= vertex && vertex < adjacencyLists_.size());
	return adjacencyLists_[vertex];
}

std::vector<int> ListGraph::GetPrevVertices(int vertex) const {
	assert(0 <= vertex && vertex < adjacencyLists_.size());
	std::vector<int> prevVertices;

	for (int from = 0; from < adjacencyLists_.size(); ++from) {
		for (int to : adjacencyLists_[from]) {
			if (to == vertex)
				prevVertices.push_back(from);
		}
	}
	return prevVertices;
}
