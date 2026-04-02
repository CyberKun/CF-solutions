#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        char arr[8][8];

        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                cin >> arr[i][j];
            }
        }
        int flag = 0;
        int flag2 = 0;

        for (int i = 0; i < 8; i++)
        {
            if (arr[0][i] == 'B')
            {
                flag2 = 1;
                for (int j = 1; j < 8; j++)
                {
                    flag = 0;
                    if (arr[j][i] == 'R')
                    {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0)
                {
                    cout << 'B' << endl;
                    break;
                }
            }
        }
        if (flag == 1 || flag2 == 0)
            cout << 'R' << endl;
    }

    return 0;
}