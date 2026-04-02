#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m, count = 0;
    cin >> n;

    vector<vector<int>> vec(n);
    vector<string> res(n);

    for (int i = 0; i < n; i++)
    {
        vec[i].resize(3);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> vec[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        float a = vec[i][0];
        float b = vec[i][1];
        float c = vec[i][2];

        float sum1 = (a + c) / 2;
        float sum2 = (a + b) / 2;
        float sum3 = (b + c) / 2;

        int flag = 1;

        if (b == sum1 || c == sum2 || a == sum3)
        {
            res[i] = "YES";
        }
        else
        {
            for (int k = 1; k <= a * b; k++)
            {
                int r = c * k;
                if (r == sum2 || a == (r + b) / 2 || b == (a + r) / 2)
                {
                    res[i] = "YES";
                    flag = 0;
                    break;
                }
                else
                {
                    res[i] = "NO";
                }
            }

            if (flag)
            {
                for (int k = 1; k <= a * c; k++)
                {
                    int r = b * k;
                    if (r == sum1 || a == (r + c) / 2 || c == (a + r) / 2)
                    {
                        res[i] = "YES";
                        flag = 0;
                        break;
                    }
                    else
                    {
                        res[i] = "NO";
                    }
                }
            }

            if (flag)
            {
                for (int k = 1; k <= b * c; k++)
                {
                    int r = a * k;
                    if (r == sum3 || b == (r + c) / 2 || c == (r + b) / 2)
                    {
                        res[i] = "YES";
                        flag = 0;
                        break;
                    }
                    else
                    {
                        res[i] = "NO";
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << res[i] << endl;
    }

    return 0;
}