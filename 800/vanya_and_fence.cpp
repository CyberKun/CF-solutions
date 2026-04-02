#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, h, count = 0;
    cin >> n >> h;

    vector<int> vec(n);

    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
        if (vec[i] > h)
            count++;
    }

    cout << vec.size() + count << endl;

    return 0;
}
