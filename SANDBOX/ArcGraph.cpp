#include <cassert>
#include "ArcGraph.h"

ArcGraph::ArcGraph(int size) : size_(size) {}

ArcGraph::ArcGraph(const IGraph& graph) {
	size_ = graph.VerticesCount();

	for (int from = 0; from < graph.VerticesCount(); ++from) {
		for (int to : graph.GetNextVertices(from)) {
			edges_.emplace_back(from, to);
		}
	}
}

void ArcGraph::AddEdge(int from, int to) {
	assert(0 <= from && from < size_);
	assert(0 <= to && to < size_);
	edges_.emplace_back(from, to);
}

int ArcGraph::VerticesCount() const {
	return size_;
}

std::vector<int> ArcGraph::GetNextVertices(int vertex) const {
	assert(0 <= vertex && vertex < size_);
	std::vector<int> nextVertices;
	for (auto& edge : edges_) {
		if (edge.first == vertex) {
			nextVertices.push_back(edge.second);
		}
	}
	return nextVertices;
}

std::vector<int> ArcGraph::GetPrevVertices(int vertex) const {
	assert(0 <= vertex && vertex < size_);
	std::vector<int> prevVertices;
	for (auto& edge : edges_) {
		if (edge.second == vertex) {
			prevVertices.push_back(edge.first);
		}
	}
	return prevVertices;
}
