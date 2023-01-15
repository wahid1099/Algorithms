// #include<iostream>
#include <bits/stdc++.h>
using namespace std;

char pathstring[51][51];
int visited[51][51];

int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

int n, m;
int ans;

bool is_inside(int x, int y)
{

    if (x >= 0 && x < n && y >= 0 && y < m)
    {
        return true;
    }

    return false;
}

void dfs(int x, int y, int count)
{
    int i = 0;
    if (count > ans)
    {
        ans = count;
    }
    visited[x][y] = 1;

    for (i = 0; i < 8; i++)
    {
        int new_x = x + dx[i];
        int new_y = y + dy[i];
        if (is_inside(new_x, new_y) && pathstring[new_x][new_y] == pathstring[x][y] + 1 && visited[new_x][new_y] == 0)
        {

            dfs(new_x, new_y, count + 1);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int caseno = 1;

    while (1)
    {
        cin >> n >> m;
        if (n == 0 && m == 0)
            break;

        ans = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> pathstring[i][j];
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (pathstring[i][j] == 'A')
                {
                    dfs(i, j, 1);
                }
            }
        }

        cout << "Case " << caseno++ << ": " << ans << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                visited[i][j] = 0;
            }
        }
    }

    return 0;
}