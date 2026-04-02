#include <iostream>
#include <vector>
#include <algorithm>
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
            if ((vec[i].second) == 0)
                vec[i].second = k;
        }

        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (vec[i].second < vec[j].second)
                {
                    pair<int, int> temp = vec[i];
                    vec[i] = vec[j];
                    vec[j] = temp;
                }
                else if (vec[i].second == vec[j].second)
                {
                    if (vec[j].first < vec[i].first)
                    {
                        pair<int, int> temp = vec[i];
                        vec[i] = vec[j];
                        vec[j] = temp;
                    }
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            cout << vec[i].first << ' ';
        }
        cout << endl;
    }
    return 0;
}
