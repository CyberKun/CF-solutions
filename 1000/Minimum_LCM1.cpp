#include <bits/stdc++.h>
using namespace std;

int lcm(int a, int b) {
    return (a * b) / __gcd(a, b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        
        int ans1 = 1, ans2 = n - 1;
        int min_lcm = lcm(ans1, ans2);

        // Only check up to the square root of n for optimization
        for (int a = 1; a < n; ++a) {
            int b = n - a;
            
            if (b <= 0) break;

            int temp_lcm = lcm(a, b);
            if (temp_lcm < min_lcm) {
                min_lcm = temp_lcm;
                ans1 = a;
                ans2 = b;
            }
        }

        cout << ans1 << ' ' << ans2 << endl;
    }

    return 0;
}
