#include <iostream>
#include <vector>
#include <algorithm> // Include the algorithm header for std::min_element and std::max_element
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
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
            int max_diff = arr[n - 1] - arr[0]; // Initial difference between last and first elements

            // Check possible subsegment rotations
            for (int i = 0; i < n - 1; i++)
            {
                max_diff = max(max_diff, arr[n - 1] - arr[i]); // Rotate from i+1 to n
                max_diff = max(max_diff, arr[i] - arr[0]);     // Rotate from 1 to i+1
            }

            // Check full array rotation
            int min_element_val = *min_element(arr.begin(), arr.end());
            int max_element_val = *max_element(arr.begin(), arr.end());
            max_diff = max(max_diff, max_element_val - min_element_val);

            cout << max_diff << endl;
        }
    }

    return 0;
}

