#include <iostream>
#include <string>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        long long int n, k, x;
        cin >> n >> k >> x;

        long long int low = k * (k + 1) / 2;
        long long int high = (n * (n + 1) / 2) - ((n - k) * (n - k + 1) / 2);

        if (low > x || high < x)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }
    return 0;
}