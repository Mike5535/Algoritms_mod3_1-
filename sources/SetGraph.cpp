#include "../headers/SetGraph.h"

SetGraph::SetGraph(int size){
    list_adj.resize(size);
}

vector<int> SetGraph::GetNextVertices(int vertex) const{
    assert(vertex >= 0 && vertex < list_adj.size());
    vector<int> next(list_adj[vertex].begin(), list_adj[vertex].end());
    return next;
}

SetGraph::SetGraph(const IGraph& graph){
    list_adj.resize(graph.VerticesCount());
    for (int i = 0; i < graph.VerticesCount(); i++){
        for (auto& it : graph.GetNextVertices(i)){
            list_adj[i].insert(it);
        }
    }
}

void SetGraph::AddEdge(int from, int to){
    assert(from >= 0 && from < list_adj.size());
    assert(to >= 0 && to < list_adj.size());
    list_adj[from].insert(to);
}

int SetGraph::VerticesCount() const{
    return (int)list_adj.size();
}

vector<int> SetGraph::GetPrevVertices(int vertex) const{
    assert(vertex >= 0 && vertex < list_adj.size());
    vector<int> prev_vert;
    for (int from = 0; from < list_adj.size(); from++){
        for (int to : list_adj[from]){
            if (to == vertex){
                prev_vert.push_back(from);
            }
        }
    }
    return prev_vert;
}
