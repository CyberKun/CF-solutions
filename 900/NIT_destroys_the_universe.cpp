#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        long long int n;
        cin >> n;

        vector<int> x(n);

        for (int i = 0; i < n; i++)
        {
            cin >> x[i];
        }
        if (n == 1)
        {
            if (x[0] == 0)
            {
                cout << 0 << endl;
            }
            else
            {
                cout << 1 << endl;
            }
        }
        else if (n == 2)
        {
            if (x[0] == 0 && x[1] == 0)
                cout << 0 << endl;
            else
                cout << 1 << endl;
        }
        else if (n == 3)
        {
            if (x[0] == 0 && x[1] == 0 && x[2] == 0)
                cout << 0 << endl;
            else
                cout << 1 << endl;
        }
        else
        {
            int count = 1;

            for (int i = 1; i < n - 1; i++)
            {
                if (x[i] == 0)
                    count++;
            }
            if(count==n-1)
            {
                cout << 0 << endl;
            }
            cout << count << endl;
        }
    }
    return 0;
}