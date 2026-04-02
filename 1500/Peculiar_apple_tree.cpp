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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t = 1;
    // cin >> t;

    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> adj[n + 1], dist(n + 1 , -1);
        for (int i = 2; i <= n; i++) {
            ll u;
            cin >> u;
            adj[i].push_back(u);
            adj[u].push_back(i);
        }

        auto bfs = [&](int src) {
            queue<int> q;
            q.push(src);
            dist[src] = 0;

            while (!q.empty()) {
                int node = q.front();
                q.pop();

                for (int child : adj[node]) {
                    if (dist[child] == -1)
                    {
                        dist[child] = dist[node] + 1;
                        q.push(child);
                    }
                }
            }
        };
        bfs(1);

        ll maxy = *max_element(dist.begin() , dist.end());
        vector<ll> depth(maxy + 1 , 0);
        for(int i = 1 ; i <= n ; i++) {
            depth[dist[i]] = ((depth[dist[i]] + 1) % 2);
        } 
        cout << accumulate(depth.begin() , depth.end() , 0ll) << '\n';

    }
    return 0;
}
