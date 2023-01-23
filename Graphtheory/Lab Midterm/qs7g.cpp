#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>
using namespace std;

const int N = 1e5 + 5;
unordered_map<int, vector<int>> tree;
unordered_map<int, int> parent;
vector<bool> visited(N);
stringstream result;

void bfs(int src)
{
    visited[src] = true;

    for (int adj_node : tree[src])
    {
        if (!visited[adj_node])
        {
            parent[adj_node] = src;
            bfs(adj_node);
        }
    }
}

bool is_parent(int a, int b)
{
    if (parent.count(b) == 0)
        return false;
    if (parent[b] == a)
    {
        return true;
    }
    else
    {
        return is_parent(a, parent[b]);
    }
}
int main()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        int l;
        cin >> l;
        tree[l].push_back(i);
    }
    bfs(0);
    int m;
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        if (is_parent(a, b))
        {
            result << 1 << endl;
        }
        else
        {
            result << 0 << endl;
        }
    }
    cout << result.str();
    return 0;
}
