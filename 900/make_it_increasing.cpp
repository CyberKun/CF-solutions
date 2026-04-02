#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        long long int n;
        cin >> n;

        vector<long long int> a(n);

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        long long int flag = 0, count = 0;

        for (int i = n - 2; i >= 0; i--)
        {
            while (a[i] >= a[i + 1])
            {
                a[i] /= 2;
                count++;

                if (a[i] == a[i + 1] && a[i] / 2 == a[i + 1])
                {
                    cout << -1 << endl;
                    flag = 1;
                    break;
                }
            }
            if(flag==1)
            break;
        }

        if (flag == 0)
        {
            cout << count << endl;
        }
    }
    return 0;
}