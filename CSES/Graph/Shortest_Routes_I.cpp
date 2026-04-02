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
const ll INF = 1e18;

vector<ll> dijkstra(int n, vector<vector<pair<ll, ll>>> &adj, ll src) {
    vector<ll> dist(n, INF);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        auto top = pq.top();
        ll d = top.first;
        int u = top.second;
        pq.pop();

        if (d > dist[u]) continue; 

        for (auto &v : adj[u]) {
            if (dist[v.first] > d + v.second) {
                dist[v.first] = d + v.second;
                pq.push({dist[v.first], v.first});
            }
        }
    }
    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m;
    cin >> n >> m;

    vector<vector<pair<ll, ll>>> adj(n);
    for (int i = 0; i < m; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        u--, v--; 

        adj[u].push_back({v, w});
        // adj[v].push_back({u, w});
    }

    vector<ll> dist = dijkstra(n, adj, 0);
    for(int i = 0 ; i < n ; i++) cout << dist[i] << ' ';
    cout << '\n';
    return 0;
}
