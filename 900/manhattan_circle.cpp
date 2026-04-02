#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;

    vector<int> n(t), m(t), count(t, 0), count1(t, 0);
    vector<vector<vector<char>>> a(t);

    for (int i = 0; i < t; i++)
    {
        cin >> n[i] >> m[i];
        a[i].resize(n[i]);
        for (int j = 0; j < n[i]; j++)
        {
            a[i][j].resize(m[i]);
            for (int k = 0; k < m[i]; k++)
            {
                cin >> a[i][j][k];
                if (a[i][j][k] == '#')
                {
                    count[i]++;
                }
            }
        }
    }

    for (int i = 0; i < t; i++)
    {
        int count2 = (count[i] + 1) / 2;
        int flag = 0;
        for (int j = 0; j < n[i]; j++)
        {
            for (int k = 0; k < m[i]; k++)
            {
                if (a[i][j][k] == '#')
                    count1[i]++;
                if (count1[i] == count2)
                {
                    cout << j + 1 << ' ' << k + 1 << endl;
                    flag = 1;
                    break;
                }
            }
            if (flag)
                break;
        }
    }

    return 0;
}