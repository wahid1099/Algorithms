#include <bits/stdc++.h>

using namespace std;

const int N = 101;

vector<int> adj_list[N];

int longest_paths[N];
int parent[N];
int visited[N];

void dfs(int node)
{

    visited[node] = 1;

    for (int adj_node : adj_list[node])
    {
        if (visited[adj_node] == 0)
        {
            if (longest_paths[adj_node] < longest_paths[node] + 1)
            {
                longest_paths[adj_node] = longest_paths[node] + 1;
                parent[adj_node] = node;
                dfs(adj_node);
            }
        }
    }
}

void printpath(int src)
{
    stack<int> path;
    while (src != 0)
    {
        path.push(src);
        src = parent[src];
    }

    while (!path.empty())
    {
        cout << path.top() << " ";
        path.pop();
    }
    cout << endl;
}
int main()
{
    for (int i = 2; i <= N; i++)
    {
        for (int j = 2; j <= N; j++)
        {
            if (j % i == 0)
            {
                adj_list[i].push_back(j);
            }
        }
    }

    for (int i = 2; i <= N; i++)
    {
        longest_paths[i] = 1;
    }

    for (int i = 2; i <= N; i++)
    {
        dfs(i);
    }

    int start = 2;

    for (int i = 3; i <= N; i++)
    {
        if (longest_paths[i] > longest_paths[start])
        {
            start = i;
        }
    }

    cout << "Longest path length: " << longest_paths[start] << endl;
    cout << "Longest path: ";
    printpath(start);

    return 0;
}
