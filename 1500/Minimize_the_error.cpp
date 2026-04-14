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

    ll t = 1;
    // cin >> t;

    while (t--) {
        ll n , k1 , k2;
        cin >> n >> k1 >> k2;
        vector<pair<ll,ll>> vec(n);
        for (int i = 0; i < n; i++) cin >> vec[i].first;
        for (int i = 0; i < n; i++) cin >> vec[i].second;

        sort(vec.begin(), vec.end(), [](const pair<ll, ll> &a, const pair<ll, ll> &b){
       // if (a.first != b.first) return a.first < b.first;
        return abs((a.first - a.second)) > abs(b.first - b.second); });

        // for(int i = 0 ; i < n ; i++) cout << vec[i].first << ' ' << vec[i].second << '\n';
        ll tot = k1+k2;
        ll curr = abs(vec[0].first - vec[0].second);
        ll lstidx = -1;
        for(int i = 1 ; i < n ; i++) {
            if((curr - abs(vec[i].first - vec[i].second))*i <= tot) {
                tot -= (curr - abs(vec[i].first - vec[i].second)) * i;
                curr = abs(vec[i].first - vec[i].second);
            }
            else {
                lstidx = i;
                break;
            }
        }
        ll ans = 0;
        if(lstidx != -1) {
            ll sub = tot/lstidx;
            ll ext = tot % lstidx;
            
            for(int i = 0 ; i < lstidx ; i++) {
                if(i < ext) ans += (curr - sub - 1)*(curr - sub - 1);
                else ans += (curr - sub)*(curr - sub);
            }
            for(int i = lstidx ; i < n ; i++) ans += (vec[i].first - vec[i].second)*(vec[i].first - vec[i].second);
        }
        else {
            if(curr*n >= tot) {
                ll sub = tot/n;
                ll ext = tot%n;
                for(int i = 0 ; i < n ; i++) {
                    if(i < ext) ans += (curr - sub - 1)*(curr - sub - 1);
                    else ans += (curr - sub)*(curr - sub);
                }
            }
            else {
                tot -= curr*n;
                if(tot % 2) ans = 1;
                else ans = 0;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
