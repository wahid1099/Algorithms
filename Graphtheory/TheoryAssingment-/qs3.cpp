#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

map<int, int> freq;
map<int, int> dp;

int delete_chain(int num)
{
    if (dp.count(num) > 0)
    {
        return dp[num];
    }
    int total = freq[num];
    if (freq.count(num + 1) > 0)
    {
        total += delete_chain(num + 1);
    }
    if (freq.count(num - 1) > 0)
    {
        total += delete_chain(num - 1);
    }
    dp[num] = total;
    return total;
}

int main()
{
    int n;
    cin >> n;
    int a;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        freq[a]++;
    }
    int max_points = 0;
    for (auto &f : freq)
    {
        max_points = max(max_points, delete_chain(f.first));
    }
    cout << max_points << endl;
    return 0;
}
