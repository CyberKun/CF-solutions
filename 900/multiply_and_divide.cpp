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
        int count = 0;
        while (num[i] != 1)
        {
            if (num[i] % 6 == 0)
            {
                num[i] /= 6;
                count++;
            }
            else if (num[i] % 6 != 0 && num[i] % 3 == 0)
            {
                num[i] *= 2;
                count++;
            }
            else
            {
                count = -1;
                break;
            }
        }

        cout << count << endl;
    }

    return 0;
}