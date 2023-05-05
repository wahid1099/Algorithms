#include <iostream>
#include <string>
using namespace std;

int main()
{
    int t; // number of test cases
    cin >> t;

    string pi = "31415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679"; // first 100 digits of pi
    string n;                                                                                                            // input string

    while (t--)
    {
        cin >> n;
        int count = 0;
        for (int i = 0; i < n.length(); i++)
        {
            if (n[i] == pi[i])
            {
                count++;
            }
        }
        cout << count << endl;
    }

    return 0;
}
