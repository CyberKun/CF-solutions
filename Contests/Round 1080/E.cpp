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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    while (t--)
    {
        ll n;
        cin >> n;

        vector<vector<ll>> adj(n + 1);
        vector<ll> val(n + 1, 0);

        for (int i = 0; i < n; i++)
        {
            ll l, r;
            cin >> l >> r;
            if (l != 0)
            {
                adj[i].push_back(l);
                adj[l].push_back(i);
            }
            if (r != 0)
            {
                adj[i].push_back(r);
                adj[r].push_back(i);
            }
        }

        function<void(ll, ll)> ifs = [&](ll node, ll par)
        {
            ll chd = 0, sum = 0;

            for (ll nxt : adj[node])
            {
                if (nxt == par)
                    continue;
                ifs(nxt, node);
                sum = (sum + val[nxt]) % MOD;
                chd++;
            }

            if (chd == 0)
            {
                val[node] = 1;
            }
            else
            {
                val[node] = (3 + sum) % MOD;
            }
        };

        ifs(0, -1);

        vector<ll> out(n + 1);
        out[0] = 0;

        for (int i = 1; i <= n; i++)
        {
            out[i] = val[i - 1];
        }

        for (int i = 0; i <= n; i++)
        {
            cout << out[i] << " ";
        }
        cout << "\n";

        for (int i = 1; i <= n; i++)
        {
            cout << val[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}
