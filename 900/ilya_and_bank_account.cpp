#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;

    if (n >= 0) cout << n;

    else
    {
        n = n * (-1);
        int m = n;
        int count = 0;

        while (m > 0)
        {
            m = m / 10;
            count++;
        }

        m = n;
        int num[count];

        for (int i = count - 1; i >= 0; i--)
        {
            num[i] = m % 10;
            m = m / 10;
        }

        int ans1 = n / 10;
        int ans2 = 0;

        for (int i = 0; i < count - 2; i++)
        {
            ans2 = ans2 * 10 + num[i];
        }

        ans2 = ans2 * 10 + num[count - 1];
        ans1 = ans1 * (-1);
        ans2 = ans2 * (-1);

        if (ans1 > ans2) cout << ans1;
        else cout << ans2;
    }

    return 0;
}