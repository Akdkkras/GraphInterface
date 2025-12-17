#pragma once
#include "IGraph.h"

class MatrixGraph : public IGraph {
public:
	MatrixGraph(int size);
	MatrixGraph(const IGraph& graph);
	~MatrixGraph() override = default;

	void AddEdge(int from, int to) override;
	int VerticesCount() const override;

	std::vector<int> GetNextVertices(int vertex) const override;
	std::vector<int> GetPrevVertices(int vertex) const override;

private:
	std::vector<std::vector<char>> adjacencyMatrix_;
};
