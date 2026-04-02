#include <bits\stdc++.h>
using namespace std;

int main()
{
    long long int t;
    cin >> t;

    while (t--)
    {
        long long int n, x;
        cin >> n >> x;
        long long int MAXsum = 0, MINsum = 0;

        vector<long long int> num(n);

        for (int i = 0; i < n; i++)
        {
            cin >> num[i];

            MAXsum += (num[i] + x - 1) / x;
        }

        for (int i = 0; i < num.size() - 1;)
        {
            if (num[i] % x != 0 && num[i + 1] % x != 0 && (num[i] / x > 0 && num[i + 1] / x > 0))
            {
                num[i] += num[i + 1];
                num.erase(num.begin() + i + 1);
            }
            else
                i++;
        }

        for (int i = 0; i < num.size(); i++)
        {
            MINsum += (num[i] + x - 1) / x;
        }

        cout << MINsum << ' ' << MAXsum << endl;
    }
    return 0;
}