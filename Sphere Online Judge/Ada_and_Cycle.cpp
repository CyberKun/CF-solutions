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
        ll adj[n][n];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> adj[i][j];

        vector<vector<ll>> edges(n + 1, vector<ll>());
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (adj[i][j]) {
                    edges[i + 1].push_back(j + 1);
                }
            }
        }
        

        vector<bool> visited(n + 1, false);
        function<ll(ll)> bfs = [&](ll node)->ll {
            queue<ll> q;
            q.push(node);
            vector<ll> dist(n + 1, 0);
            visited[node] = true;
            dist[node] = 0;
            ll ct = 1;

            while (!q.empty()) {
                ll top = q.front();
                q.pop();
                for (auto e : edges[top]) {
                    if (e == node) return dist[top] + 1;
                    if (!visited[e]) {
                        visited[e] = true;
                        dist[e] = dist[top] + 1;
                        q.push(e);
                    }
                }
                ct++;
            }
            return -1;
        };
        for(int i = 1 ; i <= n ; i++) {
            ll ans = bfs(i);
            cout << (ans == -1 ? "NO WAY" : to_string(ans)) << ' ';
            fill(visited.begin(), visited.end(), false);
        }
        cout << '\n';
    }
    return 0;
}
