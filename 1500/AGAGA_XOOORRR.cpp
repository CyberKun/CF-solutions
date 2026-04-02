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
        vector<ll> vec(n);
        for (int i = 0; i < n; i++) {
            cin >> vec[i];
        }
        vector<ll> sufxor(n,0);
        sufxor[n-1] = vec[n-1];
        for(int i = n-2 ; i >= 0 ; i--) {
            sufxor[i] = sufxor[i+1]^vec[i];
        }
        ll xo = 0;
        for(int i = 0 ; i < n ; i++) xo = xo^vec[i];

        if(xo == 0) {
            cout << "YES\n";
            continue;
        }

        ll num = 0;
        ll ct = 0;
        bool psbl = false;
        for(int i = 0 ; i < n ; i++) {
            num = num ^ vec[i];
            if(num == xo && i != n-1 && (sufxor[i+1] == 0 || sufxor[i+1] == xo)) {
                ct++;
                num = 0;
            }
        }
        if(ct > 1) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
