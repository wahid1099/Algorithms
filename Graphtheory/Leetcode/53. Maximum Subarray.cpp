class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int currsum = 0;
        int maxsum = -10000;
        for (auto &num : nums)
        {
            currsum = currsum < 0 ? num : currsum + num;
            maxsum = max(maxsum, currsum);
        }
        return maxsum;
    }
};

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int currsum = 0;
        int maxsum = -10000;
        for (auto &num : nums)
        {

            if (currsum < 0)
            {
                currsum = num;
            }
            else
            {
                currsum = currsum + num;
            }

            maxsum = max(maxsum, currsum);
        }
        return maxsum;
    }
};