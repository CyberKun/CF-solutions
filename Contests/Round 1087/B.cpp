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
        vector<ll> ans(n);
        for(int i = n - 1 ; i >= 0 ; i--) {
            ll ct1 = 0 , ct2 = 0;
            for(int j = i + 1 ; j < n ; j++) {
                if(vec[j] > vec[i]) ct1++;
                if(vec[j] < vec[i]) ct2++;
            }
            ans[i] = max(ct1 , ct2);
        }
        for(int i = 0 ; i < n ; i++) cout << ans[i] << ' ';
        cout << '\n';
    }
    return 0;
}
