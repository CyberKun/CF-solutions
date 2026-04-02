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
#define endl '\n'

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
void _print(pair<T, V> p)
{
    cerr << "{";
    _print(p.first);
    cerr << ",";
    _print(p.second);
    cerr << "}";
}

template <class T>
void _print(vector<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}

template <class T>
void _print(set<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}

template <class T>
void _print(multiset<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}

template <class T, class V>
void _print(map<T, V> v)
{
    cerr << "[ ";
    for (auto i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}

/* ================= MATH ================= */

ll ceil_div(ll a, ll b)
{
    return a % b == 0 ? a / b : a / b + 1;
}

ll gcd(ll a, ll b)
{
    if (a == 0LL)
        return b;
    return gcd(b % a, a);
}

/* ================= DSU ================= */

class dsu
{
public:
    vector<int> parent, size, rank;
    dsu(int n)
    {
        parent.resize(n + 2);
        size.resize(n + 2, 1);
        rank.resize(n + 2, 0);

        for (int i = 1; i <= n + 1; i++)
        {
            parent[i] = i;
        }
    }

    int findPar(int node)
    {
        if (parent[node] == node)
            return node;
        return parent[node] = findPar(parent[node]); // path compression
    }

    void unionSize(int u, int v)
    {
        int pu = findPar(u);
        int pv = findPar(v);

        if (pu == pv)
            return;

        // attach smaller to bigger
        if (size[pu] < size[pv])
        {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else
        {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }

    void unionRank(int u, int v)
    {
        int pu = findPar(u);
        int pv = findPar(v);

        if (pu == pv)
            return;

        if (rank[pu] < rank[pv])
        {
            parent[pu] = pv;
        }
        else if (rank[pv] < rank[pu])
        {
            parent[pv] = pu;
        }
        else
        {
            parent[pv] = pu;
            rank[pu]++;
        }
    }
};

/* ================= MAIN ================= */

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n , q;
    cin >> n >> q;
    vector<ll>ans(n+2,0);
    vector<tuple<ll,ll,ll>> lrc(q);

    for(int i = 0 ; i < q ; i++) {
        ll l , r , c;
        cin >> l >> r >> c;
        lrc[i] = {l,r,c};
    }

    dsu d(n);

    for(int i = q-1 ; i >= 0 ; i--) {
        if(d.findPar(get<0>(lrc[i])) > get<1>(lrc[i])) continue;
        ll l = get<0>(lrc[i]) , r = get<1>(lrc[i]) , c = get<2>(lrc[i]);
        ll node = d.findPar(l);
        while(node <= r) {
            ans[node] = c;
            d.parent[node] = d.findPar(node + 1);
            node = d.findPar(node);
        }
    }
    for(int i = 1 ; i <= n ; i++) cout << ans[i] << ' ';
    cout << '\n';
    return 0;
}