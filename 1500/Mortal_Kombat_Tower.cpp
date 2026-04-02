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
const int INF = 2*1e5;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    while (t--) {
        ll n;
        cin >> n;
        vector<ll> vec(n);
        for (int i = 0; i < n; i++) cin >> vec[i];
        vector<vector<ll>>dp(n , vector<ll>(4 , INF));
        // dp[i][0] = minimum skip used to reach ith index with you having two more kill and your friend having one more kill
        // dp[i][1] = minimum skip used to reach ith index with you having two more kill and your friend having no more kill
        // dp[i][2] = minimum skip used to reach ith index with your friend having two more kill and you having one more kill
        // dp[i][3] = minimum skip used to reach ith index with your friend having two more kill and you having no more kill

        dp[0][0] = (vec[0] == 1);
        for(int i = 1 ; i < n ; i++) {
            dp[i][0] = min(dp[i-1][2] , dp[i-1][3]) + (vec[i] == 1);
            dp[i][1] = (dp[i-1][0]) + (vec[i] == 1);
            dp[i][2] = min(dp[i-1][0] , dp[i-1][1]);
            dp[i][3] = dp[i-1][2];
        }
        cout << min({dp[n-1][0] , dp[n-1][1] , dp[n-1][2] , dp[n-1][3]}) << '\n';
    }
    return 0;
}
