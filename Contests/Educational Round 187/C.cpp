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
        ll s , m;
        cin >> s >> m;

        vector<ll> all;
        for (int i = 61; i >= 0; i--) {
            if ((m >> i) & 1) {
                all.push_back(1LL << i);
            }
        }

        if(s % m == 0) {
            cout << s / m << '\n';
            continue;
        }

        if (s % (*min_element(all.begin() , all.end())) != 0) {
            cout << -1 << "\n";
           continue;
        }

        ll low = 1 , high = s , ans = s;
        while (low <= high) {
            ll mid = low + (high - low) / 2;
            ll start = s;
            for(int i = 0 ; i < all.size() ; i++) {
                ll maxy = start / all[i];
                start -= min(maxy , mid) * all[i];
                if(start == 0) break;
            }
            if(start == 0) {
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }

        cout << ans << '\n';

    }
    return 0;
}
