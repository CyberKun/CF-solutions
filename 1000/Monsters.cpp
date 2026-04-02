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
        int n, k;
        cin >> n >> k;

        vector<pair<int, int>> vec(n);

        for (int i = 0; i < n; i++)
        {
            cin >> vec[i].first;
            vec[i].second = i + 1;

            vec[i].first %= k;
            if ((vec[i].first) == 0)
                vec[i].first = k;
        }

        // Sort the vector of pairs
        sort(vec.begin(), vec.end(), [](const pair<int, int> &a, const pair<int, int> &b)
             {
                 if (a.first != b.first)
                     return a.first > b.first; // Sort by first in descending order
                 return a.second < b.second;   // Sort by first in ascending order if first are equal
             });

        for (int i = 0; i < n; i++)
        {
            cout << vec[i].second << ' ';
        }
        cout << endl;
    }
    return 0;
}
