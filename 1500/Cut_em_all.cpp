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

/* ================= DSU ================= */

class dsu{
    vector<int> parent, size, rank;

    public:
        dsu(int n){
            parent.resize(n + 1);
            size.resize(n + 1, 1);
            rank.resize(n + 1, 0);

            for (int i = 0; i <= n; i++) parent[i] = i;
        }

        int findPar(int node){
            if (parent[node] == node) return node;
            return parent[node] = findPar(parent[node]);
        }

        void unionSize(int u, int v){
            int pu = findPar(u);
            int pv = findPar(v);

            if (pu == pv)
                return;

            if (size[pu] < size[pv]){
                parent[pu] = pv;
                size[pv] += size[pu];
            }
            else{
                parent[pv] = pu;
                size[pu] += size[pv];
            }
        }

        void unionRank(int u, int v){
            int pu = findPar(u);
            int pv = findPar(v);

            if (pu == pv) return;

            if (rank[pu] < rank[pv]) parent[pu] = pv;
            else if (rank[pv] < rank[pu]) parent[pv] = pu;
            else{
                parent[pv] = pu;
                rank[pu]++;
            }
        }

        int getSize(int x){
            return size[findPar(x)];
        }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


        ll n;
        cin >> n;

        vector<vector<ll>> adj(n);
        for (int i = 0; i < n-1; i++){
            ll u, v;
            cin >> u >> v;
            u--, v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
            
        }

        dsu d(n);

        for (int u = 0 ; u < n; u++){
            for (auto i : adj[u]){
                d.unionSize(u, i);
            }
        }

        vector<bool> vis(n,false);
        bool psbl = true;
        for(int i = 0 ; i < n ; i++) {
            if(!vis[i]) {
                vis[i] = true;
                if(d.getSize(i) % 2) {
                    psbl = false;
                    break;
                }
            }
        }
        cout << (psbl ? (n-1 - (n/2)) : -1) << '\n';
    return 0;
}