#include <iostream>
using namespace std;

int main()
{
    long long int t;
    cin >> t;

    while (t--)
    {
        long long int x, n;
        cin >> x >> n;

        // Determine the position based on the remainder of n modulo 4
        if (n % 4 == 0)
        {
            cout << x << endl;
        }
        else if (n % 4 == 1)
        {
            cout << (x % 2 == 0 ? x - n : x + n) << endl;
        }
        else if (n % 4 == 2)
        {
            cout << (x % 2 == 0 ? x + 1 : x - 1) << endl;
        }
        else if (n % 4 == 3)
        {
            cout << (x % 2 == 0 ? x + (n + 1) : x - (n + 1)) << endl;
        }
    }

    return 0;
}
