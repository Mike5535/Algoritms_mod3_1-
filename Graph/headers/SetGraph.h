#include "../headers/IGraph.h"
#include <cassert>
#include <set>
#include <vector>

using std::vector;

class SetGraph : public IGraph {
    vector<std::set<int>> list_adj;

    public:
        SetGraph(int size);

        vector<int> GetNextVertices(int vertex) const override;

        SetGraph(const IGraph& graph);

        void AddEdge(int from, int to) override;

        int VerticesCount() const override;

        vector<int> GetPrevVertices(int vertex) const override;
};
