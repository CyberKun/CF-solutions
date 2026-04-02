#include <iostream>
#include <cstring>
#include <algorithm> // For std::transform
#include <cctype>    // For std::tolower
using namespace std;

int main()
{
    string str1, str2;
    getline(cin, str1);
    getline(cin, str2);

    int a1, a2;
    a1 = str1.length();
    a2 = str2.length();

    for (int i = 0; i < a1; i++)
    {
        if (str1[i] < 97)
        {
            str1[i] = str1[i] + 32;
        }
    }

    for (int i = 0; i < a2; i++)
    {
        if (str2[i] < 97)
        {
            str2[i] = str2[i] + 32;
        }
    }

    if (str1 < str2)
    {
        cout << -1 << endl;
    }
    else if (str1 > str2)
    {
        cout << 1 << endl;
    }
    else
    {
        cout << 0 << endl;
    }

    return 0;
}