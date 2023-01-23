
#include <bits/stdc++.h>
using namespace std;

const int N = 164;
int visited[N][N];
char matrix[N][N];
char outpout[N][N];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};
int n;
pair<int, int> src, dst;

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

    if (matrix[x][y] == '@' || matrix[x][y] == '.')
    {
        return true;
    }
    return false;
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
        if (x == dst.first && y == dst.second)
        {
            return;
        }
        outpout[x][y] = '+';

        for (int i = 0; i < 4; i++)
        {
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            pair<int, int> adj_node = {new_x, new_y};
            if (is_inside(adj_node) && issafe(adj_node) && visited[new_x][new_y] == 0)
            {
                visited[new_x][new_y] = 1;
                q.push(adj_node);
                // output[adj_node.first][adj_node.second] = '+';
            }
        }
    }
}

int main()
{

    cin >> n;

    memset(outpout, '0', sizeof(outpout));

    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];

            if (matrix[i][j] == 'X')
            {

                src = {i, j};
            }
            else if (matrix[i][j] == '@')
            {
                dst = {i, j};
            }
        }
    }

    /*
     for (int i = 0; i < n; i++)
     {
         for (int j = 0; j < n; j++)
         {

             cout << matrix[i][j] << " ";
         }
         cout << endl;
     }

     cout << "src" << src.first << src.second << endl;


 */
    bfs(src);

    if (visited[dst.first][dst.second] == 0)
    {

        cout << "N" << endl;
    }
    else
    {

        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = 0; j < n; j++)
        //     {
        //         if (visited[i][j] == 1)
        //         {
        //             outpout[i][j] = '+';
        //         }
        //     }
        // }
        outpout[dst.first][dst.second] = '@';

        cout << "Y" << endl;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << outpout[i][j];
            }
            cout << endl;
        }
    }

    return 0;
}