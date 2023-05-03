#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    string result;
    int i = 0;
    while (i < s.length())
    {
        int n = s[i] - '0';
        if (n >= 1 && n <= 9)
        {
            i++;
            int j = i;
            while (j < s.length() && islower(s[j]))
            {
                j++;
            }
            string c = s.substr(i, j - i);
            for (int k = 0; k < n; k++)
            {
                result += c;
            }
            i = j;
        }
        else
        {
            result += s[i];
            i++;
        }
    }
    cout << result << endl;
    return 0;
}
