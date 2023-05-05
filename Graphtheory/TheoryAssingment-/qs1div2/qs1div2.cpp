// #include<iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int nums[n];
        int count = 0, ans = 0;

        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
            if (nums[i] == -1)
            {
                count++;
            }
            else
            {
                ans++;
            }
        }

        if (ans > count)
        {
            cout << -ans << endl;
        }
        else
        {
            cout << count << endl;
        }
    }
    return 0;
}