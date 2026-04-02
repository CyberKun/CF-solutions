#include <iostream>
#include <vector>
#include <cmath>
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

        int a1=a;
        int b1=b;
        int c1=c;
        

        if (sum1 == static_cast<int>(sum1) && ((sum1 / b) == static_cast<int>(sum1 / b)))
        {
            res[i] = "YES";
        }
        else if (sum2 == static_cast<int>(sum2) && ((sum2 / c) == static_cast<int>(sum2 / c)))
        {
            res[i] = "YES";
        }
        else if (sum3 == static_cast<int>(sum3) && ((sum3 / a) == static_cast<int>(sum3 / a)))
        {
            res[i] = "YES";
        }
        else if ( (2 * c1 - b1) % a1 == 0 || (2 * b1 - c1) % a1 == 0 || (2 * a1 - c1) % b1 == 0 || (2 * c1 - a1) % b1 == 0 || (2 * b1 - a1) % c1 == 0 || (2 * a1 - b1) % c1 == 0)
        {
            res[i] = "YES";
        }
        else
        {
            res[i] = "NO";
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << res[i] << endl;
    }

    return 0;
}