#include <bits/stdc++.h>
using namespace std;


int maxFriendshipPower(int N, int M, vector<vector<int>> &roads, vector<int> &A)
{
    const long long MOD = 998244353, INV2 = 499122177;
    vector<int> par(N + 1), sz(N + 1, 1);
    iota(par.begin(), par.end(), 0);

    function<int(int)> find = [&](int x) -> int
    {
        return par[x] == x ? x : par[x] = find(par[x]);
    };

    for (auto &e : roads)
    {
        int u = find(e[0]), v = find(e[1]);
        if (u != v)
        {
            par[u] = v;
            sz[v] += sz[u];
        }
    }

    vector<int> comp;
    for (int i = 1; i <= N; i++)
        if (find(i) == i)
            comp.push_back(sz[i]);
    sort(comp.rbegin(), comp.rend());
    sort(A.rbegin(), A.rend());

    long long ans = 0;
    int idx = 0;
    for (int c : comp)
    {
        long long s = 0;
        for (int j = 0; j < c; j++)
            s = (s + A[idx++]) % MOD;
        ans = (ans + s * ((s - 1 + MOD) % MOD) % MOD * INV2) % MOD;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--)
    {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> roads(M, vector<int>(2));
        for (auto &e : roads)
            cin >> e[0] >> e[1];
        vector<int> A(N);
        for (auto &x : A)
            cin >> x;
        cout << maxFriendshipPower(N, M, roads, A) << "\n";
    }
}