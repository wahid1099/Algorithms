// https://github.com/farukshin/e-olymp/blob/master/1000-1999/1455/1455.cpp

// problem link - https://cses.fi/problemset/task/1197

#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const long long INF = 1e18;

vector<pair<int, int>> adj_list[N];
long long d[N];

int graph[N][N];

int parent[N];

int main()
{

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        d[i] = INF;
    }

    for (int i = 1; i <= n; i++)
    {

        for (int j = 1; j <= n; j++)
        {
            cin >> graph[i][j];
        }
    }

    bool negative_cycle = false;
    int last_updated_node = -1;
    d[1] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int node = 1; node <= n; node++)
        {
            for (int v = 1; v <= n; v++)
            {

                if (d[v] > d[node] + graph[i][node])
                {
                    d[v] = d[node] + d[node];
                    parent[v] = node;
                    if (i == n)
                    {
                        negative_cycle = true;
                        last_updated_node = v;
                    }
                }
            }
        }
    }
    if (negative_cycle == true)
    {
        cout << "YES" << endl;

        int selected_node = last_updated_node;
        for (int i = 1; i <= n - 1; i++)
        {
            selected_node = parent[selected_node];
        }

        int first_node = selected_node;

        vector<int> cycle;
        cycle.push_back(selected_node);

        while (true)
        {
            selected_node = parent[selected_node];
            cycle.push_back(selected_node);
            if (selected_node == first_node)
            {
                break;
            }
        }

        reverse(cycle.begin(), cycle.end());

        for (int node : cycle)
        {
            cout << node << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}
