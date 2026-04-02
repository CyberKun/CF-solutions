#include <bits/stdc++.h>
using namespace std;

int closestPowerOfTwo(int num)
{
    // Start with the largest power of two less than num
    int power = 1;
    while (power * 2 < num)
    {
        power *= 2;
    }
    return power;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int x;
        cin >> x;
        int k = -1;

        int i = closestPowerOfTwo(x) - 1;

        int num = x ^ i;
        if (x + i > num && x + num > i && i + num > x)
        {
            k = i;
        }

        cout << k << endl;
    }

    return 0;
}
