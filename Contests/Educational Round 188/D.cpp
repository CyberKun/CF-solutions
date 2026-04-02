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
        ll n , m;
        cin >> n >> m;
        vector<vector<ll>>adj(n + 1);
        vector<ll> ind(n+1 , 0);
        vector<ll> otd(n+1 , 0);
        vector<ll>color(n+1 , -1);
        for(int i = 0 ; i < m ; i++) {
            ll u , v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
            otd[u]++;
            ind[v]++;
        }
        ll ans = 0;
        // for(int i = 1 ; i <= n ; i++) {
        //     if(ind[i] == 0 && otd[i] == 0) ans++;
        // }

        //Taken from gfg
        auto solve = [&](int st) -> pair<int, int> {
            queue<int> q;
            q.push(st);
            color[st] = 0;
            ll cnt0 = 1 , cnt1 = 0;
            bool is_bip = true;

            while (!q.empty()) {
                ll u = q.front();
                q.pop();

                for (int v : adj[u]) {
                    if (color[v] == -1) {
                        color[v] = 1 - color[u];
                        if (color[v] == 0) cnt0++;
                        else cnt1++;
                        q.push(v);
                    }
                    else if (color[v] == color[u]) is_bip = false;
                }
            }
            if (!is_bip) return {-1, -1};
            return {cnt0, cnt1};
        };

        for(int i = 1 ; i <= n ; i++) {
            if(color[i] == -1) {
                auto cnt = solve(i);
                if(cnt.first != -1) ans += max(cnt.first , cnt.second);
            }
        }
        cout << ans << '\n';
    }
        return 0;

}
