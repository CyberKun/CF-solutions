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
        vector<vector<ll>> edges(n + 1, vector<ll>());
        set<ll> st1 , st2;
        for(int i = 0 ; i < n - 1 ; i++) {
            ll u , v;
            cin >> u >> v;
            edges[u].push_back(v);
            edges[v].push_back(u);
        }

        function<void(ll,ll)> bfs = [&](ll node , ll par) {
            if(par == -1) st1.insert(node);
            else if(st1.count(par)) st2.insert(node);
            else st1.insert(node);

            for(auto e : edges[node]) {
                if(e != par) bfs(e , node);
            }
        };

        bfs(1, -1);
        cout << (st1.size() * st2.size()) - (n - 1) << '\n';
    }
    return 0;
}
