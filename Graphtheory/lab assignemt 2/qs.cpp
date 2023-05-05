class Solution
{

public:
    int numSquares(int n)
    {
        vector<int> dp(n + 1, -1);
        return ans(n, dp);
    }

    int ans(int n, vector<int> &dp)
    {

        if (n == 0)
            return 0;
        int minimum = n;
        if (dp[n] != -1)
            return dp[n];

        for (int i = 1; i * i <= n; i++)
        {
            int temp = i * i;

            int op = 1 + ans(n - temp, dp);
            minimum = min(minimum, op);
        }
        dp[n] = minimum;
        return dp[n];
    }
};