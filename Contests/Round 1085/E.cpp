#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m, l;
    cin >> n >> m >> l;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> d(m, 0);
    // Pre-allocate the sorting array to make the loop lightning fast
    vector<int> sorted_d(m, 0);
    int flash_idx = 0;

    // Simulate the night second-by-second
    for (int t = 1; t <= l; t++)
    {

        // 1. Enemy Strategy: Maintain exactly K active buckets
        int flashes_left = n - flash_idx;
        int K = min(m, flashes_left + 1);

        // Instantly find the K-th largest danger level using nth_element (O(m) time)
        sorted_d = d;
        nth_element(sorted_d.begin(), sorted_d.begin() + K - 1, sorted_d.end(), greater<int>());
        int threshold = sorted_d[K - 1];

        // The enemy adds 1 danger to the SMALLEST bucket among the active top K.
        // Because of our threshold, the smallest active bucket is exactly equal to 'threshold'.
        for (int j = 0; j < m; j++)
        {
            if (d[j] == threshold)
            {
                d[j]++;
                break;
            }
        }

        // 2. Your Strategy: Flash the highest danger animatronic
        if (flash_idx < n && t == a[flash_idx])
        {
            int max_idx = 0;
            for (int j = 1; j < m; j++)
            {
                if (d[j] > d[max_idx])
                {
                    max_idx = j;
                }
            }
            d[max_idx] = 0;
            flash_idx++;
        }
    }

    // The answer is the highest danger level remaining at the end of the night
    int ans = 0;
    for (int j = 0; j < m; j++)
    {
        ans = max(ans, d[j]);
    }
    cout << ans << "\n";
}

int main()
{
    // Standard Fast I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (cin >> t)
    {
        while (t--)
            solve();
    }
    return 0;
}