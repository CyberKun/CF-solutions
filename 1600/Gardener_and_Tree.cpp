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
    cin.tie(NULL);

    ll t;
    cin >> t;

    while (t--) {
        ll n, k;
        cin >> n >> k;

        vector<vector<ll>> adj(n + 1);
        vector<ll> deg(n + 1, 0);

        for (int i = 0; i < n - 1; i++){
            ll u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
            deg[u]++;
            deg[v]++;
        }

        if (n == 1){
            cout << 0 << '\n';
            continue;
        }

        vector<ll> kreq(n + 1, 0);
        queue<ll> q;

        for (int i = 1; i <= n; i++){
            if (deg[i] == 1){
                kreq[i] = 1;
                q.push(i);
            }
        }

        while (!q.empty()) {
            ll u = q.front();
            ll nm;
            q.pop();

            for (ll v : adj[u]) {
                if (kreq[v] == 0) {             
                    deg[v]--; 
                    if (deg[v] == 1) { 
                        kreq[v] = kreq[u] + 1;
                        q.push(v);
                    }
                }
            }
        }

        ll ct = 0;
        for (int i = 1; i <= n; i++){
            if (kreq[i] > k)
                ct++;
        }

        cout << ct << '\n';
    }

    return 0;
}
