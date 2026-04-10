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
const int MOD = 1e9 + 7;

ll mody(ll base, ll exp) {
    ll res = 1;
    base %= MOD;
    while (exp > 0){
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n , k;
    cin >> n >> k;
    vector<vector<pair<ll,ll>>> adj(n , vector<pair<ll,ll>>());
    for(int i = 1 ; i < n ; i++) {
        ll u , v , w;
        cin >> u >> v >> w;
        u--,v--,adj[u].push_back({v,w}),adj[v].push_back({u,w});
    }
    vector<ll> val(n,1);
    ll ans = 0;
    function<void(ll, ll)> dfs = [&](ll node, ll par){
        for(auto i : adj[node]) {
            if(i.first != par) {
                dfs(i.first,node);
                if(!i.second) val[node] += val[i.first]; 
            }
        }
        if (par == -1) ans = (ans + mody(val[node], k)) % MOD;
        else{
            for (auto i : adj[node]){
                if (i.first == par){
                    if (i.second) ans = (ans + mody(val[node], k)) % MOD;
                    break;
                }
            }
        }
    };
    dfs(0,-1);
    cout << (mody(n,k) + MOD - (ans) % MOD) % MOD << '\n';
}
