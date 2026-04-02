#include <bits/stdc++.h>
using namespace std;

// Function to calculate factorial
unsigned long long factorial(int n)
{
    unsigned long long fact = 1;
    for (int i = 1; i <= n; ++i)
    {
        fact *= i;
    }
    return fact;
}

// Function to calculate combinations
unsigned long long combination(int n, int r)
{
    if (r > n)
        return 0;
    return factorial(n) / (factorial(r) * factorial(n - r));
}

// Function to calculate total combinations where size is >= r
unsigned long long totalCombinations(int n, int r)
{
    unsigned long long total = 0;
    for (int i = r; i <= n; ++i)
    {
        total += combination(n, i);
    }
    return total;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, k, q;
        cin >> n >> k >> q;

        vector<int> vec(n);
        vector<int> count;
        int num = 0, ans = 0;

        for (int i = 0; i < n; i++)
        {
            cin >> vec[i];

            if (vec[i] <= q)
                num++;
            else
            {
                if (num >= k)
                    count.push_back(num);

                num = 0;
            }
        }

        if (num >= k)
            count.push_back(num);

        for (int i = 0; i < count.size(); i++)
        {
            ans += totalCombinations(count[i], k);
        }
        if(ans <=1)
        cout << ans << endl;
        else
        cout << ans - 1 << endl;

        // for (int i = 0; i < count.size(); i++)
        // {
        //     cout << count[i] << ' ';
        // }
        // cout << endl;
    }
    return 0;
}
