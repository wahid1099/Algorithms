#include <iostream>
using namespace std;

int collect_coins(int index, int n, int coins[], int dp[])
{
    if (index >= n)
    {
        return 0;
    }
    if (dp[index] != -1)
    {
        return dp[index];
    }
    int take_coins = coins[index] + collect_coins(index + 2, n, coins, dp);
    int skip_coins = collect_coins(index + 1, n, coins, dp);
    dp[index] = max(take_coins, skip_coins);
    return dp[index];
}

int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        int n;
        cin >> n;
        int coins[n];
        for (int j = 0; j < n; j++)
        {
            cin >> coins[j];
        }
        int dp[n];
        fill(dp, dp + n, -1);
        int result = collect_coins(0, n, coins, dp);
        cout << "Case " << i << ": " << result << endl;
    }
    return 0;
}

/*

                                                collect_coins(0, 5, [1, 2, 3, 4, 5])
                                                                /        |       \
                                            collect_coins(1, 5, [1, 2, 3, 4, 5])
                                                                /        |       \
                                            collect_coins(2, 5, [1, 2, 3, 4, 5])
                                                                /        |       \
                                            collect_coins(3, 5, [1, 2, 3, 4, 5])
                                                                /        |       \
                                            collect_coins(4, 5, [1, 2, 3, 4, 5])

    */
