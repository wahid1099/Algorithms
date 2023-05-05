#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 1e5 + 5;
vector<int> graph[MAXN];
int dp[MAXN];

int dfs(int u)
{
    if (dp[u] != -1)
    {
        return dp[u];
    }
    int ans = 0;
    for (int v : graph[u])
    {
        ans = max(ans, dfs(v) + 1);
    }
    dp[u] = ans;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
    }
    fill(dp, dp + n + 1, -1);
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, dfs(i));
    }
    cout << ans << "\n";
    return 0;
}
