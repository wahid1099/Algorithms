#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, m;
vector<int> adj_list[N];
vector<int> parent;
vector<bool> visited;
int noofcities;
void dfs(int i, int par)
{
    parent[i] = par;
    visited[i] = true;
    for (auto child : adj_list[i])
    {
        if (child == par)
            continue;
        if (visited[child] && child != par)
        {
            vector<int> ans;
            int start = i;
            while (child != i)
            {
                ans.push_back(i);
                i = parent[i];
            }
            ans.push_back(child);
            ans.push_back(start);

            cout << ans.size() << endl;

            exit(0);
        }
        else
        {
            dfs(child, i);
        }
    }
}

int main()
{

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    parent.resize(N, -1);
    visited.resize(N, false);
    for (int i = 0; i < n; i++)
    {
        if (parent[i] == -1)
        {
            dfs(i, -1);
        }
    }
    cout << "IMPOSSIBLE";
}