#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;

    vector<int> n(t), k(t), count(t); 
    vector<vector<int>> a(t);         

    
    for (int i = 0; i < t; i++)
    {
        cin >> n[i] >> k[i];
        a[i].resize(n[i]); 
        for (int j = 0; j < n[i]; j++)
        {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < t; i++)
    {
        sort(a[i].begin(), a[i].end(), greater<int>());
    }

    // for (int i = 0; i < t; i++)
    // {
    //     int count1 = 0, count2 = 0;

    //     for (int j = 0; j < a[i].size() - 1;)
    //     {
    //         cout << 1;

    //         if ((a[i][j] - a[i][j + 1]) > k[i])
    //         {
    //             int b = j + 1;
    //             while (b + 1 < a[i].size() && a[i][b] - a[i][b + 1] < k[i])
    //             {
    //                 count2++;
    //                 b++;
    //             }

    //             if (count1 >= count2)
    //             {
    //                 a[i].erase(a[i].begin() + j + 1, a[i].begin() + j + 1 + count2);
    //                 count[i] = count[i] + count2;
    //                 count2 = 0;
    //             }
    //             else
    //             {
    //                 a[i].erase(a[i].begin() + j - count1, a[i].begin() + j);
    //                 count[i] = count[i] + count1;
    //                 count2 = 0;
    //                 j = 0;
    //                 count1 = 0;
    //             }
    //         }
    //         else if ((a[i][j] - a[i][j + 1]) > k[i] && j + 1 == a[i].size() - 1)
    //         {
    //             a[i].erase(a[i].begin() + j + 1);
    //             break;
    //         }
    //         else
    //         {
    //             count1++;
    //             j++;
    //         }
    //     }
    // }


        // Processing each test case
    for (int i = 0; i < t; i++)
    {
        int j = 0,count1=0;
        while (j < a[i].size() - 1)
        {
            // If the difference between two consecutive elements is greater than k[i]
            if ((a[i][j] - a[i][j + 1]) > k[i])
            {
                int count2 = 0;
                int b = j + 1;

                // Count how many consecutive elements can be removed
                while (b < a[i].size() - 1 && a[i][b] - a[i][b + 1] <= k[i])
                {
                    count2++;
                    b++;
                }

                if (count1 >= count2 && count2>0)
                {
                    a[i].erase(a[i].begin() + j + 1, a[i].begin() + j + 1 + count2);
                    count[i] = count[i] + count2;
                    count2 = 0;
                }
                else if (count2>count1)
                {
                    a[i].erase(a[i].begin() + j - count1, a[i].begin() + j);
                    count[i] = count[i] + count1;
                    count2 = 0;
                    j = 0;
                    count1 = 0;
                }
                else
                {
                    a[i].erase(a[i].begin() + j); // Remove the current element if no others match
                    count[i]++;
                }
                // Continue checking from the same index to ensure no elements are skipped
            }
            else
            {
                count1++;
                j++; // If no removal, move to the next element
            }
        }
    }




    for (int i = 0; i < t; i++)
    {

        for (int j = 0; j < n[i]; j++)
        {
            cout << a[i][j];
        }
        cout << endl;
    }

    for (int i = 0; i < t; i++)
    {
        cout << count[i] << endl;
    }

    return 0;
}