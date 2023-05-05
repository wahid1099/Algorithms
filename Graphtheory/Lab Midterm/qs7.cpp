#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int INF = 1e9;
int level[N];
int level_reverse[N];
vector<int> graph[N];
int visited[N];
int n, m, u, v;
int cnt = 0;

void dfs(int src)
{
    level[src] = cnt++;
    visited[src] = 1;

    for (auto adj_node : graph[src])
    {
        dfs(adj_node);
    }

    level_reverse[src] = cnt++;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int src = -1;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> u;
        if (u != 0)
            graph[u].push_back(i);
        else
            src = i;
    }

    for (int i = 1; i <= n; i++)
    {
        level[i] = INF;
        level_reverse[i] = INF;
    }

    dfs(src);

    cin >> m;

    while (m--)
    {
        cin >> u >> v;
        if (level[u] < level[v] && level_reverse[u] > level_reverse[v])
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }

    return 0;
}
