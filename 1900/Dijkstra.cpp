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

vector<ll> dijkstra(int n, vector<vector<pair<ll, ll>>> &adj, ll src, vector<ll> &parent){
    vector<ll> dist(n, INF);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()){
        auto top = pq.top();
        ll d = top.first , u = top.second;
        pq.pop();
        if (d > dist[u]) continue;

        for (auto &v : adj[u]){
            if (dist[v.first] > d + v.second){
                dist[v.first] = d + v.second;
                pq.push({dist[v.first], v.first});
                parent[v.first] = u;
            }
        }
    }
    return dist;
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
    vector<ll>par(n , -1);
    vector<ll> dist = dijkstra(n, adj, 0 , par);
    if(dist[n-1] == INF) {
        cout << -1 << '\n';
        return 0;
    }
    vector<ll>ans;
    ll node = n-1;
    ans.push_back(n);
    while(node != 0) {
        ans.push_back(par[node] + 1);
        node = par[node];
    }
    reverse(ans.begin() , ans.end());
    for(int i = 0 ; i < ans.size() ; i++) cout << ans[i] << ' ';
    cout << '\n';
    return 0;
}
