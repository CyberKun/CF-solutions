#include <iostream>
#include <string>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        string str;
        cin.ignore();

        getline(cin, str);

        int total_length = 0, count = 0, flag = 0;

        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] == '.')
            {
                count++;
                total_length++;
            }
            else
            {
                count = 0;
            }

            if (count == 3)
            {
                cout << 2 << endl;
                flag = 1;
                break;
            }
        }

        if (flag == 0)
        {
            cout << total_length << endl;
        }
    }
    return 0;
}