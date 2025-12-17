#include "SetGraph.h"
#include <cassert>

SetGraph::SetGraph(int size) : adjacencyLists_(size) {}

SetGraph::SetGraph(const IGraph& graph) {
	adjacencyLists_.resize(graph.VerticesCount());
	for (int i = 0; i < graph.VerticesCount(); ++i) {
		std::vector<int> nextVertices = graph.GetNextVertices(i);
		adjacencyLists_[i] = std::unordered_multiset<int>(nextVertices.begin(), nextVertices.end());
	}
}

void SetGraph::AddEdge(int from, int to) {
	assert(0 <= from && from < adjacencyLists_.size());
	assert(0 <= to && to < adjacencyLists_.size());
	adjacencyLists_[from].insert(to);
}

int SetGraph::VerticesCount() const {
	return static_cast<int>(adjacencyLists_.size());
}

std::vector<int> SetGraph::GetNextVertices(int vertex) const {
	assert(0 <= vertex && vertex < adjacencyLists_.size());
	return std::vector<int>(adjacencyLists_[vertex].begin(), adjacencyLists_[vertex].end());
}

std::vector<int> SetGraph::GetPrevVertices(int vertex) const {
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
