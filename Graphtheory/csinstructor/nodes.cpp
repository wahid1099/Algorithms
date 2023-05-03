#include <iostream>
using namespace std;

int main()
{
    long long n;
    while (cin >> n)
    {
        int level = 1;
        while (n > 1)
        {
            level++;
            n /= 2;
        }
        cout << level << endl;
    }
    return 0;
}
