#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        int a[n];

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        if (k > 1)
        {

            cout << "YES" << endl;
        }
        else
        {

            int flag = 0;

            for (int i = 0; i < n - 1; i++)
            {
                if (a[i] > a[i + 1])
                {
                    cout << "NO" << endl;
                    flag = 1;
                    break;
                }
            }

            if (flag == 0)
            {
                cout << "YES" << endl;
            }
        }
    }
    return 0;
}