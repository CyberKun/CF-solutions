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
        ll n, m;
        cin >> n >> m;
        vector<vector<ll>> edges(n, vector<ll>());
        for (int i = 0; i < m; i++) {
            ll u, v;
            cin >> u >> v;
            edges[u].push_back(v);
            edges[v].push_back(u);
        }
        vector<bool> visited(n, false);

        function<void(ll)> bfs = [&](ll node) {
            queue<ll> q;
            q.push(node);
            visited[node] = true;

            while(!q.empty()) {
                ll top = q.front();
                q.pop();
                cout << top << ' ';
                for (auto e : edges[top]) {
                    if (!visited[e]) {
                        visited[e] = true;
                        q.push(e);
                    }
                }
            }
        };

        bfs(0);
        cout << '\n';
    }
    return 0;
}
