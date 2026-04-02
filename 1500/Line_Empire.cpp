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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    while (t--) {
        ll n , a , b;
        cin >> n >> a >> b;
        vector<ll> vec(n);
        for (int i = 0; i < n; i++) cin >> vec[i];
        vector<ll>suf(n,0) , pref(n,0);
        for(int i = n-2 ; i >= 0 ; i--) suf[i] = suf[i+1] + abs(vec[i+1] - vec[i]);
        pref[0] = 0;
        for(int i = 1 ; i < n ; i++) pref[i] = pref[i-1] + (vec[i] - vec[i-1]);
        vector<ll> dp(n,0);
        // dp[i] = minimum cost to conquer upto ith kingdom
        // dp[0] = 0;
        // dp[1] = b * (vec[1] - vec[0]);
        dp[0] = b * (vec[n-1] - vec[0]);
        int j = 0;
        for(int i = 1 ; i < n-1 ; i++) {
            // ll conq = b * (vec[i] - vec[j]);
            // ll swtc = LLONG_MAX;
            // int id = j;
            // for(int k = j + 1 ; k < i ; k++) {
            //     swtc = min(swtc , a * (vec[k] - vec[j]) + b * (vec[i] - vec[k]));
            //     if (swtc == (a * (vec[k] - vec[j]) + b * (vec[i] - vec[k]))) id = k;
            // }
            // if(swtc <= conq) {
            //     dp[i] = dp[i-1] + swtc;
            //     j = id;
            // }
            // else dp[i] = dp[i-1] + conq;
            
            // dp[i] = minimum cost to conquer all the kingdoms by shifting to the (i-1)th kingdom
            dp[i] = a * (vec[i-1] - vec[0]) + b * (vec[i] - vec[0]) + b * (vec[n-1] - vec[i]);

        }
        cout << *min_element(dp.begin() , dp.end() - 1) << '\n';
    }
    return 0;
}
