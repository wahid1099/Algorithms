// #include<iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{

    string word1, word2;
    bool found;
    vector<int> char_count(26);

    while (cin >> word1 >> word2)
    {

        found = true;

        for (char c : word1)
        {
            char_count[c - 'a']++;
        }

        for (char s : word2)
        {
            char_count[s - 'a']--;
            if (char_count[s - 'a'] < 0)
            {
                cout << "Impossible" << endl;
                found = false;
                break;
            }
        }
        if (found)
        {
            cout << "Possible" << endl;
        }
        char_count.clear();
    }
    return 0;
}