#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

int n;
char grid[45][45];
int dist[45][45];

pair<int, int> start, dest;

bool is_valid(int x, int y)
{
    return (x >= 0 && x < n && y >= 0 && y < n);
}

void bfs(pair<int, int> start)
{
    queue<pair<int, int>> q;
    memset(dist, -1, sizeof dist);
    dist[start.first][start.second] = 0;
    q.push(start);

    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int new_x = p.first + dx[i];
            int new_y = p.second + dy[i];
            if (is_valid(new_x, new_y) && dist[new_x][new_y] == -1 && grid[new_x][new_y] != 'O')
            {
                dist[new_x][new_y] = dist[p.first][p.second] + 1;
                q.push({new_x, new_y});
            }
        }
    }
}

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'X')
            {
                start = {i, j};
            }

            if (grid[i][j] == '@')
            {
                dest = {i, j};
            }
        }
    }

    bfs(start);

    if (dist[dest.first][dest.second] == -1)
    {
        cout << "N" << endl;
        return 0;
    }

    cout << "Y" << endl;
    int x = start.first, y = start.second;
    while (grid[x][y] != '@')
    {
        grid[x][y] = '+';
        for (int i = 0; i < 4; i++)
        {
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            if (is_valid(new_x, new_y) && dist[new_x][new_y] == dist[x][y] - 1)
            {
                x = new_x;
                y = new_y;
                break;
            }
        }
    }
    grid[x][y] = '+';

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << grid[i][j];
        }
        cout << endl;
    }

    return 0;
}
