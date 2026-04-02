#include <iostream>
#include <string>
using namespace std;

int main()
{
    int t;
    cin >> t;
    cin.ignore();

    while (t--)
    {
        string str;
        getline(cin, str);

        int ab = 0, ba = 0;

        for (int i = 0; i < str.length() - 1; i++)
        {
            if (str[i] == 'a' && str[i + 1] == 'b')

                ab++;

            else if (str[i] == 'b' && str[i + 1] == 'a')

                ba++;
        }

        if (ab == ba)
        {
            cout << str << endl;
        }
        else if (ab > ba)
        {
            if (str[0] == 'a' && str[1] == 'b')
                str[0] = 'b';
            else
                str[str.length() - 1] = 'a';

            cout << str << endl;
        }
        else
        {
            if (str[str.length() - 1] == 'a' && str[str.length() - 2] == 'b')
                str[str.length() - 1] = 'b';
            else
                str[0] = 'a';

            cout << str << endl;
        }
    }

    return 0;
}

// cout << ab << ' ' << ba << endl;

// cout << "ab" << ' ' << i << endl;