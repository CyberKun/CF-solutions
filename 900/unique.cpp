#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int x;
        cin >> x;

        if (x / 10 == 0)
        {
            cout << x << endl;
        }
        else if (x < 18)
        {
            int a = x - 9;
            cout << a << 9 << endl;
        }
        else if (x < 25)
        {
            int a = x - 17;
            cout << a << 8 << 9 << endl;
        }
        else if (x < 31)
        {
            int a = x - 24;
            cout << a << 7 << 8 << 9 << endl;
        }
        else if (x < 36)
        {
            int a = x - 30;
            cout << a << 6 << 7 << 8 << 9 << endl;
        }
        else if (x < 40)
        {
            int a = x - 35;
            cout << a << 5 << 6 << 7 << 8 << 9 << endl;
        }
        else if (x < 43)
        {
            int a = x - 39;
            cout << a << 4 << 5 << 6 << 7 << 8 << 9 << endl;
        }
        else if (x < 45)
        {
            int a = x - 42;
            cout << a << 3 << 4 << 5 << 6 << 7 << 8 << 9 << endl;
        }
        else if (x == 45)
        {
            cout << 123456789 << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }

    return 0;
}