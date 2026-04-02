#include <iostream>
#include <vector>
#include <algorithm> // For std::sort
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
            cin >> vec[i].second;
            vec[i].first = i + 1;

            vec[i].second %= k;
            if (vec[i].second == 0)
                vec[i].second = k;
        }

        // Sort the vector of pairs
        sort(vec.begin(), vec.end(), [](const pair<int, int> &a, const pair<int, int> &b)
             {
                 if (a.second != b.second)
                     return a.second > b.second; // Sort by second in descending order
                 return a.first < b.first;       // Sort by first in ascending order if seconds are equal
             });

        for (const auto &p : vec)
        {
            cout << p.first << ' ';
        }
        cout << endl;
    }

    return 0;
}
