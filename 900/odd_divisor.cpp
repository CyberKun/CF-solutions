#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    long long int num[n];

    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }

    for (int i = 0; i < n; i++)
    {
        int flag = 0;
        if (num[i] % 2 != 0)
            cout << "YES" << endl;

        else
        {
            for (long long int j = 3; j <= num[i]; j++)
            {
                if (num[i] % j == 0 && j % 2 != 0)
                {
                    flag = 1;
                    cout << j << endl;
                    break;
                }
            }
            if (flag == 1)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }

    return 0;
}