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
        vector<ll> adj[n + 1], degree(n + 1, 0);
        for (int i = 1; i < n; i++) {
            ll u , v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
            degree[u]++;
            degree[v]++;
        }
        ll k = *max_element(degree.begin() , degree.end()) + 1;
        ll root = -1;
        for(int i = 1 ; i <= n ; i++) {
            if(degree[i] == k - 1) root = i;
        }
        vector<ll> ans(n + 1 , 0) , par(n + 1 , -1);

        auto bfs = [&](int src) {
            queue<int> q;
            vector<int> vis(n + 1, 0);
            q.push(src);
            vis[src] = 1;
            while (!q.empty()){
                int u = q.front();
                q.pop();
                for (int v : adj[u]){
                    if (!vis[v]){
                        vis[v] = 1;
                        par[v] = u;
                        q.push(v);
                    }
                }
            }
        };
        // set<int> s;
        // for (int i = 1; i <= k; i++) s.insert(i);

        auto afs = [&](int src , ll k) {
            queue<int> q;
            vector<int> vis(n + 1, 0);
            q.push(src);
            vis[src] = 1;
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                //vector<bool> visited(n + 1 , false);
                ll i = 1;
                // s.erase(ans[u]);
                // if(par[u] != -1) s.erase(ans[par[u]]);
                
                for (int v : adj[u]) {
                    if (!vis[v]) {
                        vis[v] = 1;
                        if(!ans[v]) {
                            if(i == ans[u]) i++;
                            if(par[u] != -1 && i == ans[par[u]]) i++;
                            if (i == ans[u]) i++;
                            if(i > k) i = 1;
                            ans[v] = i;
                            i++;
                        }
                        q.push(v);
                    }
                }
                // visited.clear();
            }
        };

        ans[root] = 1;
        for(int i = 0 ; i < adj[root].size() ; i++) ans[adj[root][i]] = i + 2;
        bfs(root);
        afs(root , k);
        cout << k << '\n';
        for(int i = 1 ; i <= n ; i++) cout << ans[i] << ' ';
        cout << '\n';
    }
    return 0;
}
