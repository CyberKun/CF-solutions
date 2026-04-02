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
        ll n;
        cin >> n;
        vector<pair<ll,ll>> deg(n + 1 , {0,0});
        for(int i = 1 ; i <= n ; i++) deg[i].second = i;
        vector<pair<ll,ll>>edg;
        vector<vector<ll>>adj(n+1);
        
        for(int i = 0 ; i < n - 1 ; i++) {
            ll u , v;
            cin >> u >> v;
            edg.push_back({u,v});
            adj[u].push_back(v);
            adj[v].push_back(u);
            deg[u].first++;
            deg[v].first++;
        }
        if(n <= 3) {
            for(int i = 0 ; i < n - 1 ; i++) cout << i << '\n';
            continue;
        }

        sort(deg.begin() + 1 , deg.end());
        map<pair<ll,ll>,ll> fq;
        fq[{deg[1].second, adj[deg[1].second][0]}] = 1;
        fq[{deg[2].second, adj[deg[2].second][0]}] = 2;
        fq[{deg[3].second, adj[deg[3].second][0]}] = 3;
        ll a = 3;
        for(int i = 0 ; i < n - 1 ; i++) {
            if(fq[{edg[i].first , edg[i].second}]) cout << fq[{edg[i].first, edg[i].second}] - 1 << '\n';
            else if (fq[{edg[i].second, edg[i].first}]) cout << fq[{edg[i].second, edg[i].first}] - 1 << '\n';
            else {
                cout << a << '\n';
                a++;
            }
        }
    }
    return 0;
}
