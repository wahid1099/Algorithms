// #include<iostream>
#include <bits/stdc++.h>
using namespace std;
const int N = 1e7;
int visited[N];
vector<int> adj_list[N];
int hascats[N];

int n, m;
int ans;

bool isLeaf(int parent)
{
    for (auto u : adj_list[parent])
    {
        if (visited[u] == 0)
        {
            return false;
        }
    }
    return true;
}
void dfs(int src)
{

    visited[src] = 1;

    if (hascats[src] > m)
    {
        return;
    }

    if (isLeaf(src) && hascats[src] <= m)
    {
        ans++;
    }
    for (int adj_node : adj_list[src])
    {

        if (visited[adj_node] == 0)
        {
            if (hascats[adj_node] == 1)
            {
                hascats[adj_node] += hascats[src];
            }
            dfs(adj_node);
        }
    }
}

int main()
{

    cin >> n >> m;

    int u, v;
    for (int i = 1; i <= n; i++)
    {

        cin >> hascats[i];
    }

    for (int i = 1; i < n; i++)
    {
        cin >> u >> v;

        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    ans = 0;
    dfs(1);

    cout << ans << endl;
    return 0;
}