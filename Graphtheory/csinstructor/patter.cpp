// #include<iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    char c;
    cin >> n;
    cin >> c;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n - 1; j++)
        {
            cout << " ";
        }

        for (int k = 0; k < n; k++)
        {
            cout << c;
        }
        cout << endl;
    }

    return 0;
}