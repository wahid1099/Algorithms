// #include<iostream>
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> graph[N];
int n, k, u, v;
int main()
{

    cin >> n >> k;
    while (k--)
    {
        int operation;
        cin >> operation;
        if (operation == 1)
        {
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        else if (operation == 2)
        {
            int u;
            cin >> u;
            for (int i = 0; i < graph[u].size(); i++)
            {
                cout << graph[u][i] << " ";
            }
        }
    }

    return 0;
}