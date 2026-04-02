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

        vector<int> arr(n);

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        if (n == 1)
        {
            cout << 0 << endl;
        }
        else
        {
            vector<int> ans;
            int ans1 = arr[0] - arr[1];
            int hd = arr[0] - arr[n - 1];

            // if (ld > 0 && hd > 0)
            // {
            //     int min = arr[1];
            //     int max = arr[0];
            // }
            // else if (ld > 0 && hd < 0)
            // {
            //     int min = arr[1];
            //     int max = arr[n - 1];
            // }
            // else if (ld < 0 && hd > 0)
            // {
            //     int min = arr[1];
            //     int max = arr[0];
            // }
            int min = arr[0];
            int max = arr[n - 1];
            int ans2 = arr[n - 2] - arr[n - 1];

            ans.push_back(ans1);
            ans.push_back(ans2);

            sort(arr.begin(), arr.end());

            if (min - arr[0] > arr[n - 1] - max)
            {
                int diff2 = max - arr[0];
                ans.push_back(diff2);
            }
            else if (min - arr[0] < arr[n - 1] - max)
            {
                int diff2 = arr[n - 1] - min;
                ans.push_back(diff2);
            }
            else
            {
                int diff2 = max - min;
                ans.push_back(diff2);
            }

            int a =*max_element(ans.begin(), ans.end());

            cout << *max_element(ans.begin(), ans.end()) << endl;
        }
    }
    return 0;
}