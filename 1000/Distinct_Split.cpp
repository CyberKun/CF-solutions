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
        int n, flag = 0, pair = 0;
        cin >> n;

        vector<char> str(n);
        vector<int> str2;

        for (int i = 0; i < n; i++)
            cin >> str[i];

        sort(str.begin(), str.end());

        for (int i = 0; i < str.size() - 1;)
        {
            if (str[i] == str[i + 1])
            {
                str.erase(str.begin() + i + 1);

                if (flag == 0)
                {
                    pair++;
                    flag = 1;
                }
            }
            else
            {
                flag = 0;
                i++;
            }
        }


        cout << pair << endl;
    }

    return 0;
}
