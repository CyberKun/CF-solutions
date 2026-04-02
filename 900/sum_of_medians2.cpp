#include <bits/stdc++.h>
using namespace std;

int main() {
    long long int t;
    cin >> t;

    while (t--) {
        long long int n, k;
        cin >> n >> k;

        int s = n * k;
        long long int sum = 0;
        vector<int> vec(s);

        for (int i = 0; i < s; i++) {
            cin >> vec[i];
        }

        // To maximize the sum of medians, start picking the medians from the back of the sorted array
        // Calculate the position of the median in each subarray of size n
        int median_pos = (n + 1) / 2 - 1; // 0-based index of the median
        
        // Start picking medians from the sorted array
        for (int i = 0; i < k; i++) {
            // Pick the i-th median from the end
            sum += vec[s - (i * n + median_pos + 1)];
        }

        cout << sum << endl;
    }

    return 0;
}
