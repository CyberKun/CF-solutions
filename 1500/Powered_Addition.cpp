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
        vector<ll> vec(n);
        for (int i = 0; i < n; i++) cin >> vec[i];
        ll ans = 0;
        for (int i = 1; i < n; i++) {
            if (vec[i] < vec[i-1]) {
                ans = max(ans , (ll)(vec[i-1] - vec[i]));
                vec[i] = vec[i-1];
            }
        }
        if(ans == 0) {
            cout << 0 << '\n';
            continue;
        }

        ll num = 0;
        for(int i = 0 ; i <= 31 ; i++) {
            num += (1<<i);
            if(num >= ans) {
                cout << i + 1 << '\n';
                break;
            }
        }
    }
    return 0;
}
