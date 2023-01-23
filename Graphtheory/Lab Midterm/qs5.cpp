
#include <bits/stdc++.h>
using namespace std;

const int N = 1604;
int visited[N][N];
int matrix[N][N];
char outpout[N][N];

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

int n;

bool is_inside(pair<int, int> coords)
{
    int x = coords.first;
    int y = coords.second;
    if (x >= 0 && x < n && y >= 0 && y < n)
    {
        return true;
    }

    return false;
}

bool issafe(pair<int, int> coord)
{
    int x = coord.first;
    int y = coord.second;
    if (matrix[x][y] == -2)
    {
        return false;
    }
    return true;
}
void bfs(pair<int, int> src)
{

    queue<pair<int, int>> q;
    visited[src.first][src.second] = 1;
    q.push(src);
    while (!q.empty())
    {

        pair<int, int> head = q.front();
        q.pop();
        int x = head.first;
        int y = head.second;

        for (int i = 0; i < 4; i++)
        {
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            pair<int, int> adj_node = {new_x, new_y};
            if (is_inside(adj_node) && issafe(adj_node) && visited[new_x][new_y] == 0)
            {
                // cout << "matrix is " << matrix[new_x][new_y] << endl;
                visited[new_x][new_y] = 1;
                q.push(adj_node);
                // outpout[adj_node.first][adj_node.second] = '+';
            }
        }
    }
}

int main()
{

    cin >> n;

    memset(outpout, '0', sizeof(outpout));
    pair<int, int> src, dst;

    for (int i = 0; i < n; i++)
    {
        string input;
        cin >> input;
        for (int j = 0; j < n; j++)
        {
            // cin >> matrix[i][j];
            if (input[j] == '.')
            {
                matrix[i][j] = -1;
            }

            else if (input[j] == 'X')
            {
                matrix[i][j] = -1;

                src = {i, j};
            }
            else if (input[j] == '@')
            {
                matrix[i][j] = -1;

                dst = {i, j};
            }
            else if (input[j] == '0')
            {
                matrix[i][j] = -2;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j];
        }
        cout << endl;
    }

    // bfs(src);

    // if (visited[dst.first][dst.second] == 0)
    // {
    //     cout << "N" << endl;
    // }
    // else
    // {

    //     for (int i = 0; i < n; i++)
    //     {
    //         for (int j = 0; j < n; j++)
    //         {
    //             if (visited[i][j] == 1)
    //             {
    //                 outpout[i][j] = '+';
    //             }
    //             else if (visited[i][j] == 0)
    //             {
    //                 outpout[i][j] = '0';
    //             }
    //         }
    //     }
    //     outpout[dst.first][dst.second] = '@';

    //     cout << "Y" << endl;

    //     for (int i = 0; i < n; i++)
    //     {
    //         for (int j = 0; j < n; j++)
    //         {
    //             cout << outpout[i][j];
    //         }
    //         cout << endl;
    //     }
    // }

    return 0;
}