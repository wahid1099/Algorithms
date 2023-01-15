// #include<iostream>
#include <bits/stdc++.h>
using namespace std;

const int N = 101;

vector<int> adj_list[N];

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
        cout << i << "->";
        for (int &x : adj_list[i])
        {
            cout << x << ", ";
        }
        cout << endl;
    }

    return 0;
}