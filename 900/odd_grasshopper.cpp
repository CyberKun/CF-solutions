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

        if (x % 2 != 0)
        {
            if (n % 2 == 0)
            {
                if (n % 4 == 0)
                    cout << x + 1 << endl;
                else
                    cout << x << endl;
            }
            else if ((n + 1) % 4 == 0)

                cout << x - n - 1 << endl;

            else
                cout << x + n << endl;
        }
        else
        {
            if (n % 2 == 0)
            {
                if (n % 4 == 0)
                    cout << x << endl;
                else
                    cout << x + 1 << endl;
            }
            else if ((n + 1) % 4 == 0)

                cout << x + (n + 1) << endl;
            else

                cout << x - n << endl;
        }
    }

    return 0;
}