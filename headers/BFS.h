#include <vector>
#include <cassert>
#include <queue>
#include <functional>

template <typename T>
void BFS(T graph, int vert, std::vector<int>& nums, std::vector<int>& parent, std::vector<int>& distances)
{
    std::queue<int> qu;
    qu.push(vert);

    while (qu.empty() == 0)
    {
        int curr = qu.front();
        qu.pop();
        for (int next : graph.GetNextVertices(curr))
        {
            if (distances[next] > distances[curr] + 1)
            {
                distances[next] = distances[curr] + 1;
                parent[next] = curr;
                nums[next] = nums[curr];
                qu.push(next);
            }
            else if (distances[next] == distances[curr] + 1 && parent[next] != curr)
            {
                nums[next] += nums[curr];
            }
        }
    }
}

template <typename T>
int mainBFS(T& graph, int U, int V)
{
    std::vector<int> distances(graph.VerticesCount(), INT32_MAX);
    distances[U] = 0;

    std::vector<int> parent_index(graph.VerticesCount(), -1);
    std::vector<int> paths_nums(graph.VerticesCount(), 0);
    paths_nums[U] = 1;

    BFS(graph, U, paths_nums, parent_index, distances);

    return paths_nums[V];
}
