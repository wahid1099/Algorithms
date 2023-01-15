#include <bits/stdc++.h>
using namespace std;

class DirectedGraph
{
public:
    int n;
    vector<vector<pair<int, int>>> graph;
    vector<int> dist;
    vector<int> longestPath;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    DirectedGraph(int num_nodes)
    {
        n = num_nodes;
        graph.resize(n + 1);
        dist.resize(n + 1, -1e9);
        longestPath.resize(n + 1, -1);
    }

    void add_edge(int u, int v, int w)
    {
        graph[u].push_back({v, w});
    }

    void longestPathLength(int s)
    {
        dist[s] = 0;
        pq.push({0, s});
        while (!pq.empty())
        {
            int u = pq.top().second;
            pq.pop();
            for (auto e : graph[u])
            {
                int v = e.first, w = e.second;
                if (dist[v] < dist[u] + w)
                {
                    dist[v] = dist[u] + w;
                    longestPath[v] = u;
                    pq.push({dist[v], v});
                }
            }
        }
    }
    void print_longest_path()
    {
        int maxPath = 0;
        int maxNode;
        for (int i = 2; i <= n; i++)
        {
            if (dist[i] > maxPath)
            {
                maxPath = dist[i];
                maxNode = i;
            }
        }
        cout << "Longest path is of length " << maxPath << endl;
        vector<int> path;
        while (maxNode != -1)
        {
            path.push_back(maxNode);
            maxNode = longestPath[maxNode];
        }
        reverse(path.begin(), path.end());
        cout << "Path :";
        for (auto x : path)
            cout << x << " ";
        cout << endl;
    }
};

int main()
{
    int n = 101;
    DirectedGraph G(n);
    for (int i = 2; i <= n; i++)
    {
        for (int j = 2; j <= n; j++)
        {
            if (j % i == 0)
            {

                G.add_edge(i, j, 1);
            }
        }
    }
    G.longestPathLength(2);
    G.print_longest_path();
    return 0;
}
