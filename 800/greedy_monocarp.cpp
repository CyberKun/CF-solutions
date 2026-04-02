#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;

    vector<int> n(t), k(t), count(t);
    vector<vector<int>> a(t);

    for (int i = 0; i < t; i++)
    {
        cin >> n[i] >> k[i];
        a[i].resize(n[i]);
        for (int j = 0; j < n[i]; j++)
        {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < t; i++)
    {
        sort(a[i].begin(), a[i].end(), greater<int>());
    }

    for (int i = 0; i < t; i++)
    {
        int count1 = 0;
        int flag = 0;

        for (int j = 0; j < n[i]; j++)
        {
            count1 = count1 + a[i][j];

            if (count1 == k[i])
            {
                flag = 1;
                break;
            }
            else if (count1 > k[i])
            {
                count1 = count1 - a[i][j];
                break;
            }
        }

        if (flag == 1)
            cout << 0 << endl;
        else
        {
            cout << (k[i] - count1) << endl;
        }
    }


    return 0;
}