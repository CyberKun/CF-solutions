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
        ll n , m , l;
        cin >> n >> m >> l;
        vector<ll> vec(n);
        for (int i = 0; i < n; i++) cin >> vec[i];
        if(m == 1) {
            cout << l - vec[n - 1] << '\n';
            continue;
        }
        ll ans = l - vec[n - 1];
        int i = 2 , j = n - 1;
        while(i <= m && j >= 0) {
            if(j == 0) ans += (vec[j])/i;
            else ans += (((vec[j] - vec[j - 1]) / i));
            i++;
            // if(i > m) i = m; 
            j--;
        }

        // if(i == m) {

        // }

        // if(i > m) {
        //     ll num = 0;
        //     for(int k = j ; k > 0 ; k--) num = max(num , vec[k] - vec[k - 1]);
        //     num = max(num , vec[0] - 1);
        //     ans += num/m;
        // }
        cout << max(1ll , ans) << '\n';
    }
    return 0;
}
