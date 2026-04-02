#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        long long int n;
        cin >> n;

        int a = n, count = 0;

        while (a != 0)
        {
            a /= 10;
            count++;
        }

        int cnt = 0;

        vector<int> num(count);

        for (int i = count - 1; i >= 0; i--)
        {
            num[i] = n % 10;
            n /= 10;
        }

        int i = num.size() - 1;

        while (num[i] != 0 && num[i] != 5 && i >= 0)
        {
            cnt++;
            i--;
        }

        int cnt2 = cnt;
        int cnt1 = cnt;
        int index = i, flag = 0;

        if (num[i] == 0)
        {
            i--;
            while (num[i] != 0 && num[i] != 5 && i >= 0)
            {
                cnt++;
                i--;
            }
        }
        else if (num[i] == 5)
        {
            index--;
            i--;
            while (num[i] != 2 && num[i] != 7 && i >= 0)
            {
                cnt1++;
                i--;
            }
            if (num[index] == 0 && index > 0)
                flag = 1;
            while (num[index] != 0 && index >= 0)
            {
                cnt2++;
                flag = 1;
                index--;
                if (index == 0)
                    flag = 0;
            }

            if (flag == 1)
            {
                index--;
                while (num[index] != 0 && num[index] != 5 && i >= 0)
                {
                    cnt2++;
                    index--;
                }

                if (cnt2 + 1 < cnt1)
                    cnt1 = cnt2 + 1;
            }
            cnt = cnt1;
        }

        cout << cnt << endl;
    }
    return 0;
}