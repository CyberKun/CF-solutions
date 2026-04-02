#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        if (a < b)
        {
            if ((c > a && c < b) && (d > b || (d < a)))
                cout << "YES" << endl;
            else if ((d > a && d < b) && (c > b || (c < a)))
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
        else 
        {
            if ((c > b && c < a) && (d > a || (d < b)))
                cout << "YES" << endl;
            else if ((d > b && d < a) && (c > a || (c < b)))
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }

    return 0;
}