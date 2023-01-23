/*
5
....X
.OOOO
.....
OOOO.
@....

*/
// #include<iostream>
#include <bits/stdc++.h>
using namespace std;
const int N = 2002;
int visited[N][N];
int level[N][N];
int maze[N][N];

int n, m;

int main()
{

    cin >> n;

    pair<int, int> src, dst;

    for (int i = 0; i < n; i++)
    {
        string input;
        cin >> input;
        cout << endl;

        for (int j = 0; j < n; j++)
        {

            if (input[j] == '.' || input[j] == 'X' || input[j] == '@')
            {

                maze[i][j] = -1;
            }
            else if (input[j] == 'X')
            {

                src = {i, j};
            }
            else if (maze[i][j] == '@')
            {
                dst = {i, j};
            }
        }
    }
    // //   for ouput
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout << maze[i][j] << "\t";
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    return 0;
}