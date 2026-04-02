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

        int count = 1, maxcount = 0;

        for (int i = 0; i < n - 1; i++)
        {
            if (arr[i] == arr[i + 1])
            {
                count++;
            }
            else
            {
                if (count > maxcount)
                    maxcount = count;

                count = 1;
            }
        }
        if (count > maxcount)
            maxcount = count;

        cout << maxcount + 1 << endl;
    }

    return 0;
}