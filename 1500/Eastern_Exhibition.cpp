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
        vector<ll> vec1(n) , vec2(n);
        for (int i = 0; i < n; i++) cin >> vec1[i] >> vec2[i];
        sort(vec1.begin() , vec1.end());
        sort(vec2.begin() , vec2.end());
        if(n % 2) {
            cout << 1 << '\n';
            continue;
        }

        ll a1 = vec1[n/2 - 1] , a2 = vec1[n/2];
        ll b1 = vec2[n/2 - 1] , b2 = vec2[n/2];
        cout << abs(a2 - a1 + 1) * abs(b2 - b1 + 1) << '\n';
    }
    return 0;
}
