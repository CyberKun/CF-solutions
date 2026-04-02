#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        string str1, str2;

        cin.ignore();
        cin >> str1 >> str2;

        vector<long long int> cnt(str2.length(), 1);

        for (long long int i = 0; i < str2.length(); i++)
        {
            for (long long int j = i + 1; j < str2.length(); j++)
            {
                if (str2[i] == str2[j])
                {
                    cnt[i]++;
                }
            }
        }
        long long int i = 0, k = -1;

        while (i < str2.length())
        {
            long long int count = 0, flag = 0;
            for (long long int j = str1.length() - 1; j > k; j--)
            {
                if (str1[j] == str2[i])
                {
                    count++;
                    if (count == cnt[i])
                    {
                        k = j;
                        flag = 1;
                        break;
                    }
                }
            }
            if (flag == 0)
            {
                cout << "NO" << endl;
                break;
            }
            i++;
        }

        if (i == str2.length())
        {
            cout << "YES" << endl;
        }
    }

    return 0;
}