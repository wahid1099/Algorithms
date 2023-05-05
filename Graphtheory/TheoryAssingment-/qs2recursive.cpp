#include <bits/stdc++.h>
using namespace std;

int t, n, k, blueberries[10010];

int dp[10010];

int solve(int i, int j)
{
    if (j == 0 || i == n)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int take = 0, skip = 0;
    if (j >= i + 1)
    {
        take = blueberries[i] + solve(i + 1, j - (i + 1));
    }
    skip = solve(i + 1, j);
    return dp[i][j] = max(take, skip);
}

int main()
{
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        memset(dp, -1, sizeof dp);
        cin >> n >> k;
        for (int j = 0; j < n; j++)
        {
            cin >> blueberries[j];
        }
        cout << "Scenario #" << i << ": " << solve(0, k) << endl;
    }
    return 0;
}

/*

Explanation:

t is the number of test cases
n is the number of blueberry bushes
k is the maximum number of blueberries Teresa can pick
blueberries is an array that stores the number of blueberries in each bush
dp is a 2D array that stores the result of subproblems
solve is a recursive function that calculates the maximum number of blueberries Teresa can pick from the first i bushes with the constraint of picking at most j blueberries
In each call of solve, Teresa either picks blueberries from the i-th bush or skips the i-th bush
If Teresa picks blueberries from the i-th bush, then j decreases by i + 1
If Teresa skips the i-th bush, then j remains the same
The function returns the maximum number of blueberries Teresa can pick in either case
The outer loop iterates through each test case
The result for each test case is calculated using the solve function and printed using cout



MD Wahid
do it without dp
Here is an example solution to the problem without dynamic programming in C++:

c
Copy code
#include <bits/stdc++

Stop generating

*/
