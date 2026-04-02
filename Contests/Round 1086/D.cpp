#include <bits/stdc++.h>
using namespace std;

long long minMinutes(int n, long long k, vector<long long>& t) {
    long long low = 1;
    long long high = *min_element(t.begin(), t.end()) * k;
    long long ans = high;

    while (low <= high) {
        long long mid = (low + high) / 2;
        long long produced = 0;

        for (long long x : t) {
            produced += mid / x;
            if (produced >= k) break;
        }

        if (produced >= k) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return ans;
}

int main() {
    int n;
    long long k;
    cin >> n >> k;

    vector<long long> t(n);
    for (int i = 0; i < n; i++)
        cin >> t[i];

    cout << minMinutes(n, k, t);
}