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
        int n, flag = 0;
        cin >> n;

        vector<int> vec(n);

        for (int i = 0; i < n; i++)
        {
            cin >> vec[i];
        }

        sort(vec.begin(), vec.end());

        vector<pair<int, int>> freq(vec[n - 1]);

        for (int i = 0; i < freq.size(); i++)
        {
            freq[i].first = i + 1;
            freq[i].second = 0;
        }

        for (int i = 0; i < n; i++)
        {
            freq[vec[i] - 1].second++;
        }

        int carry = 0;

        for (int i = 0; i < freq.size(); i++)
        {
            freq[i].second += carry;
            carry = 0;

            if (freq[i].second == 1)
            {
                flag = 1;
                break;
            }
            else if (freq[i].second > 2)
            {
                carry += freq[i].second - 2;
            }
        }

        if (freq[freq.size() - 1].second % 2 == 0 && flag == 0)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }

    return 0;
}