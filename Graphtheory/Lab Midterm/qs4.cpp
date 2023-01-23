// #include<iostream>
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> graph[N];
queue<int> q;
int dist[N];
void bfs()
{
    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        for (int node : graph[front])
        {
            if (dist[node] == -1)
            {
                dist[node] = dist[front] + 1;
                q.push(node);
            }
        }
    }
}
int main()
{

    int n, m, k;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for (int i = 0; i <= n; i++)
    {
        dist[i] = -1;
    }

    int temp;
    cin >> k;
    while (k--)
    {
        cin >> temp;
        q.push(temp);
        dist[temp] = 0;
    }

    bfs();

    int v = 1;
    for (int i = 1; i <= n; i++)
    {
        if (dist[i] > dist[v])
        {
            v = i;
        }
    }

    cout << dist[v] << endl
         << v;
    return 0;
}