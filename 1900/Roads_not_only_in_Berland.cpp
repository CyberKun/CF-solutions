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
    vector<int> parent, size, rank;

public:
    dsu(int n)
    {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        rank.resize(n + 1, 0);

        for (int i = 0; i <= n; i++) parent[i] = i;
    }

    int findPar(int node)
    {
        if (parent[node] == node) return node;
        return parent[node] = findPar(parent[node]);
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

    ll t = 1;
    //cin >> t;

    while (t--) {
        ll n;
        cin >> n;
        dsu d(n);
        vector<pair<ll,ll>> vec;
        for(int i = 1 ; i < n ; i++) {
            ll u , v;
            cin >> u >> v;
            if(d.findPar(u) == d.findPar(v)) vec.push_back({u,v});
            else d.unionRank(u,v);
        }

        set<ll> se;
        for(int i = 2 ; i <= n ; i++) {
            if(d.findPar(i) != d.findPar(1) && (se.find(d.findPar(i)) == se.end())) {
                se.insert(d.findPar(i));
            }
        }
        cout << se.size() << '\n';
        int i = 0;
        for(auto p : se) {
            cout << vec[i].first << ' ' << vec[i].second << ' ' << 1 << ' ' << p << '\n';
            i++;
        }

    }
    return 0;
}