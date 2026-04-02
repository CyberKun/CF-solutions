#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int t;
    cin >> t;

    while (t--)
    {
        long long int n;
        cin >> n;

        vector<int> arr(n);
        vector<char> chr(n - 1);
        int a, b, c;

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            if (i != n - 1)
            {
                if (arr[i] > arr[i + 1])
                    chr[i] = '>';
                else
                    chr[i] = '<';
            }
        }

        int flag = 0;

        for (int i = 0; i < n - 2; i++)
        {
            if (arr[i] < arr[i + 1] && arr[i + 1] > arr[i + 2])
            {
                a = i + 1;
                b = i + 2;
                c = i + 3;
                flag = 1;
                break;
            }
        }

        if (flag == 0)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
            cout << a << ' ' << b << ' ' << c << endl;
        }
    }

    return 0;
}
