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
        ll n , c , k;
        cin >> n >> c >> k;
        vector<ll> vec(n);
        for (int i = 0; i < n; i++) cin >> vec[i];
        sort(vec.begin() , vec.end());
        for(int i = 0 ; i < n ; i++) {
            if(vec[i] > c) break;
            if(vec[i] + k > c) {
                k -= (c - vec[i]);
                c += c;
            }
            else {
                c += vec[i] + k;
                k = 0;
            }
        }
        cout << c << '\n';
    }
    return 0;
}
