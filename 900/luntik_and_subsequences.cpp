#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

long long int power(int base, int exponent)
{
    long long int result = 1;
    for (int i = 0; i < exponent; ++i)
    {
        result *= base;
    }
    return result;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        long long int n, count0 = 0, count1 = 0, sum = 0;
        cin >> n;
        vector<long long int> arr(n);

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            sum += arr[i];
        }

        for (int i = 0; i < n; i++)
        {
            if (arr[i] == 0)
                count0++;
            else if (arr[i] == 1)
                count1++;
        }

        int final = power(2, count0);

        if (count1 == 0)
            cout << 0 << endl;
        else
            cout << count1 * final << endl;
    }

    return 0;
}
