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
        char arr[n];

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        if (n == 1)
        {
            cout << 2 << endl;
        }
        else if (n == 2)
        {
            if (arr[0] == arr[1])
            {
                cout << 3 << endl;
            }
            else
            {
                cout << 2 << endl;
            }
        }
        else if (n >= 3)
        {
            int count = 2;
            int res = 0;
            for (int i = 0; i < n - 1; i++)
            {
                if (arr[i] == arr[i + 1])
                {
                    count++;
                }
                else
                {
                    if (count > res)
                    {
                        res = count;
                        count = 2;
                    }
                    count=2;
                }
            }
            if (count > res)
            {
                res = count;
            }
            cout << res << endl;
        }
    }

    return 0;
}