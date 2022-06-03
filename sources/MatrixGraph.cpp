#include "../headers/MatrixGraph.h"

MatrixGraph::MatrixGraph(int size){
    adjacencyMatrix.resize(size, vector<bool>(size, false));
}

vector<int> MatrixGraph::GetNextVertices(int vertex) const{
    vector<int> next_vert;
    assert(vertex >= 0 && vertex < adjacencyMatrix.size());
    for (int i = 0; i < adjacencyMatrix.size(); i++) {
        if (adjacencyMatrix[vertex][i])
            next_vert.push_back(i);
    }
    return next_vert;
}

MatrixGraph::MatrixGraph(IGraph& graph){
    adjacencyMatrix.resize(graph.VerticesCount(), vector<bool>(graph.VerticesCount(), false));
    vector<int> next;
    for (int i = 0; i < graph.VerticesCount(); i++){
        next = graph.GetNextVertices(i);
            for (int  j = 0; j < next.size();j++) {
                adjacencyMatrix[i][j] = true;
            }
    }
}

void MatrixGraph::AddEdge(int from, int to){
        assert(from >= 0 && from < adjacencyMatrix.size());
        assert(to >= 0 && to < adjacencyMatrix.size());
        adjacencyMatrix[from][to] = true;
}

int MatrixGraph::VerticesCount() const{
    return (int)adjacencyMatrix.size();
}

vector<int> MatrixGraph::GetPrevVertices(int vertex) const{
    assert(vertex >= 0 && vertex < adjacencyMatrix.size());
    vector<int> prev_vert;

    for (int i = 0; i < adjacencyMatrix.size(); i++){
            if (adjacencyMatrix[i][vertex])
                prev_vert.push_back(i);
    }

    return prev_vert;
}
