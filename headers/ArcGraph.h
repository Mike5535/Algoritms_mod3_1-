#include "../headers/IGraph.h"
#include <vector>
#include <algorithm>

using std::vector;

class ArcGraph : public IGraph {
    vector<std::pair<int, int>> list_pair;

    public:
        ArcGraph(int size);

        int VerticesCount() const override;

        vector<int> GetNextVertices(int vertex) const override;

        ArcGraph(IGraph& graph);

        void AddEdge(int from, int to) override;

        vector<int> GetPrevVertices(int vertex) const override;
};
