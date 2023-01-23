// #include<iostream>
#include <bits/stdc++.h>
using namespace std;
int visited[100][100];

int main()
{

    int n;
    cin >> n;
    int matrix[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }

    int countroeads = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == 1 && matrix[j][i] == 1)
            {
                countroeads++;
            }
        }
    }

    cout << countroeads / 2 << endl;

    return 0;
}