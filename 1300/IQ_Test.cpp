#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int n;
    cin >> n;

    vector<int> arr(n);
    int counto = 0, counte = 0, a, b;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];

        if (arr[i] % 2 == 0)
        {
            counte++;
            a = i;
        }
        else
        {
            counto++;
            b = i;
        }
    }

    if (counte == 1)
        cout << a + 1 << endl;
    else
        cout << b + 1 << endl;

    return 0;
}
