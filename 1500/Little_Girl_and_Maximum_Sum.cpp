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

    ll n , q;
    cin >> n >> q;
    vector<ll>vec(n) , sweep(n+1,0);
    for(int i = 0 ; i < n ; i++) cin >> vec[i];
    for(int i = 0 ; i < q ; i++) {
        ll l , r;
        cin >> l >> r;
        sweep[l-1]++;
        sweep[r]--;
    } 
    for(int i = 1 ; i < n ; i++) sweep[i] += sweep[i-1];
    sort(sweep.begin(),sweep.end());
    reverse(sweep.begin(),sweep.end());
    sort(vec.begin(), vec.end());
    reverse(vec.begin(), vec.end());
    ll ans = 0;
    for(int i = 0 ; i < n ; i++) ans += vec[i]*sweep[i];
    cout << ans << '\n';
    return 0;
}
