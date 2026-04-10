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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        vector<ll> vec(n);
        for (int i = 0; i < n; i++)
            cin >> vec[i];
        ll k;
        cin >> k;
        k--;
        // int curr = vec[k];
        // int i = k, j = k;
        // ll ans = 0;
        // while(i >= 0 || j < n) {
        //     while(i >= 0 && vec[i] == curr) i--;
        //     while(j < n && vec[j] == curr) j++;
        //     if (i >= 0 || j < n) ans++;
        //     curr = (!curr);
        //     // cout << curr << '\n';
        // }
        // if(curr != vec[k]) cout << ans <<'\n';
        // else cout << ans+1 << '\n';
        ll ct1 = 0, ct2 = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (i < k && vec[i] != vec[i + 1])
                ct1++;
            if (i >= k && vec[i] != vec[i + 1])
                ct2++;
        }
        cout << ((ct1 > ct2) ? (ct1 + (vec[0] != vec[k])) : (ct2 + (vec[n - 1] != vec[k]))) << '\n';
    }
    return 0;
}
