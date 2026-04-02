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
        vector<ll> par(n + 1 , -1) , adj[n + 1] , vec(n + 1 , -1) , child[n + 1];
        ll root = -1;
        for (int i = 1; i <= n; i++) {
            cin >> par[i];
            cin >> vec[i];
            if(par[i] == -1) {
                root = i;
                continue;
            }
            adj[i].push_back(par[i]);
            adj[par[i]].push_back(i);
            child[par[i]].push_back(i);
            
        }

        // for(int i = 1 ; i <= n ; i++) {
        //     cout << i << "->";
        //     for(int j = 0 ; j < child[i].size() ; j++) cout << child[i][j] << ' ';
        //     cout << '\n';
        // }

        vector<ll> ans;
        for(int i = 1 ; i <= n ; i++) {
            if(par[i] == -1) continue;
            if(vec[i] == 1) {
                bool psbl = true;
                for(int j = 0 ; j < child[i].size() ; j++) {
                    if(!vec[child[i][j]]) {
                        psbl = false;
                        break;
                    }
                }
                if(psbl) {
                    ans.push_back(i);
                    ll p = par[i];
                    // for (ll v : child[i]){
                    //     par[v] = p;
                    //     child[p].push_back(v);
                    // }
                    // auto &v = child[par[i]];
                    // v.erase(remove(v.begin(), v.end(), i), v.end());
                    // child[i].clear();
                }
            } 
        }

        if(!ans.size()) {
            cout << -1 << '\n';
            continue;
        }

        for(int i = 0 ; i < ans.size() ; i++) cout << ans[i] << ' ';
        cout << '\n';
    }
    return 0;
}
