#include <iostream>
#include <string>
using namespace std;

int main()
{

    string str;
    getline(cin, str);

    int n = str.length(), count = 1, flag = 1;

    for (int i = 0; i < n; i++)
    {
        if (str[i] != str[i + 1])
            count = 0;
        count++;
        if (count == 7)
        {
            flag = 0;
            break;
        }
    }

    if (flag)
        cout << "NO";
    else
        cout << "YES";

    return 0;
}