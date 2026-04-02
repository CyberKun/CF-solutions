#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    cin.ignore();

    while (t--)
    {
        string s;
        getline(cin, s);

        if (s.length() == 1)
        {
            cout << 1 << endl;
        }
        else
        {
            int count1 = 0, count0 = 0;

            for (int i = 0; i < s.length(); i++)
            {
                if (s[i] == '0')
                    count0++;
                else
                    count1++;
            }

            if (count0 == count1)
                cout << 0 << endl;
            else if (count1 == s.length() || count0 == s.length())
            {
                cout << s.length() << endl;
            }
            else
            {
                for (int i = 0; i < s.length(); i++)
                {
                    if (s[i] == '0')
                        count1--;
                    else
                        count0--;

                    if (count1 < 0 || count0 < 0)
                    {
                        cout << s.length() - i  << endl;
                        break;
                    }
                }
            }
        }
    }
    return 0;
}