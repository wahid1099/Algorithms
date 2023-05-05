public
int rob(int[] nums)
{
    if (nums == null)
        return 0;
    int n = nums.length;
    if (n == 1)
        return nums[0];
    return Math.max(rob(nums, 1, n), rob(nums, 0, n - 1));
}

private
int rob(int[] nums, int start, int end)
{
    int last = 0, secondLast = 0, cur = 0;
    for (int i = start; i < end; i++)
    {
        cur = Math.max(nums[i] + secondLast, last);
        secondLast = last;
        last = cur;
    }
    return cur;
}

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        if (nums.size() == 1)
        {
            return nums[0];
        }
        if (nums.size() == 2)
        {
            return max(nums[0], nums[1]);
        }

        vector<int> dp(nums.size());
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i < nums.size() - 1; i++)
        {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        int max_money1 = dp[nums.size() - 2];
        dp[1] = nums[1];
        dp[2] = max(nums[1], nums[2]);

        for (int i = 2; i < nums.size() - 1; i++)
        {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        int max_money2 = dp[nums.size() - 1];

        return max(max_money1, max_money2);
    }
};

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;
        if (nums.size() == 1)
            return nums[0];
        int n = nums.size();
        int pre1 = nums[0], cur1 = max(nums[0], nums[1]);
        for (int i = 2; i < n - 1; i++)
        {
            int t = cur1;
            cur1 = max(pre1 + nums[i], cur1);
            pre1 = t;
        }

        int pre2 = 0, cur2 = nums[1];
        for (int i = 2; i < n - 1; i++)
        {
            int t = cur1;
            cur2 = max(pre1 + nums[i], cur1);
            pre2 = t;
        }

        return max(cur1, cur2);
    }
};