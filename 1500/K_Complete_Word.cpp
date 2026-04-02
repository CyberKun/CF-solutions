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
        ll n , k;
        cin >> n >> k;
        string s;
        cin >> s;
        vector<char> v;
        ll ans = 0;
        for(int i = 0 ; i < k/2 ; i++) {
            for(int j = i ; j + k - 1 - 2*i < n ; j += k) {
                v.push_back(s[j]);
                v.push_back(s[j + k - 1 - 2*i]);
            }
            map<char, ll> fq;
            ll maxy = 0;
            for(int k = 0 ; k < v.size() ; k++) {
                fq[v[k]]++;
                maxy = max(maxy , fq[v[k]]);
            }
            ans += (v.size() - maxy);
            v.clear();
        }
        if(k % 2) {
            map<char,ll> fq;
            ll maxy = 0;
            for(int i = k/2 ; i < n ; i += k) {
                fq[s[i]]++;
                maxy = max(maxy , fq[s[i]]);
            }
            ans += (n/k - maxy);
        }
        cout << ans << '\n';
    }
    return 0;
}
