#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, d, count = 0;
    cin >> n >> d;

    vector<int> vec(n);
    vector<int> num;

    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }

    sort(vec.begin(), vec.end());

    int size = n;

    for (int i = n - 1; i >= 0; i--)
    {
        if (size - (d / vec[i] + 1) >= 0)
        {
            size -= (d / vec[i] + 1);
            count++;
        }
        else
        break;
    }

    cout << count << endl;

    return 0;
}
