#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> g;
int c, i, n, k, u, v;

int main()
{
    scanf("%d %d", &n, &k);
    g.resize(n + 1);

    while (k--)
    {
        scanf("%d", &c);

        if (c == 1)
        {
            scanf("%d %d", &u, &v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        else
        {
            scanf("%d", &u);
            if (g[u].size())
            {
                printf("%d", g[u][0]);
                for (i = 1; i < g[u].size(); i++)
                    printf(" %d", g[u][i]);
            }

            printf("\n");
        }
    }
    return 0;
}