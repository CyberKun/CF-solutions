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
        vector<ll> ans(n , -1);
        ll nm = vec[n/2];
        for(int i = n/2 ; i < n ; i++) ans[i] = nm;
        vector<vector<ll>>vc(n + 1);
        for(int i = 0 ; i < n ; i++) {
            vc[vec[i]].push_back(i);
        }
        for(int i = 1 ; i <= n ; i++) {
            if(vc[i].size()) {
                ll num = vc[i][0] + 1;
                for(int j = 1 ; j < vc[i].size() ; j++) {
                    num = max(num , (ll)(vc[i][j] - vc[i][j-1]));
                }
                num = max(num , (n) - vc[i][vc[i].size() - 1]);
                for(int k = num - 1; k < n && (ans[k] == -1 || ans[k] == nm) ; k++) {
                    if(ans[k] == -1) ans[k] = i;
                    else ans[k] = min((ll)i , ans[k]);
                }
            }
        }
        for(int i = 0 ; i < n ; i++) cout << ans[i] << ' ';
        cout << '\n';
    }
    return 0;
}
