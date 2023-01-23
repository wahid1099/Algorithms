#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX_N = 100, INF = 1e9; // set INF as a very large number

int n, r, d, v;                  // number of villages, bus lines, starting village, destination village
vector<pair<int, int>> g[MAX_N]; // graph represented as an adjacency list
int dist[MAX_N];                 // distance from the starting village
bool visited[MAX_N];             // check if a village has been visited

void Dijkstra()
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q; // min heap to get smallest distance
    fill(dist, dist + n, INF);                                                         // initialize distances as INF
    fill(visited, visited + n, false);                                                 // initialize all villages as not visited
    dist[d] = 0;                                                                       // distance from starting village to itself is 0
    q.push({0, d});                                                                    // push starting village to the queue

    while (!q.empty())
    {
        int curr = q.top().second;
        q.pop();
        if (visited[curr])
            continue; // if the village has been visited, skip
        visited[curr] = true;

        for (auto edge : g[curr])
        { // iterate through all edges
            int next = edge.first, w = edge.second;
            if (dist[next] > dist[curr] + w)
            {                                // if the current path is shorter than the previous one
                dist[next] = dist[curr] + w; // update the distance
                q.push({dist[next], next});  // push the next village to the queue
            }
        }
    }
}

int main()
{
    cin >> n >> d >> v >> r;
    d--;
    v--; // decrease the village number by 1 to match the array index
    while (r--)
    {
        int a, b, t1, t2;
        cin >> a >> t1 >> b >> t2;
        a--;
        b--;                          // decrease the village number by 1 to match the array index
        g[a].push_back({b, t2 - t1}); // add edge from a to b with weight t2 - t1
    }

    Dijkstra();

    if (dist[v] == INF)
        cout << -1; // if no path from d to v
    else
        cout << dist[v] + 1;
    return 0;
}
