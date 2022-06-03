#include "../headers/IGraph.h"
#include <cassert>
#include <vector>

using std::vector;

class MatrixGraph : public IGraph {
    vector<vector<bool>> adjacencyMatrix;

    public:
        MatrixGraph(int size);

        MatrixGraph(IGraph& graph);

        void AddEdge(int from, int to) override;

        int VerticesCount() const override;

        vector<int> GetPrevVertices(int vertex) const override;

        vector<int> GetNextVertices(int vertex) const override;
};
