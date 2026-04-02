#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;
    getchar();

    string str;
    getline(cin, str);

    int i = 0;

    while (i < str.size() - 1 && str.size() != 0)
    {

        if (str[i] != str[i + 1])
        {
            str.erase(i, 2);
            if (i > 0)
                i--;
        }
        else
        {
            i++;
        }
    }

    cout << str.size();

    return 0;
}