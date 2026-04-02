#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, x;
        cin >> n >> x;

        int arr[n];

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        int maxdis = arr[0];

        for (int i = 0; i < n - 1; i++)
        {
            if ((arr[i + 1] - arr[i]) > maxdis)
            {
                maxdis = arr[i + 1] - arr[i];
            }
        }

        if (2 * (x - arr[n - 1]) > maxdis)
            cout << 2 * (x - arr[n - 1]) << endl;
        else
            cout << maxdis << endl;
    }
    return 0;
}