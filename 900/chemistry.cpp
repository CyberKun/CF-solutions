#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    int t;
    cin >> t;
    int n[t], k[t];

    vector<string> str(t);

    for (int i = 0; i < t; i++)
    {
        cin >> n[i] >> k[i];
        getchar();
        getline(cin, str[i]);
    }

    for (int i = 0; i < t; i++)
    {
        cout << str[i] << ' ' << str[i].size() << endl;
    }

    for (int i = 0; i < t; i++)
    {
        int count = 0;
        int flag = 1,flag1=1;
        int j = 0, l = str[i].size()-1;
        while (j < l)
        {
            if (str[i][j] == str[i][l])
            {
                if(j+1>l)
                {
                    cout << 6;
                j++;
                l--;
                }
                else
                break;
            }
            else if (count < k[i])
            {
                if (str[i][j] == str[i][l - 1])
                {
                    cout << 1;
                    str[i].erase(l, 1);
                    count++;
                    l=l-2;
                    j++;
                }
                else if (str[i][l] == str[i][j + 1])
                {
                    cout << 2;
                    str[i].erase(j, 1);
                    count++;
                    l=l-2;
                    j++;
                }
                else if (count +2 <=k[i])
                {
                    cout << 3;
                    str[i].erase(l, 1);
                    str[i].erase(j, 1);
                    l=l-2;
                    count=count+2;
                }
                else
                {
                    flag1=0;
                    flag=0;
                    cout << "NO" << endl;
                    break;
                }
            }
            else
            {
                if(flag1)
                cout << "NO" << endl;
                flag=0;
                break;
            }
        }
        if(flag)
        cout << "YES" << endl;
    }

    return 0;
}