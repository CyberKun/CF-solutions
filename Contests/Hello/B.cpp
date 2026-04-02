#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    long long int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<long long int> b(n);

        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        
        if (n == 1)
        {
            cout << 1 << endl;
        }
        else
        {

            sort(b.begin(), b.end());

            int freq = 1;
            vector<long long int> fr;
            vector<long long int> index;

            for (int i = 0; i < n - 1; i++)
            {
                if (b[i] == b[i + 1])
                {
                    freq++;
                }
                else
                {
                    fr.push_back(freq);
                    freq = 1;
                }
            }
            fr.push_back(freq);
            int k;

            if (fr.size() == 1)
            {
                cout << 1 << endl;
            }
            else
            {
                sort(fr.begin(), fr.end());

                for (int i = 0; i < fr.size() - 1; i++)
                {
                    m = m - fr[i];
                    if (m < 0)
                    {
                        cout << fr.size() - i << endl;
                        break;
                    }
                    k = i;
                }
                if (k == fr.size() - 1)
                {
                    cout << 1 << endl;
                }
            }
        }
    }

    return 0;
}