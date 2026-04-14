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

    ll n;
    cin >> n;
    vector<ll> vec(n);
    for (int i = 0; i < n; i++) cin >> vec[i];
    ll ct = 0;
    for(int i = 0 ; i < n ; i++) ct += (vec[i] == 1);
    if(ct) {
        cout << n - ct << '\n';
        return 0;
    }
    ll ans = LLONG_MAX;
    for(int i = 0 ; i < n ; i++) {
        ll gc = vec[i];
        for(int j = i+1 ; j < n ; j++) {
            gc = __gcd(gc,vec[j]);
            if(gc == 1) {
                ans = min(ans,(ll)j-i);
                break;
            }
        }
    }
    if(ans == LLONG_MAX) cout << -1 << '\n';
    else cout << n + ans - 1 << '\n';
    
    return 0;
}
