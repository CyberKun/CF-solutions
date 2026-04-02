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
    cin >> t;
    ll sc = 1;

    while (t--) {
        cout << "Scenario #" << sc++ << ":\n";
        ll n , m;
        cin >> n >> m;
        vector<vector<ll>> edges(n + 1, vector<ll>());
        for(int i = 0 ; i < m ; i++) {
            ll u , v;
            cin >> u >> v;
            edges[u].push_back(v);
            edges[v].push_back(u);
        }
        vector<int> pari(n + 1, -1);
        bool psbl = false;

        for (int i = 1; i <= n; i++) {
            if (pari[i] != -1) continue;
            queue<ll> q;
            q.push(i);
            pari[i] = 0;
            while (!q.empty()) {
                ll node = q.front();
                q.pop();
                for (auto e : edges[node]) {
                    if (pari[e] == -1) {
                        pari[e] = 1 - pari[node];
                        q.push(e);
                    }
                    else if (pari[e] == pari[node]) {
                        psbl = true;
                        break;
                    }
                }
                if (psbl) break;
            }
            if (psbl) break;
        }

        if (psbl) cout << "Suspicious bugs found!\n";
        else cout << "No suspicious bugs found!\n";
    }
    return 0;
}
