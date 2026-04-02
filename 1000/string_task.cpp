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
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U' || str[i] == 'y' || str[i] == 'Y')
        {
            i++;
        }
        else
        {
            cout << '.';
            if (str[i] < 97)
            {
                str[i] = str[i] + 32;
            }
            cout << str[i];
            i++;
        }
    }

    return 0;
}