// #include<iostream>
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> tree[N];
// int parent[N];
int visited[N];
int parent[N];

bool is_parent(int a, int b)
{
    if (a > b)
    {
        return false;
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

    for (int i = 1; i <= n; i++)
    {
        int l;
        cin >> l;
        parent[i] = l;
    }

    int m;
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;

        if (is_parent(a, b))
        {
            cout << 1 << endl;
        }
        else
        {
            cout << 0 << endl;
        }
    }
    return 0;
}