// #include<iostream>
#include <bits/stdc++.h>
using namespace std;
const int N = 105;
vector<pair<int, int>> adj_list[N];
const int INF = 1e9;
int visited[N];
int d[N];
int n, m;
int gas[N];

void dijskra(int src)
{
    for (int i = 1; i <= n; i++)
    {
        d[i] = INF;
    }
    d[src] = 0;

    priority_queue<pair<int, int>> pq;
    pq.push({0, src});

    while (!pq.empty())
    {
        pair<int, int> head = pq.top();
        int selected_node = head.second;

        pq.pop();

        for (auto adj_node : adj_list[selected_node])
        {
            int next_node = adj_node.first;
            int edg_cost = adj_node.second;
            if (d[selected_node] + edg_cost < d[next_node])
            {
                d[next_node] = d[selected_node] + edg_cost;
                pq.push({d[next_node], next_node});
            }
        }
    }
}
int main()
{

    cin >> n;

    for (int i = 1; i < n; i++)
    {
        cin >> gas[i];
    }

    cin >> m;
    if (m == 0)
    {
        cout << -1;
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back({v, gas[v]});
        // adj_list[v].push_back({u, gas[u]});
    }
    dijskra(1);

    if (d[n] == INF)
    {
        cout << -1;
    }

    else
    {
        cout << d[n];
    }

    return 0;
}