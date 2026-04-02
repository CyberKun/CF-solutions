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
        int arr[n];

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int flag = 0;

        for (int i = 0; i < n - 1; i++)
        {
            int a = arr[i];
            int b = arr[i + 1];

            if (a < b)
            {
                if (2 * a > b)
                {
                    cout << "YES" << endl;
                    flag = 1;
                    break;
                }
            }
            else
            {
                if (2 * b > a)
                {
                    cout << "YES" << endl;
                    flag = 1;
                    break;
                }
            }
        }
        if (flag == 0)
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}