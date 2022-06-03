#include "../headers/IGraph.h"
#include <cassert>
#include <vector>

using std::vector;

class ListGraph : public IGraph{
    vector<vector<int>> list_adj;

    public:
        ListGraph(int size);

        void AddEdge(int from, int to) override ;

        int VerticesCount() const override;

        ListGraph(IGraph& graph) ;   

        vector<int> GetNextVertices(int vertex) const override;

        vector<int> GetPrevVertices(int vertex) const override;
};
