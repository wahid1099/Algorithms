// #include<iostream>
#include <bits/stdc++.h>
using namespace std;

void printCombination(vector<int> const &output)
{

    cout << "{ ";
    for (int i : output)
    {
        cout << i << ", ";
    }
    cout << "} ";
    cout << endl;
}

void findcombination(int i, int n, vector<int> &output)
{
    if (n == 0)
    {
        printCombination(output);
    }

    for (int k = n; k >= i; k--)
    {
        output.push_back(k);
        findcombination(k, n - k, output);

        output.pop_back();
    }
}
int main()
{
    int n = 5;

    vector<int> output;
    findcombination(1, n, output);

    return 0;
}