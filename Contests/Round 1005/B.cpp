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
        long long int n, min_index, max_index, maxcount = 0, Aflag = 0;
        cin >> n;

        vector<int> vec(n);

        for (int i = 0; i < n; i++)
        {
            cin >> vec[i];
        }

        unordered_map<long long int,long long int> frequencyMap;

        // Count the frequency of each element
        for (long long int num : vec)
        {
            frequencyMap[num]++;
        }

        for (const auto &pair : frequencyMap)
        {
            if (pair.second > 1)
            {
                Aflag = 1;
                break;
            }
        }

        if (Aflag == 0)
        {
            cout << 1 << ' ' << n << endl;
        }
        else
        {
            bool valid = false;

            for (int i = 0; i < n - 2; i++)
            {
                int flag = 0, index = i, count = 0;
                for (int j = i + 2; j < n; j++)
                {
                    count++;
                    index = j;
                    if (vec[j] == vec[i] && vec[j - 1] != vec[j])
                    {
                        flag = 1;
                        valid = true;
                        break;
                    }
                }
                if (flag == 1)
                {
                    if (count > maxcount)
                    {
                        maxcount = count;
                        min_index = i + 2;
                        max_index = index;
                    }
                }
            }

            if (valid)
                cout << min_index << ' ' << max_index << endl;
            else
                cout << 0 << endl;
        }

    }

    return 0;
}
