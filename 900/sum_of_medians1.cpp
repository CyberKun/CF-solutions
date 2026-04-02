#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int t;
    cin >> t;

    while (t--)
    {
        long long int n, k;
        cin >> n >> k;

        int s = n * k;
        long long int sum = 0, sum1 = 0;
        vector<int> vec(s);

        for (int i = 0; i < s; i++)
        {
            cin >> vec[i];
            sum1 += vec[i];
        }
        if (n == 1)
            cout << sum1 << endl;
        else
        {
            if (n == 2)
            {
                for (int i = 0; i < k; i++)
                {
                    sum += vec[i * 2];
                }
            }
            else
            {
                int median, index;
                if (n % 2 == 0)
                {
                    median = n / 2;
                    index = s - n + median - 1;

                    for (int i = 0; i < k; i++)
                    {
                        sum += vec[index];
                        cout << vec[index] << ' ';
                        index -= (n - median + 1);
                    }
                    cout << endl;
                }
                else
                {
                    median = (n + 1) / 2;
                    index = s - n + median - 1;

                    for (int i = 0; i < k; i++)
                    {
                        sum += vec[index];
                        cout << vec[index] << ' ';
                        index -= (n - median + 1);
                    }
                    cout << endl;
                }
            }

            cout << sum << endl;
        }
    }
    return 0;
}
