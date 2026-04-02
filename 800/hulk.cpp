#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int flag = 0;

    while (n)
    {
        if (flag == 0)
        {
            cout << "I hate ";
            flag = 1;
        }
        else
        {
            cout << "I love ";
            flag = 0;
        }
        n--;
        if (n != 0)
            cout << "that ";
    }
    cout << "it" << endl;

    return 0;
}
