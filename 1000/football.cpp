#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main()
{
    long long int t;
    cin >> t;
    cin.ignore();

    vector<string> str(t);

    for (int i = 0; i < t; i++)
    {
        getline(cin, str[i]);
    }

    sort(str.begin(), str.end());

    int freq = 1;
    int max = 0;
    string ans;

    for (int i = 0; i < t - 1; i++)
    {
        if (str[i] == str[i + 1])
        {
            freq++;
        }
        else
        {
            if (freq > max)
            {
                max = freq;
                ans = str[i];
            }
            freq = 1;
        }
    }

    if (freq > max)
    {
        max = freq;
        ans = str[t - 1];
    }

    cout << ans;

    return 0;
}