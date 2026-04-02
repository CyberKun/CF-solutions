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
        vector<ll> adj[n + 1] , vec(n + 1) , rep(n + 1 , 0) , ans;
        for(int i = 1 ; i < n ; i++) {
            ll u , v , x;
            cin >> u >> v >> x;
            adj[u].push_back(v);
            adj[v].push_back(u);
            vec[u] = max(vec[u] , x);
            vec[v] = max(vec[v] , x);
        }

        function<void(ll, ll)> dfs = [&](ll node, ll parent){
            if(adj[node].size() == 1) {
                if(vec[node] == 2) rep[node] = 1;
            }

            for (auto child : adj[node]) {
                if (child != parent) {
                    dfs(child, node);
                }
            }
            if(parent != 0) rep[parent] += rep[node] + ((vec[parent] == 2) && rep[parent] == 0);
        };

        dfs(1, 0); 
        ll ct = 0;
        for(int i = 1 ; i <= n ; i++) {
            if(rep[i] == 1) {
                ct++;
                ans.push_back(i);
            }
        }
        cout << ct << '\n';
        for(int i = 0 ; i < ans.size() ; i++) cout << ans[i] << ' ';
        cout << '\n';
    }
    return 0;
}
