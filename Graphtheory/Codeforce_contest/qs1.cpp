// #include<iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string pi = "31415";
    int t;
    cin >> t;
    int ans = 0;

    while (t--)
    {
        string pi = "3141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342117069";
        string poly;
        cin >> poly;
        ans = 0;

        for (int i = 0; i < poly.size(); i++)
        {
            if (poly[0] == pi[0])
            {
                if (poly[i] == pi[i])
                {

                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}