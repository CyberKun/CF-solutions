#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int size = 2 * n, sum = 0;
        vector<int> arr(size);

        for (int i = 0; i < size; i++)
        {
            cin >> arr[i];
        }

        sort(arr.begin(), arr.end(), std::greater<int>());

        sum = arr[0];
        for (int i = 1; i < size; i++)
        {
            if (i % 2 == 0)
            {
                sum += arr[i];
            }
            else
            {
                sum -= arr[i];
            }
        }

        int flag = 0;
        for (int i = 0; i < size; i++)
        {
            if (arr[i] == sum)
            {
                flag = 1;
                break;
            }
        }

        if (flag == 0)
        {
            cout << sum << ' ';
            for (int i = 0; i < size; i++)
            {
                cout << arr[i] << ' ';
            }
            cout << endl;
        }
        else
        {
            int newSum = 0;
            for (int i = 0; i < (size / 2); i++)
            {
                newSum += arr[i];
            }
            for (int i = (size / 2); i < size; i++)
            {
                newSum -= arr[i];
            }

            int fg = 0;
            for (int i = 0; i < size; i++)
            {
                if (newSum == arr[i])
                {
                    fg = 1;
                    break;
                }
            }

            if (fg == 0)
            {
                cout << newSum << ' ';
                for (int i = 0, j = size - 1; i < j; i++, j--)
                {
                    cout << arr[i] << ' ' << arr[j] << ' ';
                }
                cout << endl;
            }
            else
            {
                int final = 0;
                for (int i = 0; i < size; i++)
                {
                    if (i % 2 == 0)
                    {
                        final += arr[i];
                    }
                    else
                    {
                        final -= arr[i];
                    }
                }

                cout << arr[size - 1] << ' ';
                for (int i = 0; i < size - 1; i++)
                {
                    cout << arr[i] << ' ';
                }
                cout << final << endl;
            }
        }
    }

    return 0;
}
