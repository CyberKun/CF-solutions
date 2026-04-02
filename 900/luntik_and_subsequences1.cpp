#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

long long count_nearly_full_subsequences(const vector<long long>& arr, long long sum) {
    long long count0 = 0, count1 = 0;
    for (long long num : arr) {
        if (num == 0) count0++;
        else if (num == 1) count1++;
    }

    if (count1 == 0) return 0; 

    return count1 * pow(2, count0);
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long n, sum = 0;
        cin >> n;
        vector<long long> arr(n);

        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
            sum += arr[i];
        }

        long long result = count_nearly_full_subsequences(arr, sum);
        cout << result << endl;
    }

    return 0;
}
