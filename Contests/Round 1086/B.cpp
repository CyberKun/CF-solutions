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
        ll n , k , p , m;
        cin >> n >> k >> p >> m;
        vector<ll> vec(n);
        for (int i = 0; i < n; i++) cin >> vec[i];
        ll ans = 0;
        if(p > k) {
            vector<ll> num;
            ll cst = 0;
            for (int i = 0; i < p - 1 ; i++) num.push_back(vec[i]);
            sort(num.begin() , num.end());
            size_t sz = p - 1 - (k - 1);
            for(int i = 0 ; i < min(sz , num.size()) ; i++) cst += num[i];
            if(cst + vec[p - 1] > m) {
                cout << 0 << '\n';
                continue;
            } 
            ans++;
            m -= (cst + vec[p - 1]);
        }
        else {
            if (m >= vec[p - 1]) {
                ans++;
                m -= vec[p - 1];
            }
            else {
                cout << 0 << '\n';
                continue;
            }
        }

        vector<ll> vec2;
        for(int i = 0 ; i < n ; i++) {
            if(i != (p - 1)) vec2.push_back(vec[i]);
        }
        sort(vec2.begin() , vec2.end());
        ll cos = 0;
        for(int i = 0 ; i < vec2.size() - (k - 1) ; i++) cos += vec2[i];
        cos += vec[p - 1];
        ans += m / cos;
        cout << ans << '\n';
    }
    return 0;
}
