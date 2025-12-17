#pragma once
#include "IGraph.h"

class ArcGraph : public IGraph {
public:
	ArcGraph(int size);
	ArcGraph(const IGraph& graph);
	~ArcGraph() override = default;

	void AddEdge(int from, int to) override;
	int VerticesCount() const override;

	std::vector<int> GetNextVertices(int vertex) const override;
	std::vector<int> GetPrevVertices(int vertex) const override;

private:
	int size_;
	std::vector<std::pair<int, int>> edges_;
};
