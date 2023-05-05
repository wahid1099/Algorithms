// #include<iostream>
#include <bits/stdc++.h>
using namespace std;
// unordered_map<int,int> parent;

const int N = 1e5 + 5;

int parent[N];
int check_parent[N];

bool is_parent(int a, int b)
{
    if (parent[b] == a)
    {
        return true;
    }
    if (b == 0)
        return false;
    return is_parent(a, parent[b]);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        int l;
        cin >> parent[i];
        // parent[i] = l;
    }

    int m;
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;

        if (is_parent(a, b))
        {
            printf("1\n");
        }
        else
        {
            printf("0\n");
        }
    }
    return 0;
}