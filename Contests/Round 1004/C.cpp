#include <bits/stdc++.h>
using namespace std;

bool check(int n, vector<int> &arr)
{
    unordered_map<int, int> freq;
    for (int num : arr)
    {
        freq[num]++;
    }
    for (auto &pair : freq)
    {
        if (pair.second % 2 != 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> arr[i];
        }

        if (check(n, arr))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}
