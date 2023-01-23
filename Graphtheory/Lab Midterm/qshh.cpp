#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1e9;

vector<pair<int, int>> adj[105];
int dist[105], n, m, cost[105];

void dijkstra(int start)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 1; i <= n; i++)
        dist[i] = INF;
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty())
    {
        int curr = pq.top().second;
        pq.pop();

        for (auto u : adj[curr])
        {
            int next = u.first, weight = u.second;
            if (dist[next] > dist[curr] + weight)
            {
                dist[next] = dist[curr] + weight;
                pq.push({dist[next], next});
            }
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> cost[i];
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back({b, cost[a]});
        adj[b].push_back({a, cost[b]});
    }

    dijkstra(1);
    if (dist[n] == INF)
        cout << -1;
    else
        cout << dist[n];
    return 0;
}
