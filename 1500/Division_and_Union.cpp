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
        ll n;
        cin >> n;
        vector<tuple<ll,ll,ll,ll>>inp(n);
        ll vi = -1;
        for(int i = 0 ; i < n ; i++) {
            ll u , v;
            cin >> u >> v;
            if(u > v) swap(u,v);
            inp[i] = {u,v,i,1};
        }
        sort(inp.begin() , inp.end());
        ll a = get<0>(inp[0]) , b = get<1>(inp[0]);
        bool chgd = false;
        for(int i = 1 ; i < n ; i++) {
            if(chgd) {
                get<3>(inp[i]) = 2;
                continue;
            }
            if(get<0>(inp[i]) > b) {
                chgd = true;
                get<3>(inp[i]) = 2;
            }
            else b = max(b,get<1>(inp[i]));
        }
        if(!chgd) {
            cout << -1 << '\n';
            continue;
        }
        sort(inp.begin(), inp.end(), [](const auto &a, const auto &b){
            return get<2>(a) < get<2>(b); });

        for(int i = 0 ; i < n ; i++) cout << get<3>(inp[i]) << ' ';
        cout << '\n';
    }
    return 0;
}
