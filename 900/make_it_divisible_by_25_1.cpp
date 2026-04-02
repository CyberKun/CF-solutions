#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
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

        int a = n, count = 0;

        while (a != 0)
        {
            a /= 10;
            count++;
        }

        int cnt = 0;
        int first0 = INT_MAX, second0 = INT_MAX, first5 = INT_MAX, second5 = INT_MAX, count7 = INT_MAX, count2 = INT_MAX, found0 = 0, found5 = 0;

        vector<int> num(count);

        for (int i = count - 1; i >= 0; i--)
        {
            num[i] = n % 10;
            n /= 10;
        }

        int i = num.size() - 1;

        while (i >= 0)
        {
            if (num[i] == 0)
            {
                if (found0 == 0)
                {
                    found0++;
                    first0 = i;
                }
                else if (found0 == 1)
                {
                    found0++;
                    second0 = i;
                }
                else
                {
                    found0++;
                }
            }
            else if (num[i] == 5)
            {
                if (found5 == 0)
                {
                    found5++;
                    first5 = i;
                }
                else if (found5 == 1)
                {
                    found5++;
                    second5 = i;
                }
                else
                {
                    found0++;
                }
            }
            else if (num[i] == 2)
            {
                if (i > count2)
                    count2 = i;
            }
            else if (num[i] == 7)
            {
                if (i > count7)
                    count7 = i;
            }
        }

        int two0 = num.size() - second0 - 2;
        int twofive = num.size() - count2 - 2;
        int sevenfive = num.size() - count7 - 2;
        int fivezero = INT_MAX;
        if (first0 > first5)
        {
            fivezero = num.size() - first5 - 2;
        }
        else
        {
            fivezero = num.size() - second5 - 2;
        }

        vector<int> ans;
        if (two0 >= 0)
            ans.push_back(two0);
        if (twofive >= 0)
            ans.push_back(twofive);
        if (sevenfive >= 0)
            ans.push_back(sevenfive);
        if (fivezero >= 0)
            ans.push_back(fivezero);

        sort(ans.begin(), ans.end());

        cout << ans[0] << endl;
    }
    return 0;
}