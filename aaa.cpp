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

    ll t;
    cin >> t;

    while (t--) {
        ll n;
        cin >> n;
        vector<vector<ll>>adj(n+1);
        for(int i = 2 ; i <= n ; i++) {
            ll u;
            cin >> u;
            adj[u].push_back(i);
            adj[i].push_back(u);
        }
        string s;
        cin >> s;

        vector<int> vis(n+1, 0);
        ll ct = 0;
        vector<ll>bal(n+1 , 0);

        function<void(int, int)> dfs = [&](int u, int parent){
            for (int v : adj[u]){
                if (v == parent) continue;
                if(s[v-1] == 'B') bal[v]++;
                else bal[v]--;
                dfs(v, u);
            }
            for(int v : adj[u]) {
                if(v == parent) continue;
                bal[u] += bal[v];
            }
        };
        bal[1] = (s[0] == 'B' ? 1 : -1);
        dfs(1,0);
        for(int i = 1 ; i <= n ; i++) {
            if(bal[i] == 0) ct++;
        }
        cout << ct << '\n';
    }
    return 0;
}
