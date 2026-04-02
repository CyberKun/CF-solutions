#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int num[12];

    for (int i = 0; i < 12; i++)
    {
        cin >> num[i];
    }

    if (n == 0)
    {
        cout << 0;
        return 0;
    }

    for (int i = 0; i < 11; i++)
    {
        for (int j = i + 1; j < 12; j++)
        {
            if (num[i] < num[j])
            {
                int temp = num[i];
                num[i] = num[j];
                num[j] = temp;
            }
        }
    }

    int sum = 0, count = 0;

    for (int i = 0; i < 12; i++)
    {
        sum = sum + num[i];
        count++;
        if (sum >= n)
            break;
        else if (i == 11 && sum < n)
        {
            count = -1;
            break;
        }
    }

    cout << count;

    return 0;
}