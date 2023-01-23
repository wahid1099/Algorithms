#include <iostream>
#include <queue>
#include <utility>
using namespace std;

const int N = 2004;

int n;

bool visited[N][N];
int startX, startY, endX, endY;
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1}; // possible moves in x and y direction

int main()
{
    cin >> n;
    int table[n][n];
    for (int i = 0; i < n; i++)
    {
        string input;
        cin >> input;
        for (int j = 0; j < n; j++)
        {

            if (input[j] == '0')
            {
                table[i][j] = -1;
            }
            else if (input[j] == '.')
            {
                table[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << table[i][j];
        }
        cout << endl;
    }

    return 0;
}
