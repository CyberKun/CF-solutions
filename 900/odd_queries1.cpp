#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long int n, q;
        cin >> n >> q;

        vector<long long int> arr(n);
        long long int ALLsum = 0;

        for (long long int i = 0; i < n; i++) {
            cin >> arr[i];
            ALLsum += arr[i];
        }

        vector<long long int> prefixSum(n + 1, 0);
        for (long long int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + arr[i];
        }

        vector<long long int> l(q), r(q), k(q);
        vector<string> ans(q);

        for (long long int i = 0; i < q; i++) {
            cin >> l[i] >> r[i] >> k[i];
        }

        for (long long int i = 0; i < q; i++) {
            long long int sum = ALLsum;

            long long int subarraySum = prefixSum[r[i]] - prefixSum[l[i] - 1];
            sum -= subarraySum;
            sum += (r[i] - l[i] + 1) * k[i];

            if (sum % 2 == 0) {
                ans[i] = "NO";
            } else {
                ans[i] = "YES";
            }
        }

        for (const string &result : ans) {
            cout << result << endl;
        }
    }

    return 0;
}

