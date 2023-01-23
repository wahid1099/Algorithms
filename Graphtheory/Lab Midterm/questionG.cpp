#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 100005;

vector<int> adj[MAXN];
int parent[MAXN], n, m, visited[MAXN];

void dfs(int u)
{
    visited[u] = 1;
    for (int i = 0; i < adj[u].size(); i++)
    {
        int v = adj[u][i];
        dfs(v);
    }
}

int isParent(int u, int v)
{
    for (int i = 1; i <= n; i++)
        visited[i] = 0;
    dfs(u);
    if (visited[v])
        return 1;
    else
        return 0;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> parent[i];
        if (parent[i] != 0)
            adj[parent[i]].push_back(i);
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        cout << isParent(a, b) << endl;
    }
    return 0;
}
