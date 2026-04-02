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
        vector<vector<ll>>edges(n , vector<ll>());
        for(int i = 0 ; i < m ; i++) {
            ll u , v;
            cin >> u >> v;
            edges[u].push_back(v);
            edges[v].push_back(u);
        }
        vector<bool> visited(n , false);

        function<void(ll)> dfs = [&](ll node){
            visited[node] = true;
            cout << node << ' ';
            for(auto e : edges[node]) {
                if(!visited[e]) {
                    dfs(e);
                }
            }
        };

        dfs(0);
        cout << '\n';
    }
    return 0;
}
