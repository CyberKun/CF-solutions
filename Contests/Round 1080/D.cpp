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

    ll t;
    cin >> t;

    while (t--) {
        ll n;
        cin >> n;
        vector<ll> vec(n) , ans(n , 0);
        for (int i = 0; i < n; i++) cin >> vec[i];
        ll sumo = accumulate(vec.begin() , vec.end() , 0ll);
        for(int i = 2 ; i < n ; i++) ans[i - 1] = (vec[i] - 2*vec[i - 1] + vec[i - 2]) / 2;
        ll nm = 0;
        
        for(int i = 1 ; i < n - 1 ; i++) {
            nm += (i)*ans[i];
        }
        ans[n - 1] = (vec[0] - nm) / (n - 1);

        nm = 0;
        for (int i = 1; i < n ; i++)
        {
            nm += (i - 1)*ans[i];
        }
        ans[0] = (vec[1] - nm);

        for(int i = 0 ; i < n ; i++) cout << ans[i] << ' ';
        cout << '\n';
    }
    return 0;
}
