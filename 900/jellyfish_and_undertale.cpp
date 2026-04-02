#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        long long int a, b, n;
        cin >> a >> b >> n;

        vector<int> x(n);

        for (int i = 0; i < n; i++)
        {
            cin >> x[i];
        }

        sort(x.begin(), x.end());

        long long int maxtime = 0;
        long long int timer = b;
        int flag = 0;

        for (int i = 0; i < n; i++)
        {
            if (x[i] >= a - 1)
            {
                maxtime = maxtime + (timer - 1);
                maxtime = maxtime + (a - 1) * (n - i) + 1;
                flag = 1;
                cout << maxtime << endl;
                break;
            }
            else
            {
                if (timer + x[i] < a)
                    timer = timer + x[i];
                else
                {
                    maxtime = maxtime + (timer - 1);
                    timer = 1 + x[i];
                }
            }
        }

        if (flag == 0)
        {
            maxtime = maxtime + timer;
            cout << maxtime << endl;
        }
    }
    return 0;
}