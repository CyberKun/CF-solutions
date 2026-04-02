#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        long long int n, k;
        cin >> n >> k;
        long long int arr[n];
        int flag = 0;

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        if (k == 2)
        {
            for (int i = 0; i < n; i++)
            {
                if (arr[i] % 2 == 0)
                {
                    cout << 0 << endl;
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
            {
                cout << 1 << endl;
            }
        }
        else if (k == 3)
        {
            int rem = arr[0] % 3;
            for (int i = 0; i < n; i++)
            {
                if (arr[i] % 3 == 0)
                {
                    cout << 0 << endl;
                    flag = 1;
                    break;
                }
                else if (arr[i] % 3 > rem)
                {
                    rem = arr[i] % 3;
                }
            }

            if (flag == 0)
                cout << 3 - rem << endl;
        }
        else if (k == 4)
        {
            int flag = 0;
            int count = 0;
            int ans = 0;
            int ans2 = 0;
            for (int i = 0; i < n; i++)
            {
                if (arr[i] % 4 == 0)
                {
                    cout << 0 << endl;
                    ans = 0;
                    ans2 = 1;
                    flag = 1;
                    break;
                }
                else if (arr[i] % 2 == 0)
                {
                    count++;
                    if (count == 2)
                    {
                        cout << 0 << endl;
                        ans = 0;
                        flag = 1;
                        break;
                    }
                }
                else
                {
                    if ((arr[i] + 1) % 4 == 0)
                    {
                        ans = 1;
                        flag = 1;
                    }
                }
            }
            if ((count == 1 || ans == 1) && ans2 != 1)
            {
                cout << 1 << endl;
            }
            else if (flag == 0)
            {
                cout << 2 << endl;
            }
        }
        else
        {
            int rem = arr[0] % 5;
            int flag = 0;
            for (int i = 0; i < n; i++)
            {
                if (arr[i] % 5 == 0)
                {
                    cout << 0 << endl;
                    flag = 1;
                    break;
                }
                else if (arr[i] % 5 > rem)
                {
                    rem = arr[i] % 5;
                }
            }
            if (flag == 0)
                cout << 5 - rem << endl;
        }
    }
    return 0;
}