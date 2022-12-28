// #include<iostream>
#include <bits/stdc++.h>
using namespace std;

int digitsum(int n)
{
    if (n == 0)
        return 0;

    return (n % 10 + digitsum(n / 10));
}

int main()
{

    int n = 7464;
    int result = digitsum(n);
    cout << "digitsum--" << result << endl;

    return 0;
}