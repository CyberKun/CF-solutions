#include <bits/stdc++.h>
using namespace std;

int lcm(int a, int b)
{
    return (a * b) / __gcd(a, b);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int n, minu = INT_MAX, ans1, ans2;
        cin >> n;

        int a = 1, b = n - 1;

        while (b > 0)
        {
            int temp = lcm(a, b);

            if (temp < minu)
            {
                minu = temp;
                ans1 = a;
                ans2 = b;
            }
            a++;
            b--;
        }

        cout << ans1 << ' ' << ans2 << endl;
    }

    return 0;
}
