class Solution
{
public:
    void merge(vector<int> &num1, int m, vector<int> &num2, int n)
    {
        int k = (m + n - 1);

        int i = m - 1;
        int j = n - 1;
        while (i >= 0 && j >= 0)
        {
            if (num1[i] > num2[j])
            {
                num1[k--] = num1[i--];
            }
            else
            {
                num1[k--] = num2[j--];
            }
        }

        while (i >= 0)
        {
            num1[k--] = num1[i--];
        }

        while (j >= 0)
        {
            num1[k--] = num2[j--];
        }
        //  return num1;
    }
};