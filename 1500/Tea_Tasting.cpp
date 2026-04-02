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
        vector<ll> capa(n) , tea(n) , pre(n , 0);
        vector<pair<ll,ll>> sweep(n+1,{0,0});
        for (int i = 0; i < n; i++) cin >> tea[i];
        for(int i = 0 ; i < n ; i++) cin >> capa[i];
        pre[0] = capa[0];
        for(int i = 1 ; i < n ; i++) pre[i] = pre[i-1] + capa[i];
        for(int i = 0 ; i < n ; i++) {
            if(capa[i] >= tea[i]) {
                sweep[i].second += tea[i];
                continue;
            }
            ll low = i+1 , high = n-1 , ans = i+1;
            while(low <= high) {
                ll mid = (low + high) / 2;
                ll sumo = pre[mid] - (i == 0 ? 0 : pre[i-1]);
                if(sumo <= tea[i]) {
                    low = mid + 1;
                    ans = mid + 1;
                }
                else high = mid - 1;
            }
            sweep[i].first++;
            sweep[ans].first--;
            if(i == 0) sweep[ans].second += (tea[i] - pre[ans-1]);
            else sweep[ans].second += (tea[i] - (pre[ans-1] - pre[i-1]));
        }
        ll sumi = 0;
        for(int i = 0 ; i < n ; i++) {
            sumi += sweep[i].first;
            cout << sumi*capa[i] + sweep[i].second << ' ';
        }
        cout << '\n';
    }
    return 0;
}
