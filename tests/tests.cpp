#include <gtest/gtest.h>
#include "../headers/ListGraph.h"
#include "../headers/MatrixGraph.h"
#include "../headers/SetGraph.h"
#include "../headers/ArcGraph.h"
#include "../headers/BFS.h"

TEST(ListGraph, copy) {
    ListGraph graph(8);
    graph.AddEdge(1, 4);
    graph.AddEdge(1, 5);
    graph.AddEdge(1, 6);
    graph.AddEdge(2, 4);
    graph.AddEdge(2, 5);
    graph.AddEdge(2, 6);
    graph.AddEdge(3, 6);
    graph.AddEdge(3, 7);
 
    ListGraph graph1(graph);
    EXPECT_EQ(8, graph1.VerticesCount());
}

TEST(MatrixGraph, copy) {
    MatrixGraph graph(8);
    graph.AddEdge(1, 4);
    graph.AddEdge(1, 5);
    graph.AddEdge(1, 6);
    graph.AddEdge(2, 4);
    graph.AddEdge(2, 5);
    graph.AddEdge(2, 6);
    graph.AddEdge(3, 6);
    graph.AddEdge(3, 7);
 
    MatrixGraph graph1(graph);
    EXPECT_EQ(8, graph1.VerticesCount());
}

TEST(SetGraph, copy) {
    SetGraph graph(8);
    graph.AddEdge(1, 4);
    graph.AddEdge(1, 5);
    graph.AddEdge(1, 6);
    graph.AddEdge(2, 4);
    graph.AddEdge(2, 5);
    graph.AddEdge(2, 6);
    graph.AddEdge(3, 6);
    graph.AddEdge(3, 7);
 
    SetGraph graph1(graph);
    EXPECT_EQ(8, graph1.VerticesCount());
}

TEST(ArcGraph, copy) {
    ArcGraph graph(8);
    graph.AddEdge(1, 4);
    graph.AddEdge(1, 5);
    graph.AddEdge(1, 6);
    graph.AddEdge(2, 4);
    graph.AddEdge(2, 5);
    graph.AddEdge(2, 6);
    graph.AddEdge(3, 6);
    graph.AddEdge(3, 7);
 
    ArcGraph graph1(graph);
    EXPECT_EQ(8, graph1.VerticesCount());
}

TEST(ListGraph, bfs) {
    ListGraph graph(5);
    graph.AddEdge(0, 1);
    graph.AddEdge(0, 2);
    graph.AddEdge(1, 2);
    graph.AddEdge(1, 3);
    graph.AddEdge(2, 3);

    EXPECT_EQ(2, mainBFS<ListGraph>(graph, 0, 3));
}

TEST(ArcGraph, bfs) {
    ArcGraph graph(5);
    graph.AddEdge(0, 1);
    graph.AddEdge(0, 2);
    graph.AddEdge(1, 2);
    graph.AddEdge(1, 3);
    graph.AddEdge(2, 3);

    EXPECT_EQ(2, mainBFS<ArcGraph>(graph, 0, 3));
}

TEST(SetGraph, bfs) {
    SetGraph graph(5);
    graph.AddEdge(0, 1);
    graph.AddEdge(0, 2);
    graph.AddEdge(1, 2);
    graph.AddEdge(1, 3);
    graph.AddEdge(2, 3);

    EXPECT_EQ(2, mainBFS<SetGraph>(graph, 0, 3));
}

TEST(MatrixGraph, bfs) {
    MatrixGraph graph(5);
    graph.AddEdge(0, 1);
    graph.AddEdge(0, 2);
    graph.AddEdge(1, 2);
    graph.AddEdge(1, 3);
    graph.AddEdge(2, 3);

    EXPECT_EQ(2, mainBFS<MatrixGraph>(graph, 0, 3));
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
