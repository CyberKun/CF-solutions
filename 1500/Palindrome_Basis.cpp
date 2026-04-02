/****************************************************
██████╗ ██████╗ ██╗   ██╗████████╗███████╗███╗   ██╗
██╔══██╗██╔══██╗██║   ██║╚══██╔══╝██╔════╝████╗  ██║
██████╔╝██████╔╝██║   ██║   ██║   █████╗  ██╔██╗ ██║
██╔══██╗██╔══██╗██║   ██║   ██║   ██╔══╝  ██║╚██╗██║
██████╔╝██║  ██║╚██████╔╝   ██║   ███████╗██║ ╚████║
╚═════╝ ╚═╝  ╚═╝ ╚═════╝    ╚═╝   ╚══════╝╚═╝  ╚═══╝
***************************************************/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9 + 7;

vector<ll> getPalindromes() {
    vector<ll> pal;
    for (int i = 1; i <= 40000; i++) {
        ll x = i, rev = 0;
        while (x > 0) {
            rev = rev * 10 + (x % 10);
            x /= 10;
        }
        if (rev == i) pal.push_back(i);
    }
    return pal;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    vector<ll> pali = getPalindromes();
    vector<ll> dp(4 * 1e4 + 1, 0);
    dp[0] = 1;
    for (ll j = 0; j < pali.size(); j++) {
        ll p = pali[j];
        for (int i = p; i < dp.size(); i++) {
            dp[i] = (dp[i] + dp[i - p]) % MOD;
        }
    }

    while (t--) {
        ll n;
        cin >> n;
        cout << dp[n] << '\n';
    }
    return 0;
}
