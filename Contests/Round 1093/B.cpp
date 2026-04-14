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
        ll n,m;
        cin >> n >> m;
        vector<ll> vec(n);
        for (int i = 0; i < n; i++) cin >> vec[i];
        ll ct = 1 , mxct = 1;
        for(int i = 0 ; i < n-1 ; i++) {
            if(vec[i] == vec[i+1]) ct++;
            else ct = 1;
            mxct = max(mxct,ct);
        }
        if(mxct < m) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}
