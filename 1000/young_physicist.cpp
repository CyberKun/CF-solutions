#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n][3], x = 0, y = 0, z = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }

    for (int i = 0; i < n; i++)
    {
        x = x + arr[i][0];
        y = y + arr[i][1];
        z = z + arr[i][2];
    }

    if (x == 0 && y == 0 && z == 0)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}