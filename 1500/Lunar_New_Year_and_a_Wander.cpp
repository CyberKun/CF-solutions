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

    ll n , m;
    cin >> n >> m;
    vector<set<ll>>adj(n+1,set<ll>());
    for(int i = 0 ; i < m ; i++) {
        ll u , v;
        cin >> u >> v;
        adj[u].insert(v);
        adj[v].insert(u);
    }

    auto bfs = [&](ll start){
        set<ll> s;
        vector<ll> vis(n+1, 0);
        s.insert(start);
        vis[start] = 1;

        while (!s.empty()){
            ll node = *s.begin();
            s.erase(s.begin());
            cout << node << ' ';
            for (auto i : adj[node]){
                if (!vis[i]){
                    vis[i] = 1;
                    s.insert(i);
                }
            }
        }
        cout << '\n';
    };
    bfs(1);
    return 0;
}
