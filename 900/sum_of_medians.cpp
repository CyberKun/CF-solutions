#include <bits\stdc++.h>
using namespace std;

int main()
{
    long long int t;
    cin >> t;

    while (t--)
    {
        long long int n, k;
        cin >> n >> k;

        int s = n * k, sum = 0;
        vector<int> vec(s);

        for (int i = 0; i < s; i++)
        {
            cin >> vec[i];
        }

        if (n == 2)
        {
            int num = 0, i = 0;
            while (num < k)
            {
                sum += vec[i];
                i += 2;
                num++;
            }
        }
        else
        {
            int num = 0, i = s - n + 1;

            while (num < k)
            {
                sum += vec[i];
                i = i - n + 1;
                num++;
            }
        }

        cout << sum << endl;
    }
    return 0;
}