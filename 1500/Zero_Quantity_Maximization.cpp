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

    ll t=1;
    // cin >> t;

    while (t--) {
        ll n;
        cin >> n;
        vector<ll> vec1(n) , vec2(n);
        for (int i = 0; i < n; i++) cin >> vec1[i];
        for (int i = 0; i < n; i++) cin >> vec2[i];
        map<pair<ll,ll>,ll>fq;
        ll ans = 0 , ct = 0;
        for(int i = 0 ; i < n ; i++) {
            if(!vec1[i] && !vec2[i]) {
                ct++;
                continue;
            }
            else if(!vec1[i]) continue;
            ll a = vec1[i]/__gcd(vec1[i],vec2[i]);
            ll b = vec2[i]/__gcd(vec1[i],vec2[i]);
            fq[{a,b}]++;
            ans = max(ans , fq[{a,b}]);
        }
        cout << ans + ct << '\n';
    }
    return 0;
}
