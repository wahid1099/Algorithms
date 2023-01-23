#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

const int MAXN = 45;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

int n;
char grid[MAXN][MAXN];
bool visited[MAXN][MAXN];
int dist[MAXN][MAXN];
pair<int, int> parent[MAXN][MAXN];

bool isValid(int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < n && grid[x][y] == '.';
}

void printPath(pair<int, int> curr)
{
    if (grid[curr.first][curr.second] == '@')
        return;
    printPath(parent[curr.first][curr.second]);
    grid[curr.first][curr.second] = '+';
}

void bfs(pair<int, int> start, pair<int, int> end)
{
    queue<pair<int, int>> q;
    q.push(start);
    visited[start.first][start.second] = true;
    dist[start.first][start.second] = 0;

    while (!q.empty())
    {
        auto curr = q.front();
        q.pop();

        if (curr == end)
        {
            printPath(end);
            return;
        }

        for (int i = 0; i < 4; i++)
        {
            int x = curr.first + dx[i];
            int y = curr.second + dy[i];

            if (isValid(x, y) && !visited[x][y])
            {
                parent[x][y] = curr;
                dist[x][y] = dist[curr.first][curr.second] + 1;
                visited[x][y] = true;
                q.push({x, y});
            }
        }
    }
}

int main()
{
    cin >> n;
    pair<int, int> start, end;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == '@')
                start = {i, j};
            if (grid[i][j] == 'X')
                end = {i, j};
        }
    }

    memset(visited, false, sizeof(visited));
    bfs(start, end);

    if (dist[end.first][end.second] == 0)
    {
        cout << "N" << endl;
    }
    else
    {
        cout << "Y" << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << grid[i][j];
            }
            cout << endl;
        }
    }

    return 0;
}
