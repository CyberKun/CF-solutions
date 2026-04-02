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
        int n, flag = 0, count = 0;
        cin >> n;

        string s;
        cin >> s;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1' && flag == 0)
            {
                flag = 1;
                count++;
            }

            if (s[i] == '0' && flag == 1)
            {
                flag = 0;
                count++;
            }
        }

        cout << count << endl;
    }

    return 0;
}
