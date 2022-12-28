// #include<iostream>
#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b)
{
    if (b == 0)
        return a;

    return gcd(b, a % b);
}

int main()
{
    int a = 63, b = 42;
    cout << "GCD of " << a << " and " << b << " is " << gcd(a, b);
    return 0;
}