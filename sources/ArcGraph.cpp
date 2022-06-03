#include "../headers/ArcGraph.h"

ArcGraph::ArcGraph(int size){
    list_pair.resize(size);
}

int ArcGraph::VerticesCount() const{
    vector<int> vert;

    for (const std::pair<int, int>& edges : list_pair) {
        auto res = std::find(std::begin(vert), std::end(vert), edges.first);
        if (res == std::end(vert))
            vert.push_back(edges.first);
        res = std::find(std::begin(vert), std::end(vert), edges.second);
        if (res == std::end(vert))
            vert.push_back(edges.second);
    }
return vert.size();
}

vector<int> ArcGraph::GetNextVertices(int vertex) const{
    vector<int> next;

    for (const std::pair<int,int>& edges : list_pair) {
        if (edges.first == vertex)
            next.push_back(edges.second);
    }
return next;
}

ArcGraph::ArcGraph(IGraph& graph){
    for (int from = 0; from < graph.VerticesCount(); from++){
        for (int to = 0; to < graph.GetNextVertices(from).size(); to++) {
            std::pair<int, int> pair(from, to);
            list_pair.push_back(pair);
        }
    }
}

void ArcGraph::AddEdge(int from, int to){
    std::pair<int, int> pair(from, to);
    list_pair.push_back(pair);
}

vector<int> ArcGraph::GetPrevVertices(int vertex) const{
    vector<int> prev;

    for (auto& edges : list_pair){
        if (edges.second == vertex)
            prev.push_back(edges.first);
    }
    return prev;
}
