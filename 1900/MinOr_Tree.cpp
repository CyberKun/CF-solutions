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

/* ================= DEBUG ================= */

void _print(int x) { cerr << x; }
void _print(ll x) { cerr << x; }
void _print(string x) { cerr << x; }
void _print(char x) { cerr << x; }
void _print(bool x) { cerr << x; }

template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(map<T, V> v);

template <class T, class V>
void _print(pair<T, V> p){
    cerr << "{";
    _print(p.first);
    cerr << ",";
    _print(p.second);
    cerr << "}";
}

template <class T>
void _print(vector<T> v){
    cerr << "[ ";
    for (T i : v) {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}

template <class T>
void _print(set<T> v) {
    cerr << "[ ";
    for (T i : v){
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}

template <class T>
void _print(multiset<T> v){
    cerr << "[ ";
    for (T i : v){
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}

template <class T, class V>
void _print(map<T, V> v){
    cerr << "[ ";
    for (auto i : v){
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}

/* ================= MATH ================= */

ll ceil_div(ll a, ll b){
    return a % b == 0 ? a / b : a / b + 1;
}

ll gcd(ll a, ll b){
    if (a == 0LL)
        return b;
    return gcd(b % a, a);
}

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

        if (pu == pv) return;

        // attach smaller to bigger
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

        if (rank[pu] < rank[pv])parent[pu] = pv;
        else if (rank[pv] < rank[pu]) parent[pv] = pu;
        else{
            parent[pv] = pu;
            rank[pu]++;
        }
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    while(t--) {

        ll n, m;
        cin >> n >> m;

        vector<vector<pair<ll, ll>>> adj(n);
        vector<vector<tuple<ll, ll, bool>>> edgs(n);
        vector<ll> vec;
        for (int i = 0; i < m; i++){
            ll u, v, w;
            cin >> u >> v >> w;
            vec.push_back(w);
            u--, v--;
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
            edgs[u].push_back({v, w, false});
        }
        map<tuple<ll,ll,ll>,ll> fq;
        

        for(int i = 30 ; i >= 0 ; i--) {
            dsu d(n);
            // for(int j = 0 ; j < n ; j++) {
            //     for(auto b : adj[j]) {
            //         ll u = b.first;
            //         ll w = b.second;
            //         if((((w >> i) & 1) == 0) && (!fq[{u,j,w}])) d.unionSize(u,j);
            //     }
            // }

            for(int u = 0 ; u < n ; u++) {
                for(auto b : edgs[u]) {
                    ll v = get<0>(b);
                    ll w = get<1>(b);
                    bool fq = get<2>(b);
                    if ((((w >> i) & 1) == 0) && (!fq)) d.unionSize(u, v);
                }
            }

            bool psbl = true;
            for(int i = 1 ; i < n ; i++) {
                if(d.findPar(i) != d.findPar(0)) {
                    psbl = false;
                    break;
                }
            }

            if(psbl) {
                // for (int j = 0; j < n; j++) {
                //     for (auto b : adj[j]) {
                //         ll u = b.first;
                //         ll w = b.second;
                //         if (((w >> i) & 1) == 1) fq[{u,j,w}]++;
                //     }
                // }
                for (int u = 0; u < n; u++){
                    for (auto& b : edgs[u]){
                        ll v = get<0>(b);
                        ll w = get<1>(b);
                        bool fq = get<2>(b);
                        if ((((w >> i) & 1) == 1)) get<2>(b) = true;
                    }
                }
            }
        }

        ll ans = 0;
        // for(int i = 0 ; i < n ; i++) {
        //     for(int j = 0 ; j < adj[i].size() ; j++) {
        //         if(fq[{(ll)i , (ll)adj[i][j].first , (ll)adj[i][j].second}]) continue;
        //         ans = (ans | adj[i][j].second);
        //     }
        // }
        for (int u = 0; u < n; u++){
            for (auto b : edgs[u]){
                ll v = get<0>(b);
                ll w = get<1>(b);
                bool fq = get<2>(b);
                if (fq) continue;
                ans = (ans | w);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
