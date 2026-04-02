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

            for (int i = 0; i < x.size() - 1;)
            {
                if (x[i] == 0 && x[i + 1] == 0)
                {
                    x.erase(x.begin() + i);
                }
                else
                    i++;
            }

            if (x.size() >= 2)
            {
                if (x[0] == 0)
                    x.erase(x.begin() + 0);

                if (x[x.size() - 1] == 0)
                    x.erase(x.begin() + x.size() - 1);

                for (int i = 0; i < x.size(); i++)
                {
                    if (x[i] == 0)
                    {
                        count++;
                    }
                }
                if (count < 3)
                    cout << count << endl;
                else
                    cout << 2 << endl;
            }
            else
            {
                if (x.size() == 1)
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
                else
                {
                    cout << 1 << endl;
                }
            }
        }
    }
    return 0;
}