#include <iostream>
#include <stack>
#include <vector>

using namespace std;

const int MAXN = 100;

int n;                 // number of nodes
vector<int> adj[MAXN]; // adjacency list for the graph
bool visited[MAXN];    // array to keep track of visited nodes

void dfs(int start)
{
    stack<int> s;
    s.push(start);

    while (!s.empty())
    {
        int v = s.top();
        s.pop();

        if (!visited[v])
        {
            visited[v] = true;
            cout << v << " ";

            for (int u : adj[v])
            {
                if (!visited[u])
                {
                    s.push(u);
                }
            }
        }
    }
}
// 1 5 4 0 2 3
//  output=1->4->2->3->0->5
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1); // start the search at node 0

    return 0;
}
