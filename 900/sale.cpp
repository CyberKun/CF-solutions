#include <iostream>
using namespace std;

int main()
{
    int n, m, sum = 0;
    cin >> n >> m;
    int num[n];

    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (num[i] > num[j])
            {
                int temp = num[i];
                num[i] = num[j];
                num[j] = temp;
            }
        }
    }

    for (int i = 0; i < m; i++)
    {
        if (num[i] <= 0)
        {
            num[i] *= (-1);
            sum += num[i];
        }
        else
            break;
    }
    cout << sum;

    return 0;
}