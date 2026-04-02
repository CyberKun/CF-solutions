#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        int count = 0;
        bool in_segment = false;

        for (int i = 0; i < n; i++)
        {
            if (a[i] != 0)
            {
                if (!in_segment)
                {
                    count++;
                    in_segment = true;
                }
            }
            else
            {
                in_segment = false;
            }
        }

        cout << count << endl;
    }

    return 0;
}
