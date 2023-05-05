#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, s, r;
        cin >> n >> s >> r;

        int max_val = s - r;   // the maximum value on the stolen dice
        int sum = r + max_val; // the sum of all the dice values

        // output the values of the remaining dice
        for (int i = 1; i < n; i++)
        {
            cout << i << " ";
        }

        // output the maximum value
        cout << max_val << endl;
    }

    return 0;
}
