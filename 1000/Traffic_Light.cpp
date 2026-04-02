#include <bits/stdc++.h>
using namespace std;

int lcm(int a, int b)
{
    return (a * b) / __gcd(a, b);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int n, flag = 0, count = 0, gflag = 0, nm = 0, ans = INT_MIN;
        char c;
        cin >> n >> c;

        vector<char> vec(n);
        vector<int> num;

        for (int i = 0; i < n; i++)
        {
            cin >> vec[i];
        }

        if (c == 'g')
        {
            int flag = 0;

            for (int i = 0; i < n; i++)
            {
                if (vec[i] != 'g')
                {
                    flag = 1;
                    break;
                }
            }

            if (flag == 1)
            {
                vector<int> index;
                for (int i = 0; i < n; i++)
                {
                    num.push_back(vec[i]);
                }

                for (int i = 0; i < n; i++)
                {
                    num.push_back(vec[i]);
                    if (vec[i] == 'g')
                        break;
                }

                for (int i = 0; i < num.size(); i++)
                {
                    if (num[i] == 'g')
                        index.push_back(i);
                }

                for (int i = 0; i < index.size() - 1; i++)
                {
                    ans = max(ans, index[i + 1] - index[i]);
                }
            }
            else
                ans = 0;
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                if (vec[i] == 'g' && gflag == 0)
                {
                    nm = i;
                    gflag = 1;
                }
                if (vec[i] == c)
                {
                    flag = 1;
                }

                if (vec[i] == 'g')
                {
                    ans = max(ans, count);
                    count = 0;
                    flag = 0;
                }

                if (flag == 1)
                {
                    count++;
                }
            }

            if (count > 0)
            {
                ans = max(ans, count + nm);
            }
        }
        if (ans < 0)
            cout << 0 << endl;
        else
            cout << ans << endl;
    }

    return 0;
}
