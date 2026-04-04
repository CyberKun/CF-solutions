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
        ll n , W;
        cin >> n >> W;
        vector<ll> vec(n);
        for (int i = 0; i < n; i++) cin >> vec[i];
        vector<ll>pows(31,0);
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < 31 ; j++) {
                if((1<<j) == vec[i]) {
                    pows[j]++;
                    break;
                }
            }
        }
        // for(int i = 0 ; i < 31 ; i++) cout << pows[i] << ' ';
        // cout << '\n';
        ll ans = 0;
        while(accumulate(pows.begin(),pows.end(),0) != 0) {
            ll sumo = W;
            for(int i = 30 ; i >= 0 ; i--) {
                if(sumo >= (1<<i) && pows[i]) {
                    ll temp = sumo/(1<<i);
                    temp = min(temp,pows[i]);
                    pows[i] -= temp;
                    sumo -= (temp * (1<<i));
                }
            }
            ans++;
        }
        cout << ans << '\n';
        
    }
    return 0;
}
