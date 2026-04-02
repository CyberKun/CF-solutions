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
        ll n, h, k;
        cin >> n >> h >> k;
        vector<ll> vec(n);
        for (int i = 0; i < n; i++)
            cin >> vec[i];

        ll sumo = accumulate(vec.begin(), vec.end(), 0ll);
        ll fn = h % sumo;
        ll tim = (h / sumo) * (k + n);

        if (fn == 0)
        {
            cout << tim - k << '\n';
            continue;
        }
        vector<ll> pre(n + 1, 0);
        pre[0] = vec[0];
        ll id = -1;
        for (int i = 1; i < n; i++)
        {
            pre[i] = pre[i - 1] + vec[i];
        }

        // for (int i = 1; i < n; i++)
        // {
        //     if (pre[i] >= fn) {
        //         id = i;
        //         break;
        //     }
        // }

        vector<ll> mx(n, 0), mn(n, 0);
        mn[0] = vec[0];
        for (int i = 1; i < n; i++)
            mn[i] = min(vec[i], mn[i - 1]);
        mx[n - 1] = vec[n - 1];
        for (int i = n - 2; i >= 0; i--)
            mx[i] = max(vec[i], mx[i + 1]);

        ll ans = n - 1;
        for (int i = 1; i < n; i++)
        {
            if (pre[i] >= fn)
            {
                ans = i + 1;
                break;
            }
            if (mx[i + 1] - mn[i] + pre[i] >= fn)
            {
                ans = i + 1;
                break;
            }
        }

        if (mx[0] >= fn)
        {
            cout << tim + 1 << '\n';
            continue;
        }

        cout << tim + ans << '\n';

        // vector<ll> num(n + 1, 0);
        // ll maxinc = maxy - vec[0];
        // num[0] = maxinc;
        // for (int i = 1 ; i < id; i++)
        // {
        //     num[i] = max(maxinc , maxy - vec[i]);
        // }

        // ll ans = id;
        // for(int i = id - 1 ; i > 0 ; i--) {
        //     if(pre[i - 1] + num[i - 1] < fn) break;
        //     ans = i;
        // }
        // cout << tim + ans + 1 << '\n';
    }
    return 0;
}