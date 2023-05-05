class Solution
{
public:
    int tallestBillboard(vector<int> &rods)
    {
        unordered_map<int, int> dp = {{0, 0}};

        for (int r : rods)
        {
            unordered_map<int, int> newDp(dp);

            for (auto &[diff, taller] : dp)
            {
                int shorter = taller - diff;

                int newTaller = newDp[diff + r];
                newDp[diff + r] = max(newTaller, taller + r);

                int newDiff = abs(shorter + r - taller);
                int newTaller2 = max(shorter + r, taller);
                newDp[newDiff] = max(newTaller2, newDp[newDiff]);
            }

            dp = newDp;
        }

        return dp[0];
    }
};

// memorization

class Solution
{
public:
    int tallestBillboard(vector<int> &rods)
    {

        unordered_map<int, unordered_map<int, int>> memo;

        return helper(0, 0, 0, rods, memo);
    }

    int helper(int index, int sum1, int sum2, vector<int> &rods, unordered_map<int, unordered_map<int, int>> &memo)
    {
        if (index == rods.size())
        {
            if (sum1 == sum2)
            {
                return sum1;
            }
            else
            {
                return INT_MIN;
            }
        }

        if (memo.count(index) && memo[index].count(sum1))
        {
            return memo[index][sum1][sum2];
        }

        int max1 = helper(index + 1, sum1 + rods[index], sum2, rods, memo);
        int max2 = helper(index + 1, sum1, sum2 + rods[index], rods, memo);
        int max3 = helper(index + 1, sum1, sum2, rods, memo);

        int ans = max(max(max1, max2), max3);

        if (!memo.count(index))
        {
            memo[index] = unordered_map<int, int>();
        }
        if (!memo[index].count(sum1))
        {
            memo[index][sum1] = unordered_map<int, int>();
        }
        memo[index][sum1][sum2] = ans;

        return ans;
    }
};
