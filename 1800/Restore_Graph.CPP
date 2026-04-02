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

    ll t = 1;
    // cin >> t;

    while (t--) {
        ll n , k;
        cin >> n >> k;
        vector<pair<ll, ll>> vec(n);
        for (int i = 0; i < n; i++) {
            cin >> vec[i].first;
            vec[i].second = i + 1;
        }
        vector<pair<ll, ll>> num = vec;
        sort(vec.begin(), vec.end());
        queue<ll> q;
        // vector<vector<ll>> edges(n + 1, vector<ll>());
        int j = 0;
        vector<ll>remk(n , k);
        if((vec[0].first == vec[1].first && vec[0].first == 0) || vec[0].first != 0) {
            cout << -1 << '\n';
            return 0;
        }
        vector<pair<ll,ll>>ans;
        for(int i = 1 ; i < n ; i++) {
            while(j < n && remk[j] == 0) j++;
            if (j == n) {
                cout << -1 << '\n';
                return 0;
            }
            if(vec[i].first == vec[j].first) {
                cout << -1 << '\n';
                return 0;
            }
            while(j < n && vec[i].first != vec[j].first + 1) j++;
            if (j == n) {
                cout << -1 << '\n';
                return 0;
            }
            ans.push_back({vec[j].second ,vec[i].second });
            remk[j]--;
            remk[i]--;

        }
        cout << ans.size() << '\n';
        for(int i = 0 ; i < ans.size() ; i++) cout << ans[i].first << ' ' << ans[i].second << '\n';

    }
    return 0;
}
