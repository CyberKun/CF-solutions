#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, m, count = 0;
    cin >> n;
    m = n;

    while (m != 0)
    {
        m = m / 10;
        count++;
    }

    vector<int> num(count);

    for (int i = 0; i < count; i++)
    {
        num[i] = n % 10;
        n = n / 10;
    }

    reverse(num.begin(), num.end());
    int i = 0;

    while (i < num.size())
    {
        if ((i + 2) < num.size() && num[i] == 1 && num[i + 1] == 4 && num[i + 2] == 4)
        {
            num.erase(num.begin() + i, num.begin() + i + 3);
        }
        else if ((i + 1) < num.size() && num[i] == 1 && num[i + 1] == 4)
        {
            num.erase(num.begin() + i, num.begin() + i + 2);
        }
        else if ((i) < num.size() && num[i] == 1)
        {
            num.erase(num.begin() + i, num.begin() + i + 1);
        }
        else
            i++;
    }

    if (num.empty())
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }

    return 0;
}