int solve(vector<pair<int, int>> &p, vector<int> &dp, int i)
{
    if (i == 0)
    {
        return p[0].second;
    }
    if (dp[i] != -1)
    {
        return dp[i];
    }
    int ans = p[i].second;
    for (int j = 0; j < i; j++)
    {
        if (p[j].second <= p[i].second)
        {
            ans = max(ans, p[i].second + solve(p, dp, j));
        }
    }
    dp[i] = ans;
    return ans;
}

int bestTeamScore(vector<int> &scores, vector<int> &ages)
{
    int n = scores.size();
    vector<pair<int, int>> p(n);
    for (int i = 0; i < n; i++)
    {
        p[i] = make_pair(ages[i], scores[i]);
    }
    sort(p.begin(), p.end());
    vector<int> dp(n, -1);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, solve(p, dp, i));
    }
    return ans;
}
