#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, l, r;
        cin >> n >> l >> r;

        vector<int> arr(n);
        vector<int> vec1;
        vector<int> vec2;
        vector<int> vec3;

        int sum = 0;

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        int maxsum = sum;

        int i = 0;
        while (i < l-1)
        {
            vec1.push_back(arr[i]);
            i++;
        }
        while (i < r)
        {
            vec2.push_back(arr[i]);
            sum += vec2[i];
            i++;
        }
        while (i < n)
        {
            vec3.push_back(arr[i]);
            i++;
        }

        sort(vec1.begin(), vec1.end());
        sort(vec2.begin(), vec2.end(), greater<int>());
        sort(vec3.begin(), vec3.end());

        int sum2 = sum;

        for (int i = 0; i < vec2.size(); i++)
        {
            if (vec1[i] < vec2[i])
            {
                sum2 = sum2 - vec2[i];
                sum2 = sum2 + vec1[i];
            }
            else
            {
                break;
            }
        }

        int sum3 = sum;

        for (int i = 0; i < vec2.size(); i++)
        {
            if (vec3[i] < vec2[i])
            {
                sum3 = sum3 - vec2[i];
                sum3 = sum3 + vec3[i];
            }
            else
            {
                break;
            }
        }

        cout << min(sum2, sum3) << endl;
    }

    return 0;
}
