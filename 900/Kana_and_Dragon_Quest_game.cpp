#include <iostream> 
using namespace std;

int main()
{
    int t;
    cin >> t;

    int x[t], n[t], m[t];

    for (int i = 0; i < t; i++)
    {
        cin >> x[i] >> n[i] >> m[i];
    }

    for (int i = 0; i < t; i++)
    {
        int count1 = 0, count2 = 0;
        while (x[i] > 0)
        {
            int b, c;
            b = x[i] / 2 + 10;
            c = x[i] - 10;

            if (count1 < n[i] && b < x[i])
            {
                x[i] = b;
                count1++;
            }
            else if (count2 < m[i])
            {
                x[i] = c;
                count2++;
            }
            else
            {
                break;
            }
        }

        if (x[i] <= 0)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}