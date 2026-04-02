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
        vector<pair<ll,ll>> vec(n,{0,0});
        for (int i = 0; i < n; i++) cin >> vec[i].first;
        vector<ll> deg(n+1,0);

        for(int i = 0 ; i < n-1 ; i++) {
            ll u , v;
            cin >> u >> v;
            vec[u-1].second++;
            vec[v-1].second++;
            deg[u]++;
            deg[v]++;
        }
        sort(vec.begin() , vec.end());
        reverse(vec.begin() , vec.end());
        ll sumo = 0;
        for(int i = 0 ; i < n ; i++) sumo += vec[i].first;

        // vector<ll> prefFV(n + 1, 0), prefV(n + 1, 0);

        // for (int i = 0; i < n; i++)
        // {
        //     prefFV[i + 1] = prefFV[i] + vec[i].first * vec[i].second;
        //     prefV[i + 1] = prefV[i] + vec[i].second;
        // }

        vector<ll> ans(n-1);

        // for (int k = 0; k < n-1; k++) {
        //     ll limit = k + 1;
        //     ll idx = upper_bound(vec.begin(), vec.end(), make_pair(limit, LLONG_MAX)) - vec.begin();
        //     ll sum1 = prefFV[idx];
        //     ll sum2 = limit * (prefV[n] - prefV[idx]);
        //     ans[k] = sum1 + sum2;
        // }

        ans[0] = sumo;
        int j = 0;
        for(int i = 1 ; i < n-1 ; i++) {
            while(j < n && vec[j].second <= 1) j++;
            if(j < n) {
                sumo += vec[j].first;
                vec[j].second--;
            }
            ans[i] = sumo;
        }

        for (int i = 0; i < n-1; i++) cout << ans[i] << " ";
        cout << "\n";
    }
    return 0;
}
