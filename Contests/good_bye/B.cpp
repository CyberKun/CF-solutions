#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    int n;

    while (t--)
    {
        cin >> n;
        int arr[n][2];
        vector<vector<int>> vec(n);

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i][0] >> arr[i][1];
        }

        for (int i = 0; i < n; i++)
        {
            int a = arr[i][0];
            vec[i].push_back(arr[i][0]);
            a++;
            while (a <= arr[i][1])
            {
                vec[i].push_back(a);
                a++;
            }
        }
        int flag = 0;
        int num[n];

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < vec[i].size(); j++)
            {
                flag = 0;
                for (int k = 0; k < n; k++)
                {
                    if (arr[k][0] == arr[k][1] && arr[k][0] == vec[i][j] && k != i)
                    {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 1)
                {
                    num[i] = 0;
                }
                else
                {
                    num[i] = 1;
                    break;
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            cout << num[i];
        }
        cout << endl;
    }

    return 0;
}



