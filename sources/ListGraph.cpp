#include "../headers/ListGraph.h"

ListGraph::ListGraph(int size) {
    list_adj.resize(size);
}

void ListGraph::AddEdge(int from, int to){
    assert(from >= 0 && from < list_adj.size());
    assert(to >= 0 && to < list_adj.size());
    list_adj[from].push_back(to);
}

int ListGraph::VerticesCount() const {
    return list_adj.size();
}

ListGraph::ListGraph(IGraph& graph) {
    list_adj.resize(graph.VerticesCount());
    for (int i = 0; i < graph.VerticesCount(); i++){
        list_adj.push_back(graph.GetNextVertices(i));
        }
}           

vector<int> ListGraph::GetNextVertices(int vertex) const{
    assert(vertex >= 0 && vertex < list_adj.size());
    return list_adj[vertex];
}

vector<int> ListGraph::GetPrevVertices(int vertex) const{
    assert(vertex >= 0 && vertex < list_adj.size());
    vector<int> prev_vert;
    for (int num_vec = 0; num_vec < list_adj.size(); num_vec++) {
        for (int i = 0; i < list_adj[num_vec].size(); i++) {
             if (i == vertex) {
                  prev_vert.push_back(num_vec);
             }
        }
    }

    return prev_vert;
}

