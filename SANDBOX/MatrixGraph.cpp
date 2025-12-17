#include <cassert>
#include "MatrixGraph.h"

MatrixGraph::MatrixGraph(int size) : adjacencyMatrix_(size, std::vector<char>(size, 0)) {}

MatrixGraph::MatrixGraph(const IGraph& graph) {
	adjacencyMatrix_.resize(graph.VerticesCount(), std::vector<char>(graph.VerticesCount(), 0));
	for (int from = 0; from < graph.VerticesCount(); ++from) {
		for (auto to : graph.GetNextVertices(from)) {
			adjacencyMatrix_[from][to] = 1;
		}
	}
}

void MatrixGraph::AddEdge(int from, int to) {
	assert(0 <= from && from < adjacencyMatrix_.size());
	assert(0 <= to && to < adjacencyMatrix_.size());
	adjacencyMatrix_[from][to] = 1;
}

int MatrixGraph::VerticesCount() const {
	return static_cast<int>(adjacencyMatrix_.size());
}

std::vector<int> MatrixGraph::GetNextVertices(int vertex) const {
	assert(0 <= vertex && vertex < adjacencyMatrix_.size());
	std::vector<int> nextVertices;
	for (int to = 0; to < adjacencyMatrix_.size(); ++to) {
		if (adjacencyMatrix_[vertex][to] == 1) {
			nextVertices.push_back(to);
		}
	}
	return nextVertices;
}

std::vector<int> MatrixGraph::GetPrevVertices(int vertex) const {
	assert(0 <= vertex && vertex < adjacencyMatrix_.size());
	std::vector<int> prevVertices;
	for (int from = 0; from < adjacencyMatrix_.size(); ++from) {
		if (adjacencyMatrix_[from][vertex] == 1) {
			prevVertices.push_back(from);
		}
	}
	return prevVertices;
}
