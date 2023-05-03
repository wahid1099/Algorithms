#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000005;
int n, a[MAXN];
long long prefix_product[MAXN];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    prefix_product[0] = 1LL;
    for (int i = 1; i <= n; i++)
    {
        prefix_product[i] = prefix_product[i - 1] * a[i];
    }

    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        bool has_zero = false;
        for (int i = l; i <= r; i++)
        {
            if (a[i] == 0)
            {
                has_zero = true;
                break;
            }
        }

        if (has_zero)
        {
            cout << "0\n";
            continue;
        }

        long long product = prefix_product[r] / prefix_product[l - 1];
        cout << product << endl;
    }
    return 0;
}