#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<vector<int>> vec(n);
        vector<int> min(n);
        vector<int> min2(n);

        int m[n];

        for (int i = 0; i < n; i++)
        {
            cin >> m[i];
            vec[i].resize(m[i]);
            for (int j = 0; j < m[i]; j++)
            {
                cin >> vec[i][j];
            }
            sort(vec[i].begin(), vec[i].end());
            min[i] = vec[i][0];
            min2[i] = vec[i][1];
        }
        sort(min.begin(), min.end());
        sort(min2.begin(), min2.end());

        if (n > 1)
        {

            int sum = min[0];

            for (int i = 1; i < n; i++)
                sum += min2[i];

            cout << sum << endl;
        }
        else
        {
            cout << min[0] << endl;
        }
    }
    return 0;
}
