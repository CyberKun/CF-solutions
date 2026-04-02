#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        int arr[n];
        int a = 1;
        int i = k - 1;
        vector<int> index;
        index.push_back(k - 1);
        while (i < n)
        {
            arr[i] = a;
            a++;
            i += k;
            if (i < n)
                index.push_back(i);
        }
        int j = 0;

        for (int i = 0; i < n; i++)
        {
            if (i == index[j])
            {
                if (j < index.size() && i == index[j])
                {
                    j++;
                }
            }
            else
            {
                arr[i] = a;
                a++;
            }
        }

        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    return 0;
}