// #include<iostream>
#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e9;
const int N = 1e5 + 5;
int d[N];
int parent[N];

int main()

{

    int n;
    cin >> n;
    int graph[n][n];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> graph[i][j];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        d[i] = INF;
    }

    int src = 1;
    d[src] = 0;

    for (int i = 1; i < n; i++)
    {
        for (int u = 1; u < n; u++)
        {
            for (int v = 1; v < n; v++)
            {
                if (d[u] + graph[u][v] < d[v])
                {
                    d[v] = d[u] + graph[u][v];
                    parent[v] = u;
                }
            }
        }
    }
    bool cycleNot = true;
    for (int u = 1; u <= n; u++)
    {
        for (int v = 1; v <= n; v++)
        {
            if (d[u] + graph[u][v] < d[v])
            {
                cycleNot = false;
                cout << "YES" << endl;

                int curr = v;
                vector<int> cycles;
                while (curr == src)
                {
                    cycles.push_back(curr);
                    curr = parent[curr];
                }
                cycles.push_back(curr);
                reverse(cycles.begin(), cycles.end());

                for (int i = 0; i < cycles.size(); i++)
                {
                    cout << cycles[i] << " ";
                }
                cout << endl;
            }
        }
    }

    if (cycleNot)
    {
        cout << "NO" << endl;
    }

    return 0;
}