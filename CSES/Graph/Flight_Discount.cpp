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

ll dijkstra(int n, vector<vector<pair<ll, ll>>> &adj, ll src) {
    vector<vector<ll>> dist(n, vector<ll>(2, INF));
    priority_queue<tuple<ll, ll, ll>, vector<tuple<ll, ll, ll>>, greater<>> pq;

    // {distance, node, used_discount}
    dist[src][0] = 0;
    pq.push({0, src, 0});

    while (!pq.empty())
    {
        auto a = pq.top();
        ll d = get<0>(a) , u = get<1>(a) , used = get<2>(a);
        pq.pop();

        if (d > dist[u][used]) continue;

        for (auto &edge : adj[u]) {
            ll v = edge.first;
            ll w = edge.second;

            if (dist[v][used] > d + w) {
                dist[v][used] = d + w;
                pq.push({dist[v][used], v, used});
            }

            if (!used) {
                if (dist[v][1] > d + w / 2) {
                    dist[v][1] = d + w / 2;
                    pq.push({dist[v][1], v, 1});
                }
            }
        }
    }

    return dist[n - 1][1];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m;
    cin >> n >> m;

    vector<vector<pair<ll, ll>>> adj(n);
    for (int i = 0; i < m; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        u--, v--;

        adj[u].push_back({v, w});
        // adj[v].push_back({u, w});
    }

    ll ans = dijkstra(n, adj, 0);
    cout << ans << '\n';
    return 0;
}
