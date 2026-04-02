#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        long long int n;
        cin >> n;

        vector<long long int> size;
        size.push_back(1);
        long long int count = 0, sz = 0;

        long long int x = n;

        for (int i = 2; i <= x; i++)
        {
            while (x % i == 0)
            {
                x = x / i;
                size.push_back(i);
            }
        }

        for (int i = 0; i < size.size(); i++)
        {
            cout << size[i] << ' ';
        }
        cout << endl;

        // for (int i = 1; i <= n / 2; i++)
        // {
        //     if (n % i == 0)
        //     {
        //         count++;
        //     }
        //     else
        //     {
        //         if (count > sz)
        //         {
        //             sz = count;
        //         }
        //         count = 0;
        //     }
        // }

        // cout << sz << endl;
    }
    return 0;
}