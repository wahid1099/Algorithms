// #include<iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{

    int nodes = 4;
    vector<int> adject_list[nodes];

    adject_list[0] = {1};
    adject_list[1] = {0, 2, 3};
    adject_list[2] = {1, 3};
    adject_list[3] = {1, 2};

    for (int i = 0; i < nodes; i++)
    {
        cout << i << "->";
        for (int j = 0; j < adject_list[i].size(); j++)
        {
            cout << adject_list[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}