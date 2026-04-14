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
        ll p , q;
        cin >> p >> q;
        ll n = p + 2*q;
        ll k = 2*n+1;
        pair<ll, ll> ans = {-1, -1};
        bool psbl = false;
        for(int i = 3 ; i*i <= k ; i+=2) {
            if(k%i==0) {
                ll a = i , b = k/i;
                ll difu = abs((a-1)/2 - (b-1)/2);
                if(difu <= p) {
                    ans = {(a-1)/2,(b-1)/2};
                    break;
                }
            }
        }
       
        if(ans.first == -1) cout << -1 << '\n';
        else cout << ans.first << ' ' << ans.second << '\n';
    }
    return 0;
}
