#include <iostream>
#include <vector>
using namespace std;

int main()
{
    long long int n, count1 = 0, count2 = 0, count3 = 0, count4 = 0, totalcount = 0;
    cin >> n;

    vector<long long int> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];

        if (a[i] == 1)
            count1++;
        else if (a[i] == 2)
            count2++;
        else if (a[i] == 3)
            count3++;
        else
            count4++;
    }

    // int b = count1 % 4 + count1 / 4;
    // cout << count1 % 4 << " " << count1 / 4 << endl;

    totalcount += count4;

    if (count3 >= count1)
    {
        totalcount += count3;

        if (count2 % 2 == 0)
            totalcount += count2 / 2;
        else
            totalcount += count2 / 2 + 1;
    }
    else
    {
        totalcount += count3;
        count1 -= count3;

        if (count2 % 2 == 0)
        {
            totalcount += count2 / 2;

            if (count1 <= 4)
                totalcount++;
            else if (count1 % 4 == 0)
            {
                totalcount += count1 / 4;
            }
            else
            {
                totalcount += 1 + count1 / 4;
            }
        }
        else
        {
            totalcount += count2 / 2;

            if (count1 <= 2)
            {
                totalcount++;
            }
            else
            {
                count1 += 2;
                
                if (count1 % 4 == 0)
                {
                    totalcount += count1 / 4;
                }
                else
                {
                    totalcount += 1 + count1 / 4;
                }
            }
        }
    }

    cout << totalcount << endl;

    return 0;
}