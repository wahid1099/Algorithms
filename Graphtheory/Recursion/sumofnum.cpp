#include <bits/stdc++.h>
using namespace std;

// Function to check sum of digit using recursion
int sum_of_digit(int n)
{
    if (n == 0)
        return 0;
    return (n % 10 + sum_of_digit(n / 10));
}

// Driven code
int main()
{
    int num = 7464;
    int result = sum_of_digit(num);
    cout << "Sum of digits in " << num
         << " is " << result << endl;
    return 0;
}