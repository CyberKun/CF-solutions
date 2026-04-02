#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << arr[1] - arr[0] << ' ' << arr[n - 1] - arr[0] << endl;

    for (int i = 1; i < n - 1; i++)
    {
        int a = arr[i] - arr[0];
        int b = arr[n - 1] - arr[i];
        int c = arr[i] - arr[i - 1];
        int d = arr[i + 1] - arr[i];

        if (c < d)
            cout << c << ' ';
        else
            cout << d << ' ';

        if (a > b)
            cout << a << ' ' << endl;
        else
            cout << b << ' ' << endl;
    }

    cout << arr[n - 1] - arr[n - 2] << ' ' << arr[n - 1] - arr[0] << endl;

    return 0;
}