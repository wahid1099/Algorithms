#include <bits/stdc++.h>

using namespace std;

int main()
{
    string word1, word2;
    while (cin >> word1 >> word2)
    {
        vector<int> count1(26), count2(26);
        memset(count1.data(), 0, count1.size() * sizeof(int));
        memset(count2.data(), 0, count2.size() * sizeof(int));
        for (char c : word1)
        {
            count1[c - 'a']++;
        }
        for (char c : word2)
        {
            count2[c - 'a']++;
        }
        bool possible = true;
        for (int i = 0; i < 26; i++)
        {
            if (count2[i] > count1[i])
            {
                possible = false;
                break;
            }
        }
        if (possible)
        {
            cout << "Possible" << endl;
        }
        else
        {
            cout << "Impossible" << endl;
        }
    }
    return 0;
}
