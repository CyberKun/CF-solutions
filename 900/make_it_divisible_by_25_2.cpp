#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        long long int n;
        cin >> n;

        int a = n, count = 0, minu = INT_MAX;

        while (a != 0)
        {
            a /= 10;
            count++;
        }

        vector<int> num(count);

        for (int i = count - 1; i >= 0; i--)
        {
            num[i] = n % 10;
            n /= 10;
        }

        vector<pair<int, int>> vec = {{0, 0}, {2, 5}, {7, 5}, {5, 0}};
        vector<int> found(4, 0);
        int flag = 0;

        for (int i = num.size() - 1; i >= 0; i--)
        {
            for (int j = 0; j < vec.size(); j++)
            {
                if (found[j] == 0)
                {
                    if (num[i] == vec[j].second)
                    {
                        found[j] = 1;
                    }
                }
                else
                {
                    if (num[i] == vec[j].first)
                    {
                        minu = (minu < num.size() - i - 2) ? minu : num.size() - i - 2;
                        flag = 1;
                    }
                }
            }
            if (flag == 1)
                break;
        }

        cout << minu << endl;
    }
    return 0;
}