// #include<iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    int n;
    while (t--)
    {
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        int max_product = INT_MIN;
        int min_product = INT_MAX;
        int max_sum = INT_MIN;
        int min_sum = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int product = arr[i] * arr[j];
                int sum = arr[i] + arr[j];

                max_product = max(max_product, product);
                min_product = min(min_product, product);
                max_sum = max(max_sum, sum);
                min_sum = min(min_sum, sum);
            }
        }
        cout << max_product << " " << min_product << " " << max_sum << " " << min_sum << endl;
    }

    return 0;
}