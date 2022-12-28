// #include<iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int adjMat[n + 1][m + 1] = {};

    for (int i = 0; i <= n; i++)
    {
        int u, v;
        cin >> u >> v;
        adjMat[u][v] = 1;
        adjMat[v][u] = 1;
    }

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << adjMat[i][j] << " ";

        cout << endl;
    }

    return 0;
}
