

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
const int INF = 20001;

vector<pair<int, int>> adj_list[N];
vector<int> cost[N];

int nodes, edges;

int dist[N];
int homeTown;

void dijkstra(int src)
{
    for (int i = 0; i <= nodes; i++)
    {
        dist[i] = INF;
    }
    dist[src] = 0;

    queue<pair<long long, int>> pq;
    pq.push({0, src});

    while (!pq.empty())
    {

        pair<long long, int> head = pq.front();
        pq.pop();
        int selected_node = head.second;

        for (auto adj_entry : adj_list[selected_node])
        {
            int adj_node = adj_entry.first;
            int edge_cst = adj_entry.second;
            int temp = max(dist[selected_node], edge_cst);

            if (temp < dist[adj_node])
            {
                dist[adj_node] = temp;
                pq.push({dist[adj_node], adj_node});
            }
        }
    }
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    int caseNo = 0;
    while (t--)
    {

        cin >> nodes >> edges;

        for (int i = 0; i < edges; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            adj_list[u].push_back({v, w});
            adj_list[v].push_back({u, w});
        }

        cin >> homeTown;

        dijkstra(homeTown);

        cout << "Case " << ++caseNo << ":" << endl;
        for (int i = 0; i < nodes; i++)
        {
            if (dist[i] == INF)
            {
                cout << "Impossible" << endl;
            }
            else
            {
                cout << dist[i] << endl;
            }
        }

        for (int i = 0; i < nodes; i++)
        {
            adj_list[i].clear();
            cost[i].clear();
        }
    }

    return 0;
}

// 2

// 5 6
// 0 1 5
// 0 1 4
// 2 1 3
// 3 0 7
// 3 4 6
// 3 1 8
// 1

// 5 4
// 0 1 5
// 0 1 4
// 2 1 3
// 3 4 7
// 1
