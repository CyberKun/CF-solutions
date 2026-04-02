#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        char arr[n];

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        for (int i = 0; i < n;)
        {
            if (i == (n - 3))
            {
                cout << arr[i] << arr[i + 1] << arr[i + 2];
                break;
            }
            else if (i > n - 3)
            {
                cout << arr[i];
                i++;
            }
            else if ((arr[i] == 'b' || arr[i] == 'c' || arr[i] == 'd') && (arr[i + 3] == 'b' || arr[i + 3] == 'c' || arr[i + 3] == 'd'))
            {
                cout << arr[i] << arr[i + 1] << arr[i + 2] << '.';
                i = i + 3;
            }
            else
            {
                cout << arr[i] << arr[i + 1] << '.';
                i = i + 2;
            }
        }
        cout << endl;
    }

    return 0;
}