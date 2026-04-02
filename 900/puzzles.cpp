#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n, m, max2,max1=1001;
    cin >> m >> n;
    int num[n];

    for(int i=0;i<n;i++)
    {
        cin >> num[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (num[i] > num[j])
            {
                int temp = num[i];
                num[i] = num[j];
                num[j] = temp;
            }
        }
    }

    for (int i = 0; i <=(n - m); i++)
    {
        int a=i+m-1;
        max2 =num[a] - num[i];

        if (max2 < max1)
            max1 = max2;
    }

    cout << max1 << endl;
    return 0;
}