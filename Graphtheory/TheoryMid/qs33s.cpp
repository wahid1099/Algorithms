#include <iostream>
#include <vector>
#include <stack>
using namespace std;

const int N = 100;
vector<int> graph[N + 2];
int longest[N + 2];
int parent[N + 2];
int visited[N + 2];
int ans;

void dfs(int u)
{
    visited[u] = 1;
    for (int v : graph[u])
    {
        if (visited[v] == 0)
        {
            if (longest[v] < longest[u] + 1)
            {
                longest[v] = longest[u] + 1;
                parent[v] = u;
                dfs(v);
            }
        }
    }
}

void printPath(int u)
{
    stack<int> path;
    while (u != 0)
    {
        path.push(u);
        u = parent[u];
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
    for (int i = 2; i <= N + 1; i++)
    {
        for (int j = i; j <= N + 1; j += i)
        {
            graph[i].push_back(j);
        }
    }

    for (int i = 2; i <= N + 1; i++)
    {
        if (!visited[i])
        {
            dfs(i);
        }
    }

       int start = 2;
    for (int i = 3; i <= N + 1; i++)
    {
        if (longest[i] > longest[start])
        {
            start = i;
        }
    }

    // print the longest path
    cout << "Longest path length: " << longest[start] << endl;
    cout << "Longest path: ";
    printPath(start);

    return 0;
}
