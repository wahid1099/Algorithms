// #include<iostream>
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> tree[N];
int parent[N];
int visited[N];

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    parent[src] = 0;

    visited[src] = 1;

    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        for (int adj_node : tree[front])
        {
            if (visited[adj_node] == 0)
            {
                parent[adj_node] = front;
                visited[adj_node] = 1;
                q.push(adj_node);
            }
        }
    }
}

bool is_parent(int a, int b)
{
    if (a == b)
    {
        return true;
    }
    while (b != 0)
    {

        if (parent[b] == a)
        {
            return true;
        }
        b = parent[b];
    }

    return false;
}
int main()
{

    int n;
    cin >> n;
    int parent[n];

    for (int i = 1; i <= n; i++)
    {
        int l;
        cin >> l;
        tree[l].push_back(i);
    }
    bfs(0);
    int m;
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        if (a == b || a == m)
        {
            cout << 0 << endl;
        }
        else
        {
            if (is_parent(a, b))
            {
                cout << 1 << endl;
            }
            else
            {
                cout << 0 << endl;
            }
        }
    }
    return 0;
}