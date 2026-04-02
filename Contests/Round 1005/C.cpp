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
        long long int n;
        cin >> n;

        vector<int> vec(n);
        for (int i = 0; i < n; i++)
        {
            cin >> vec[i];
        }

        unordered_map<int, int> last_seen;
        bool found = false;
        int min_index = -1, max_index = -1;

        for (int i = 0; i < n; ++i)
        {
            if (last_seen.count(vec[i]))
            {
                int start = last_seen[vec[i]];
                if (i > start + 1)
                {
                    min_index = start + 1;
                    max_index = i + 1;
                    found = true;
                    break;
                }
            }
            last_seen[vec[i]] = i;
        }

        if (!found)
        {
            cout << 0 << endl;
        }
        else
        {
            cout << min_index + 2 << ' ' << max_index - 1 << endl;
        }
    }

    return 0;
}
