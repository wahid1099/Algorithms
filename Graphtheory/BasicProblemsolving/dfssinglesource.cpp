#include <iostream>
#include <vector>
#include <unordered_map>

void find_levels(const std::unordered_map<int, std::vector<int>> &graph,
                 int source,
                 int node,
                 int level,
                 std::unordered_map<int, int> &levels)
{
    levels[node] = level;
    for (int neighbor : graph.at(node))
    {
        if (levels.count(neighbor) == 0)
        { // neighbor has not been visited yet
            find_levels(graph, source, neighbor, level + 1, levels);
        }
    }
}

int main()
{
    std::unordered_map<int, std::vector<int>> graph = {
        {0, {1}},
        {1, {0, 2, 5}},
        {2, {1, 3, 4}},
        {3, {2}},
        {4, {2, 5}},
        {5, {1, 4}}};
    int source = 0;
    std::unordered_map<int, int> levels;
    find_levels(graph, source, source, 0, levels);
    for (const auto &[node, level] : levels)
    {
        std::cout << "The level of node " << node << " is " << level << std::endl;
    }
    return 0;
}
