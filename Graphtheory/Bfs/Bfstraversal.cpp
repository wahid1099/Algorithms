// #include<iostream>
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
int visited[N];
vector<int> adj_list[N];
void bfs(int src)
{
    queue<int> q;
    visited[src] = 1;
    q.push(src);
    while (!q.empty())
    {
        int head = q.front();
        q.pop();
        cout << head << endl;

        for (int adj_node : adj_list[head])
        {
            if (visited[adj_node] == 0)
            {
                visited[adj_node] = 1;
                q.push(adj_node);
            }
        }
    }
}
int main()
{
    int node, edges;
    cin >> node >> edges;
    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    bfs(0);

    return 0;
}