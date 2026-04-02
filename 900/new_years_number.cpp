#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int flag = 0;
        while (n > 0)
        {
            if (n < 2020)
            {
                break;
            }
            else if (n % 2021 == 0 || n % 2020 == 0)
            {
                flag = 1;
                break;
            }
            else
            {
                int a = n % 10;
                if (a != 0)
                {
                    n = n - (2021 * a);
                }
                else
                {
                    n = n - 2020;
                }
            }
        }
        if (n == 0 || flag == 1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}