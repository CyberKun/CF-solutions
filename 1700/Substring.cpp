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
        ll n , m;
        cin >> n >> m;
        string s;
        cin >> s;
        vector<vector<ll>> edges(n + 1, vector<ll>());
        for(int i = 0 ; i < m ; i++) {
            ll u , v;
            cin >> u >> v;
            u-- , v--;
            edges[u].push_back(v);
            edges[v].push_back(u);
        }

        function<void(ll, ll)> dfs = [&](ll node, ll par) {
        };

        
    }
    return 0;
}
