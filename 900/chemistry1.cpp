#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        string s;
        cin >> s;

        vector<int> ct;

        int ans = 0;
        for (int i = 0; i < s.size(); i++)
        {
            int count = 1;
            for (int j = i + 1; j < s.size(); j++)
            {
                if (s[i] == s[j])
                {
                    s.erase(j, 1);
                    j--;
                    count++;
                }
            }
            if ((count % 2) != 0)
                ct.push_back(count);
        }
        int size = ct.size();

        if (size - 1 > k)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "Yes" << endl;
        }
    }
    return 0;
}