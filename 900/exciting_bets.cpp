#include <bits\stdc++.h>
using namespace std;

int main()
{
    long long int t;
    cin >> t;

    while (t--)
    {
        long long int a, b;
        cin >> a >> b;

        long long int MAXgcd = abs(a - b);

        if (MAXgcd == 0)
            cout << 0 << ' ' << 0 << endl;
        else
        {
            long long int x, y, z;

            x = (a % MAXgcd);
            y = MAXgcd - x;

            z = min(x, y);

            cout << MAXgcd << ' ' << z << endl;
        }
    }
    return 0;
}