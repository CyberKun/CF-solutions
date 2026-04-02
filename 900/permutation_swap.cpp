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

        vector<int> x(n);
        vector<int> diff;

        for (int i = 0; i < n; i++)
        {
            cin >> x[i];
            if (abs(x[i] - (i + 1)) != 0)
            {
                diff.push_back(abs(x[i] - (i + 1)));
            }
        }

        sort(diff.begin(), diff.end());

        int maxcount = 0, count = 1, num = 1;

        for (int i = 0; i < diff.size()-1; i++)
        {
            if (diff[i] == diff[i + 1])
            {
                count++;
            }
            else
            {
                if (count > maxcount)
                {
                    maxcount = count;
                    num = diff[i];
                }
                count = 1;
            }
        }

        if (count > maxcount)
        {
            maxcount = count;
            num = diff[diff.size() - 1];
        }

        cout << num << endl;

        // for (int i = 0; i < diff.size(); i++)
        // {
        //     cout << diff[i] << ' ';
        // }
        // cout << endl;
    }
    return 0;
}