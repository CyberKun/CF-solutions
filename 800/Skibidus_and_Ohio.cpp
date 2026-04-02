#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        string str;
        cin >> str;
        int flag=0;

        for(int i=0 ; i<str.size() -1 ; i++)
        {
            if(str[i] == str[i+1])
            {
                flag=1;
                break;
            }
        }

        if(flag==1)
        {
            cout << 1 << endl;
        }
        else
        {
            cout << str.size() << endl;
        }
    }

    return 0;
}
