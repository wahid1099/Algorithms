#include <bits/stdc++.h>
using namespace std;

int t, n, k, blueberries[10010];

int dp[10010];

int main()
{
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        memset(dp, 0, sizeof dp);
        cin >> n >> k;
        for (int j = 0; j < n; j++)
        {
            cin >> blueberries[j];
        }
        for (int j = 0; j < n; j++)
        {
            for (int l = min(j + 1, k - 1); l >= 1; l--)
            {
                dp[l] = max(dp[l], dp[l - 1] + blueberries[j]);
            }
        }
        cout << "Scenario #" << i << ": " << dp[k - 1] << endl;
    }
    return 0;
}
