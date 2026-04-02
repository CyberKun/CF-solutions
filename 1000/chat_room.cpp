#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    string str;
    getline(cin, str);

    int i = 0;
    while (str[i] != '\0')
    {
        while (str[i] != 'h' && str[i] != '\0')
        {
            i++;
        }
        if (str[i] == 'h')
        {
            i++;
            while (str[i] != 'e' && str[i] != '\0')
            {
                i++;
            }
            if (str[i] == 'e')
            {
                i++;
                while (str[i] != 'l' && str[i] != '\0')
                {
                    i++;
                }
                if (str[i] == 'l')
                {
                    i++;
                    while (str[i] != 'l' && str[i] != '\0')
                    {
                        i++;
                    }
                    if (str[i] == 'l')
                    {
                        i++;
                        while (str[i] != 'o' && str[i] != '\0')
                        {
                            i++;
                        }
                        if (str[i] == 'o')
                        {
                            cout << "YES";
                            return 0;
                        }
                    }
                }
            }
        }
    }

    cout << "NO";

    return 0;
}