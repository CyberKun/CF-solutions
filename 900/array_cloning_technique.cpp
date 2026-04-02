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

        sort(a.begin(), a.end());

        long long int operations = 0, count = 1, maxcount = 0;

        for (int i = 0; i < n - 1; i++)
        {
            if (a[i] == a[i + 1])
            {
                count++;
            }
            else
            {
                if (count > maxcount)
                {
                    maxcount = count;
                    count = 1;
                }
            }
        }

        if (count > maxcount)
        {
            maxcount = count;
        }

        count = maxcount;

        while (maxcount < n)
        {
            operations++;
            count = count * 2;
            if (count <= n)
            {

                operations = operations + maxcount;
                maxcount = count;
            }
            else
            {
                operations += (n - maxcount);
                maxcount = n;
            }
        }

        cout << operations << endl;
    }
    return 0;
}